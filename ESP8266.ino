void setup() {
  // put your setup code here, to run once:
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  pinMode(D3,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D3,HIGH);
  delay(1000);
  digitalWrite(D3,LOW);
  delay(1000);  
  }
 

