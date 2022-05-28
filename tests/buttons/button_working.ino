//check if all buttons are working or not.
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
}
int levers[]={2,3,4,5,6,7,8};

void loop() {
  for(int i=0;i<=6;i++){
   // Serial.print(digitalRead(levers[i]));
if(digitalRead(levers[i])==HIGH){
    Serial.print(i);
    }
}
    delay(1000);
    Serial.print("\n");

}
