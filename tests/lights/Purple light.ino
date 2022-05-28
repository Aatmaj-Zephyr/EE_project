int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;
void setup() {

  // put your setup code here, to run once:
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
int i=0;
void loop() {
  if(i==255){
    i=0;
  }
  else {
    if(i==0){
    i=255;
  }
  }
  // put your main code here, to run repeatedly:
Serial.println("JSM");
analogWrite(red_light_pin,i);
analogWrite(green_light_pin,0);
analogWrite(blue_light_pin,255-i);

}
