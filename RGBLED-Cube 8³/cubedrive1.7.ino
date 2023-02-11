/* note 1.7 2023/2/11 By Yihuan
digital 2~13  PWM to RGB
digital 22~37 digital to GND
*/


int rgb_color_set[16][12]  = 
                 {{255,0,0,0,0,0,0,0,0,255,0},
                  {255,0,0,0,0,0,0,0,0,255,0},
                  {255,0,0,0,0,0,0,0,0,255,0},
                  {255,0,0,0,0,0,0,0,0,255,0},
                  {255,0,0,0,0,0,0,0,0,255,0},
                  {255,0,0,0,0,0,0,0,0,255,0},
                  {255,0,0,0,0,0,0,0,0,255,0},
                  {255,0,0,0,0,0,0,0,0,255,0},
                  {255,0,0,0,0,0,0,0,0,255,0},
                  {255,0,0,0,0,0,0,0,0,0,0},
                  {255,0,0,0,0,0,0,0,0,0,0},
                  {255,0,0,0,0,0,0,0,0,0,0},
                  {255,0,0,0,0,0,0,0,0,0,0},
                  {255,0,0,0,0,0,0,0,0,0,0},
                  {255,0,0,0,0,0,0,0,0,0,0},
                  {255,0,0,0,0,0,0,0,0,0,0}};

void setup() {

  for(int i=2;i<14;i++){
    pinMode(i,OUTPUT);
  }
  for(int i=22;i<38;i++){
    pinMode(i,OUTPUT);
  }

  led_all_gnd_control(1);
  Serial.begin(2000000);
}

unsigned int timer=0;
int open_now = 0;

void loop() {
  

  led_one_gnd_control(timer%16);
  led_color_show(timer%16);
  timer++;
  led_color_clear();
  serial_read();
  
}


//control function 1.1 2023/2/9

void led_all_gnd_control(int set){
  for(int i=22;i<38;i++){
    digitalWrite(i,set);
  }
}

void led_one_gnd_control(int list){
  for(int i=22;i<38;i++){
    //Serial.println(list == i-22);
    if(list == i-22){
      digitalWrite(i,0);
      //open_now = i;
    }else{
      digitalWrite(i,1);
    }
    
  }
}

void led_color_clear(){
  for(int i=2;i<14;i++){
    analogWrite(i,0);
  }
}

void led_color_show(int list){
    for(int i=2;i<14;i++){
      analogWrite(i,rgb_color_set[list][i-2]);
    }
}

void rgb_list_write(){
  
}
//contorl brige 1.0 2023 2/10


String serial_input;

void serial_read(){
  if (Serial.available()) {
    serial_input = Serial.readStringUntil('\n');
    
    int save_list = serial_input.substring(0,2).toInt();
    int save_color[12];
    //Serial.println(save_list);
    for(int i=0;i<12;i++){
      rgb_color_set[save_list][i] = serial_input.substring(i*3+2,3).toInt();

      //Serial.println(serial_input.substring(i*3+2,i*3+2+3).toInt());
    }
    print_arr(rgb_color_set[0]);
    //rgb_color_set[save_list] = save_color;
    
  }
  
}

void print_arr(int* array){
    Serial.print("[");
    Serial.print(array[0]);
    Serial.print("],[");
    for (int i = 1; i <= array[0]-1; ++i){
        Serial.print(array[i]);
        Serial.print(",");
    }Serial.print(array[array[0]]);
    Serial.print("]");
}