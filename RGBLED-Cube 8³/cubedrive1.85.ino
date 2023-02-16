/* note 1.7 2023/2/11 By Yihuan
digital 2~13  PWM to RGB
digital 22~37 digital to GND
*/


int rgb_color_set[16][12]  = 
                 {{0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0}};


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

//rgb_color_set = animation_1[0];

void loop() {
  
  //rgb_list_write(timer%16,0,255);
  led_one_gnd_control(timer%16);
  led_color_show(timer%16);
  if(timer%8000<6000){
    next_room();
  }else{
    next_room2();
  }
  

  timer++;
  led_color_clear();
  serial_read();
  //rgb_list_set(0);
  Serial.println(timer%1000);
  
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

void rgb_control_xy(int x,int y){

}
void rgb_list_write(int x,int y,int i){//can't work
  rgb_color_set[x][y] = i;
}

void rgb_list_reset(){ //can't work
  for(int i=0;i<16;i++){
    for(int j=0;i<12;j++){
      rgb_color_set[i][j] = 0;
    }
  }
}
void rgb_list_set(int k){//can't work
  for(int i=0;i<16;i++){
    for(int j=0;i<12;j++){
      //rgb_color_set[i][j] = animation_1[k][i][j];
    }
  }
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
      rgb_color_set[save_list][i] = serial_input.substring(i*3-1+3,i*3+1+2+2).toInt();
      //Serial.print(serial_input.substring(i*3-1+3,i*3+1+2+2));
     // Serial.print(" ");
      //Serial.println(rgb_color_set[0][i]);
  
      //Serial.println(serial_input.substring(i*3+2,i*3+2+3).toInt());
    }
    //print_arr(rgb_color_set[0]);
    //rgb_color_set[save_list] = save_color;
    
  }
  
}

///////
int red_led_light = 0;
int blue_led_light = 255;
unsigned room_th = 0;
int circle_x[8] = {1,1,6,11,16,16,11,6};
int circle_y[8] = {3,6,9,9,6,3,0,0};
unsigned int clock =0;
void next_room(){
  clock++;
  
  if(clock%200==0){
    //Serial.println(blue_led_light);
    if(room_th == 0){
     // rgb_color_set[circle_x[7]-1][circle_y[7]] = 0;
     // rgb_color_set[circle_x[7]-1][circle_y[7]] = 0;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]] = 255;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]] = 255;
     // rgb_color_set[circle_x[7]-1][circle_y[7]+1] = 0;
      //rgb_color_set[circle_x[7]-1][circle_y[7]+1] = 0;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]+1] = 255;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]+1] = 255;
      room_th++;
    }else{
     // rgb_color_set[circle_x[room_th-1]-1][circle_y[room_th-1]] = 0;
      //rgb_color_set[circle_x[room_th-1]-1][circle_y[room_th-1]] = 0;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]] = 255;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]] = 255;
      //rgb_color_set[circle_x[room_th-1]-1][circle_y[room_th-1]+1] = 0;
      //rgb_color_set[circle_x[room_th-1]-1][circle_y[room_th-1]+1] = 0;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]+1] = 255;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]+1] = 255;
      room_th++;
    }
    if(room_th>=8){
      room_th =0;
    }/*
    if(blue_led_light<10){
      blue_led_light = 255;
    }else{
      blue_led_light = blue_led_light-5;
    }
    if(red_led_light>245){
      red_led_light = 0;
    }else{
      red_led_light =red_led_light+5;
    }*/
    
    
  }
  
  
}

void next_room2(){
  clock++;
  
  if(clock%200==0){
    //Serial.println(blue_led_light);
    if(room_th == 0){
     rgb_color_set[circle_x[7]-1][circle_y[7]] = 0;
     rgb_color_set[circle_x[7]-1][circle_y[7]] = 0;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]] = 255;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]] = 255;
     rgb_color_set[circle_x[7]-1][circle_y[7]+1] = 0;
      rgb_color_set[circle_x[7]-1][circle_y[7]+1] = 0;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]+1] = 255;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]+1] = 255;
      room_th++;
    }else{
    rgb_color_set[circle_x[room_th-1]-1][circle_y[room_th-1]] = 0;
   rgb_color_set[circle_x[room_th-1]-1][circle_y[room_th-1]] = 0;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]] = 255;
  rgb_color_set[circle_x[room_th-1]-1][circle_y[room_th-1]+1] = 0;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]+1] = 255;
      rgb_color_set[circle_x[room_th]-1][circle_y[room_th]+1] = 255;
      room_th++;
    }
    if(room_th>=8){
      room_th =0;
    }/*
    if(blue_led_light<10){
      blue_led_light = 255;
    }else{
      blue_led_light = blue_led_light-5;
    }
    if(red_led_light>245){
      red_led_light = 0;
    }else{
      red_led_light =red_led_light+5;
    }*/
    
    
  }
  
  
}
                
