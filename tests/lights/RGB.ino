//Check if all lights are peoperly connected or not
int red_light_pin= 13;
int green_light_pin = 12;
int blue_light_pin = 11;
void setup() {

  // put your setup code here, to run once:
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("JSM");
digitalWrite(red_light_pin,HIGH);
digitalWrite(blue_light_pin,HIGH);
digitalWrite(green_light_pin,HIGH);

}
