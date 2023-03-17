 // MOTEUR
  int pin1 =7; //DC1
  int pin2 =8; //DC2
  int vit=9;
  char commande=0 ;
  float PWM ;
  // ENCODEUR
const int encoder_a = 2; // Pin 2
const int encoder_b = 3; // Pin 3
long encoder_pulse_counter = 0;
long direction = 1;
void encoderPinChangeA()
  {
    encoder_pulse_counter += 1;
    direction = digitalRead(encoder_a) == digitalRead(encoder_b) ? -1 : 1;
}

void encoderPinChangeB()
{
    encoder_pulse_counter += 1;
    direction = digitalRead(encoder_a) != digitalRead(encoder_b) ? -1 : 1;
}
void setup() {
  Serial.begin(9600);
  pinMode(pin1,OUTPUT);
  pinMode(vit,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(encoder_a, INPUT_PULLUP);
  pinMode(encoder_b, INPUT_PULLUP);
  attachInterrupt(0, encoderPinChangeA, CHANGE);
  attachInterrupt(1, encoderPinChangeB, CHANGE);
}

void loop() {
   
 if(Serial.available()>0){
 
    PWM = Serial.parseInt();
    analogWrite(vit,PWM);
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);   
    long speed = (encoder_pulse_counter/400.00)*60; // encodeur a 400 pulsations par revolution
    //Serial.print("RPM: ");
    Serial.println(direction*speed);
    encoder_pulse_counter = 0; // effacer variable pour recalculer
    delay(100);

     }}
