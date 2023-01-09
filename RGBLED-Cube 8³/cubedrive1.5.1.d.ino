int i=1 , p =1 ;
int color_set[16][12]  = 
                 {{0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255},
                  {0,0,255,0,0,255,0,0,255,0,0,255}};
void setup() {
  // put your setup code here, to run once:
  for(int i=2;i<14;i++){
    pinMode(i,OUTPUT);
  }
  for(int i=22;i<38;i++){
    pinMode(i,OUTPUT);
  }
  
  //Serial.begin(9600);
}

int save = 0;
void loop() {
  // put your main code here, to run repeatedly:
  rgb_show();
  

}
void color_show(int l){
  if(save==1){
    for(int i=2;i<14;i++){
      //analogWrite(i,255);
      analogWrite(i,color_set[l][i-2]);
      //Serial.println(color_set[l][i-2]);
    }
  }else{
    for(int i=2;i<14;i++){
      //analogWrite(i,255);
      analogWrite(i,color_set[l][15-(i-2)]);
      //Serial.println(color_set[l][12-(i-2)]);
    }
  }
  
}
void color_show_clear(){

  for(int i=2;i<14;i++){
    //analogWrite(i,255);
    analogWrite(i,0);
    //Serial.println(color_set[l][i-2]);
    
  }
}
void rgb_close(){
  for(int i=22;i<38;i++){
    digitalWrite(i,1);
    
  }
}
void rgb_show(){
  digitalWrite(22,0);
  color_show(0); 
  //Serial.println(22);
  //rgb_close();
  save = save*-1;
  for(int i=23;i<38;i++){
    //Serial.print(i-1);
    //Serial.print(" 1 ");
    //Serial.print(i);
    //Serial.print(" 0 ");
    
    digitalWrite(i-1,1);
    color_show_clear();
    digitalWrite(i,0);
    
    //delay(200);
    color_show(i-22);

    //rgb_close();
    //Serial.println(i-22);
    
  }
  digitalWrite(37,1);
  color_show_clear();
}
