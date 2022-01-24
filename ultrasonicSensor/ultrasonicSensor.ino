long trig=26; // 8;
long echo=18; // 9;
long Zeit;
long Strecke;

void setup() {
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    Serial.begin(9600);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  Zeit = pulseIn(echo,HIGH);
  Strecke=Zeit*0.017;
  
  Serial.print("Entfernung in cm:   ");
  Serial.println(Strecke);
  
    
}

    
