int i=1 , p =1 ;
int color_set  = {{0,0,0,0,0,0,0,0,0,0,0,0},
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
                  {0,0,0,0,0,0,0,0,0,0,0,0},;
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  for(int i=2;i<38){
    pinMode(i,OUTPUT);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  
}
void color_show(int l){
  for(int i=2;i<14;i++){
    analogWrite(i,color_set[l][i-2]);
  }
}
void rgb_show(){
  analogWrite(22,0);
  color_show(0);
  for(int i=23;i<38;i++){
    analogWrite(i-1,1);
    analogWrite(i-1,0);
    color_show(24-i);
  }
}
void red(){
  analogWrite(2,0);
  analogWrite(3,0);
  analogWrite(4,255);
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(7,255);
  analogWrite(8,0);
  analogWrite(9,0);
  analogWrite(10,255);
  analogWrite(11,0);
  analogWrite(12,0);
  analogWrite(13,255);
}void blue(){
  analogWrite(2,0);
  analogWrite(3,255);
  analogWrite(4,0);
  analogWrite(5,0);
  analogWrite(6,255);
  analogWrite(7,0);
  analogWrite(8,0);
  analogWrite(9,255);
  analogWrite(10,0);
  analogWrite(11,0);
  analogWrite(12,255);
  analogWrite(13,0);
}void green(){
  analogWrite(2,255);
  analogWrite(3,0);
  analogWrite(4,0);
  analogWrite(5,255);
  analogWrite(6,0);
  analogWrite(7,0);
  analogWrite(8,255);
  analogWrite(9,0);
  analogWrite(10,0);
  analogWrite(11,255);
  analogWrite(12,0);
  analogWrite(13,0);
}

void l1(){
  digitalWrite(22,0);
  digitalWrite(23,0);
  digitalWrite(24,0);
  digitalWrite(25,0);
  digitalWrite(26,1);
  digitalWrite(27,1);
  digitalWrite(28,1);
  digitalWrite(29,1);
  digitalWrite(30,1);
  digitalWrite(31,1);
  digitalWrite(32,1);
  digitalWrite(33,1);
  digitalWrite(34,1);
  digitalWrite(35,1);
  digitalWrite(36,1);
  digitalWrite(37,1);
}void l2(){
  digitalWrite(22,1);
  digitalWrite(23,1);
  digitalWrite(24,1);
  digitalWrite(25,1);
  digitalWrite(26,0);
  digitalWrite(27,0);
  digitalWrite(28,0);
  digitalWrite(29,0);
  digitalWrite(30,1);
  digitalWrite(31,1);
  digitalWrite(32,1);
  digitalWrite(33,1);
  digitalWrite(34,1);
  digitalWrite(35,1);
  digitalWrite(36,1);
  digitalWrite(37,1);
}
void l3(){
  digitalWrite(22,1);
  digitalWrite(23,1);
  digitalWrite(24,1);
  digitalWrite(25,1);
  digitalWrite(26,1);
  digitalWrite(27,1);
  digitalWrite(28,1);
  digitalWrite(29,1);
  digitalWrite(30,0);
  digitalWrite(31,0);
  digitalWrite(32,0);
  digitalWrite(33,0);
  digitalWrite(34,1);
  digitalWrite(35,1);
  digitalWrite(36,1);
  digitalWrite(37,1);
}
void l4(){
  digitalWrite(22,1);
  digitalWrite(23,1);
  digitalWrite(24,1);
  digitalWrite(25,1);
  digitalWrite(26,1);
  digitalWrite(27,1);
  digitalWrite(28,1);
  digitalWrite(29,1);
  digitalWrite(30,1);
  digitalWrite(31,1);
  digitalWrite(32,1);
  digitalWrite(33,1);
  digitalWrite(34,0);
  digitalWrite(35,0);
  digitalWrite(36,0);
  digitalWrite(37,0);
}
