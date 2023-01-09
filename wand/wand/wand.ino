// https://github.com/jrowberg/i2cdevlib
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps612.h"
#include "Wire.h"

MPU6050 mpu;

#define OUTPUT_READABLE_YAWPITCHROLL

#define INTERRUPT_PIN 27 
#define button_pin 33 

#define Long 0.4
#define sl 32
#define point_size 3
#define debounce 60

bool demo_picture[sl][sl] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
{0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
{0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
{0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
{0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

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

int button_time = millis();
//int Delay = 100;
bool button_state;
bool button_press = true;
float angle[3] = {0,0,0};
float value[3] = {0,0,0};
float x = 0;
float y = 0;
float x_max,x_min,x_mid,x_gap,x_size,y_max,y_min,y_mid,y_gap,y_size;
int cX,cY,num_start,num_end;
int coordinate[600][2];
int num = 0;
int same_point = 0;
float score = 0;

void setup() {
  for (int i=0;i < 600;i++){
    coordinate[i][0] = 0;
    coordinate[i][1] = 0;
  }
  x_max = -sl;
  x_min = sl;
  y_max = x_max;
  y_min = x_min;
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
    if (!button_state){
      if (button_press){
        button_time = millis();
        button_press = false;
        angle[0] = ypr[0];
        angle[1] = ypr[1];
        angle[2] = ypr[2];
      }
      if (angle[0] > 0 && ypr[0] < 0 && ((3.14-angle[0])+(ypr[0]+3.14)) < 3.14)
        value[0] = ((3.14-angle[0])+(ypr[0]+3.14));
      else if (angle[0] < 0 && ypr[0] > 0 && ((angle[0]+3.14)+(3.14-ypr[0])) < 3.14)
        value[0] = ((angle[0]+3.14)+(3.14-ypr[0]))*-1;
      else
        value[0] = (ypr[0]-angle[0]);
      if (angle[1] > 0 && ypr[1] < 0 && ((3.14-angle[1])+(ypr[1]+3.14)) < 3.14)
        value[1] = ((3.14-angle[1])+(ypr[1]+3.14));
      else if (angle[1] < 0 && ypr[1] > 0 && ((angle[1]+3.14)+(3.14-ypr[1])) < 3.14)
        value[1] = ((angle[1]+3.14)+(3.14-ypr[1]))*-1;
      else
        value[1] = (ypr[1]-angle[1]);
      if (angle[2] > 0 && ypr[2] < 0 && ((3.14-angle[2])+(ypr[2]+3.14)) < 3.14)
        value[2] = ((3.14-angle[2])+(ypr[2]+3.14));
      else if (angle[2] < 0 && ypr[2] > 0 && ((angle[2]+3.14)+(3.14-ypr[2])) < 3.14)
        value[2] = ((angle[2]+3.14)+(3.14-ypr[2]))*-1;
      else
        value[2] = (ypr[2]-angle[2]);
  
      if (value[0] > 1)
        x = Long*((asin(value[0]-1)*180/M_PI)+180/M_PI);
      else if (value[0] < -1)
        x = Long*((asin(value[0]+1)*180/M_PI)-180/M_PI);
  //    need a out of range warning(bigger or smaller than 2 or more)
      else
        x = Long*((asin(value[0])*180/M_PI));
      if (value[1] > 1)
        y = Long*((asin(value[1]-1)*180/M_PI)+180/M_PI);
      else if (value[0] < -1)
        y = Long*((asin(value[1]+1)*180/M_PI)-180/M_PI);
      else
        y = Long*((asin(value[1])*180/M_PI));
        
      if (millis()-button_time >= debounce){
        Serial.println(millis()-button_time);
        coordinate[num][0] = x;
        coordinate[num][1] = y;
        Serial.print(coordinate[num][0]);
        Serial.print("\t");
        Serial.println(coordinate[num][1]);
        num++;
        if (x > x_max)
            x_max = x;
        else if (x < x_min)
            x_min = x;
        else{
            x_max = x_max;
            x_min = x_min;
        }    
        if (y > y_max)
            y_max = y;
        else if (y < y_min)
            y_min = y;
        else{
            y_max = y_max;
            y_min = y_min;  
        }
      }        
    }
    else if (button_state){
      if (!button_press){
        button_press = true;
        num = 0;
        bool picture[sl][sl];
        for (int i=0;i<sl;i++){
          for (int k=0;k<sl;k++){
            picture[i][k] = 0;
          }
        }        
        x_mid = (x_max+x_min)/2;
        y_mid = (y_max+y_min)/2;
        x_gap = 0-x_mid;
        y_gap = 0-y_mid;
        x_size = sl/(x_max+x_gap);
        y_size = sl/(y_max+y_gap);
        x_max = -sl;
        x_min = sl;
        y_max = x_max;
        y_min = x_min;
        for (int c=0;c<600;c++){
          if (coordinate[c][0] <= sl && coordinate[c][1] <= sl && coordinate[c][0] >= sl*-1 && coordinate[c][1] >= sl*-1){
            cX = int(((coordinate[c][0]+x_gap))*x_size/2+sl/2-point_size/2);
            cY = int(((coordinate[c][1]+y_gap))*y_size/2+sl/2-point_size/2);
            num_start = (point_size-int(point_size/2+0.5))*-1;
            num_end = int(point_size/2);
            for (int X=num_start;X <= num_end;X++){
              for (int Y=num_start;Y <= num_end;Y++){
                if (X+X < sl && cX+X >= 0){
                  if (cY+Y < sl && cY+Y >= 0){
                    picture[cX+X][cY+Y] = 1;
                  }
                }
              }
            }
          }
        }
        for (int i=0;i < sl;i++){
          Serial.println();
          for (int j=0;j < sl;j++){
            Serial.print(picture[j][i]);
            if (demo_picture[j][i] == picture[j][i] && picture[j][i] == 1){
              same_point += 1;
            }
            picture[j][i] = 0; 
          }
        }
        Serial.println("\n");
        score = 100*(same_point/(sl*sl));
        Serial.println(same_point);
        Serial.println(score);
        Serial.println(sl*sl);
        same_point = 0;
        score = 0;
      }
    }
  }
}
