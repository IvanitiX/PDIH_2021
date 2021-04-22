int val;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7,INPUT);
}

void loop()
{
  val = digitalRead(7);
  if(val == HIGH){
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
  else{
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
  
}
