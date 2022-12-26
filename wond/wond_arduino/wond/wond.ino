// https://github.com/jrowberg/i2cdevlib
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps612.h"
#include "Wire.h"

MPU6050 mpu;

#define OUTPUT_READABLE_YAWPITCHROLL

#define INTERRUPT_PIN 27 
#define button_pin 33 

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 gy;         // [x, y, z]            gyro sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

// ===               INTERRUPT DETECTION ROUTINE                ===

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
  mpuInterrupt = true;
}

int time1 = millis();
int time3 = millis();
int Delay = 100;
bool button_state;
bool button_press = true;
float angle[3] = {0,0,0};

void setup() {
  Wire.begin();
  Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
  
  Serial.begin(115200);

  mpu.initialize();
  pinMode(INTERRUPT_PIN, INPUT);
  pinMode(button_pin,INPUT);

  devStatus = mpu.dmpInitialize();
  // supply your own gyro offsets here, scaled for min sensitivity
  mpu.setXGyroOffset(51);
  mpu.setYGyroOffset(8);
  mpu.setZGyroOffset(21);
  mpu.setXAccelOffset(1150);
  mpu.setYAccelOffset(-50);
  mpu.setZAccelOffset(1060);
  // make sure it worked (returns 0 if so)
  if (devStatus == 0) {
    // Calibration Time: generate offsets and calibrate our MPU6050
    mpu.CalibrateAccel(6);
    mpu.CalibrateGyro(6);
    mpu.PrintActiveOffsets();
    mpu.setDMPEnabled(true);
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();
    dmpReady = true;
    packetSize = mpu.dmpGetFIFOPacketSize();
  } else {
    Serial.print(F("DMP Initialization failed (code "));
    Serial.print(devStatus);
    Serial.println(F(")"));
  }
}

void loop() {
  button_state = digitalRead(button_pin);
  if (!dmpReady) return;
  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    int time2 = millis();
    int timed1 = time2 - time1;
    if (!button_state){
      if (button_press){
        button_press = false;
        angle[0] = ypr[0];
        angle[1] = ypr[1];
        angle[2] = ypr[2];
      }
      if (timed1 >= Delay){
        Serial.print("ypr\t");
        if (angle[0] > 0 && ypr[0] < 0 && ((3.14-angle[0])+(ypr[0]+3.14)) < 3.14)
          Serial.print(((3.14-angle[0])+(ypr[0]+3.14))*180/M_PI);
        else if (angle[0] < 0 && ypr[0] > 0 && ((angle[0]+3.14)+(3.14-ypr[0])) < 3.14)
          Serial.print(((angle[0]+3.14)+(3.14-ypr[0]))*-1*180/M_PI);
        else    Serial.print((ypr[0]-angle[0])*180/M_PI);
        Serial.print("\t");
        if (angle[1] > 0 && ypr[1] < 0 && ((3.14-angle[1])+(ypr[1]+3.14)) < 3.14)
          Serial.print(((3.14-angle[1])+(ypr[1]+3.14))*180/M_PI);
        else if (angle[1] < 0 && ypr[1] > 0 && ((angle[1]+3.14)+(3.14-ypr[1])) < 3.14)
          Serial.print(((angle[1]+3.14)+(3.14-ypr[1]))*-1*180/M_PI);
        else    Serial.print((ypr[1]-angle[1])*180/M_PI);
        Serial.print("\t");
        if (angle[2] > 0 && ypr[2] < 0 && ((3.14-angle[2])+(ypr[2]+3.14)) < 3.14)
          Serial.print(((3.14-angle[2])+(ypr[2]+3.14))*180/M_PI);
        else if (angle[2] < 0 && ypr[2] > 0 && ((angle[2]+3.14)+(3.14-ypr[2])) < 3.14)
          Serial.print(((angle[2]+3.14)+(3.14-ypr[2]))*-1*180/M_PI);
        else    Serial.print((ypr[2]-angle[2])*180/M_PI);
        Serial.print("\t");
        Serial.print("p");
        time1 = millis();
        Serial.println();
      }  
    }
    else if (button_state){
      if (!button_press)
        button_press = true;
      int time4 = millis();
      int timed2 = time4 - time3;
      if (timed2 >= Delay){
        Serial.print("ypr");
        Serial.print("\t");
        Serial.print("0.00");
        Serial.print("\t");
        Serial.print("0.00");
        Serial.print("\t");
        Serial.print("0.00");
        Serial.print("\t");
        Serial.print("s");
        Serial.println();
        time3 = time4;
      }
    }
  }
}
