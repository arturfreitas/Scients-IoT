#define ADS_CLOCK 25
#define ADS_DATA 26
#define ADS_RESET 27

void setup() {
  
  int bit1,bit2; 
  
  //put your setup code here, to run once:
  pinMode(ADS_CLOCK,OUTPUT);
  pinMode(ADS_DATA,INPUT);
  pinMode(ADS_RESET,OUTPUT);

  //Setting Reset to Low
  digitalWrite(ADS_RESET,HIGH);
  delay(50);
  digitalWrite(ADS_RESET,LOW);

  //Sending first pulse
  digitalWrite(ADS_CLOCK,LOW);
  delay(500);
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  
  //Sending second pulse
  digitalWrite(ADS_CLOCK,LOW);
  delay(500);
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  
  //Setting Reset low
  digitalWrite(ADS_CLOCK,LOW);
  delay(50);

  //Reading first bit
  bit1 = digitalRead(ADS_DATA);

  //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bit2 = digitalRead(ADS_DATA);
    
  Serial.print('bit 1: ' );
  Serial.println(bit1);

  Serial.print('bit 2: ');
  Serial.println(bit2); 
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
