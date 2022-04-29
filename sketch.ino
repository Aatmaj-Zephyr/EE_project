Docs
sketch.ino
diagram.json
Library Manager

int red_light_pin= 13;
int green_light_pin = 12;
int blue_light_pin = 11;
int counter=0;
//VIBGYORW
int red_val[]={255,0,0,255,0,255,255,255};
int green_val[]={0,0,255,255,255,165,0,255};
int blue_val[]={255,255,255,0,0,0,0,255};
int clock=0;
int Delay=500;
int LED_Burn_time=1000;
int color=0;
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
void loop() {
  if(clock*Delay>=LED_Burn_time){ //next color
      int temp=random(0,8);
      if(temp==color){ //prevent same colors comming twice
            color=(color+1)%8;
      }
      else{
      color=temp;
      }
      RGB_color(red_val[color],green_val[color],blue_val[color]);
      clock=0;
}
for(int i=0;i<=7;i++){
  if(digitalRead(levers[i])==1){
    if(i==color){
      score++;
      Serial.println("+");
    }
    else{
      Serial.print("-");
    }

  }
}
clock++;
delay(Delay);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, 255-red_light_value);
  analogWrite(green_light_pin, 255-green_light_value);
  analogWrite(blue_light_pin, 255-blue_light_value);
}
Simulation
