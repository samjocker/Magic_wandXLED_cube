#include <stdlib.h>
#include <time.h>

void setup() {
  for(int i=2;i<54;i++){
     pinMode(i,OUTPUT);
  }
  srand( time(NULL) );
}


void led_pwm(int r,int g,int b,int pin){
  int change[8] = {1,2,4,8,16,32,64,128};
  int count=0;
  for(int t=0;t<256;t++){
    if(t == change[int(count)]){
      digitalWrite(pin+5,r%2);
      digitalWrite(pin+16+5,g%2);
      digitalWrite(pin+32+5,b%2);
      count++;
      r=r/2;
      g=g/2;
      b=b/2;
    }
  }
}
int l[8] = {1,2,7,11,14,13,12,4};
void loop() {

  //all led off
  for(int i=1;i<49;i++){
     digitalWrite(i+6,1);
     digitalWrite(i+16+5,1);
     digitalWrite(i+32+5,1);
  }
   
   for(int i;i<256;i++){
      led_pwm(i,i,i,0);
   }
}
