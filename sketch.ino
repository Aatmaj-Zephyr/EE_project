int red_light_pin= 13;
int green_light_pin = 12;
int blue_light_pin = 11;
int counter=0;
//VIBGYORW
int red_val[]={255,0,0,255,0,255,255,255};
int green_val[]={0,0,255,255,255,165,0,255};
int blue_val[]={255,255,255,0,0,0,0,255};
int clock=0;
int Delay=500; //clockspeed
int LED_Burn_time=1000;
int color[3];
int levers[]={8,7,4,2,A0,A1,A2,A3};
int score=0;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);




}
int three=-1; //Three can be 0,1,2
void loop() {
  three++;
  if(three==3){
    beep();
    score=Read();
    Serial.println(score);
    three=0;
  }
  blink();
}
void blink(){
int temp=random(0,8);
      color[three]=temp;
      
      RGB_color(red_val[color[three]],green_val[color[three]],blue_val[color[three]]);
      clock=0;
      delay(LED_Burn_time);
      RGB_color(0,0,0);//turn led off
      delay(LED_Burn_time);
}
void beep(){ //beep the buxxer
  digitalWrite(6, LOW);//6 is negative pin
  delay(500); //wait for 0.5 sec before turning buzzer off.
  digitalWrite(6, HIGH);
}
int Read(){
  int small_score=0;
  int chance=0;//to check if three buttons are pressed or not.

  while(true){ //read the input
  for(int i=0;i<=7;i++){
  if(digitalRead(levers[i])==1){
    
    chance++; //if button is pressed one chance is taken.
    
    if(i==color[chance]){
      small_score++;
      Serial.println("+");
    }
    else{
      Serial.print("-");
    }
    if(3-chance<=0){ //if chances are over.
      return small_score;
    }
    while(digitalRead(levers[i])==1){
      delay(1);
      //pause till it is removed.
    }
  }
  }
}
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, 255-red_light_value);
  analogWrite(green_light_pin, 255-green_light_value);
  analogWrite(blue_light_pin, 255-blue_light_value);
}
