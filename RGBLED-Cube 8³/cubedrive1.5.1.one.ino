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
  for(int i=2;i<14;i++){
    pinMode(i,OUTPUT);
  }
  for(int i=22;i<38;i++){
    pinMode(i,OUTPUT);
  }
}
int save = 0;
void loop() {
  rgb_show();
}
void color_show(int l){
    for(int i=2;i<14;i++){
      analogWrite(i,color_set[l][i-2]);
    }
}
void color_show_clear(){
  for(int i=2;i<14;i++){
    analogWrite(i,0);
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
  for(int i=23;i<38;i++){
    digitalWrite(i-1,1);
    color_show_clear();
    digitalWrite(i,0);
    color_show(i-22); 
  }
  digitalWrite(37,1);
  color_show_clear();
}
