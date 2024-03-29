
int red_light_pin= 11; //pin for RED light LED in RGB
int green_light_pin = 10; //pin for GREEN light LED in RGB
int blue_light_pin = 9; //pin for BLUE light LED in RGB

int counter=0;

//VIBGYOR RGB values
int red_val[]=   {255,0,  0,  255,0,  255,255};
int green_val[]= {0,  0,  255,255,255,165,0};
int blue_val[]=  {255,255,255,0,  0,  0,  0};

int clock=0; //clock of the program
int Delay=50; //delay in between two phases
int LED_Burn_time=1000; //time which LED burns

int color=0;
int levers[]={2,13,4,5,6,7,8}; //push buttons

int score=0;

void setup() {
  Serial.begin(9600);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(2, INPUT);
  pinMode(13, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(12, INPUT);
  pinMode(A5,INPUT);
  pinMode(3,OUTPUT);
 
 


}
void loop() {
  LED_Burn_time=abs(5*(analogRead(A5)+50));//convert potentiometer into delay time
  analogWrite(3,score);//score indicator brightness
 //digitalWrite(3,HIGH);
      Serial.println(score);

  if(clock*Delay>=LED_Burn_time){ //next color

      Serial.print(score);
      int temp=random(0,7);
      if(temp==color){ //prevent same colors comming twice
            color=(color+1)%7;
      }
      else{
      color=temp;
      }
      RGB_color(red_val[color],green_val[color],blue_val[color]); //set color value
      clock=0;
}
for(int i=0;i<=6;i++){
  if(digitalRead(levers[i])==1){
    if(i==color){
      score++;
      Serial.println("+");
      clock=0; //if correct prevent double tapping
     
    }
    else{
      Serial.print("-");
      if(score>0){
      score--;
      }
    }
 while(digitalRead(levers[i])==1){
   Serial.print("pressed....");
   Serial.print(i)
        //while button is still pressed do nothing.
        // this is to prevent multiple taps (long press)
        ;
      }
  }
}
clock++;
delay(Delay);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin,green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
 }
