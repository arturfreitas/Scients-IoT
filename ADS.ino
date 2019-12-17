#define ADS_CLOCK 25
#define ADS_DATA 26
#define ADS_RESET 27

void setup() {
  
  int bits[12]; 
  
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
  bits[0] = digitalRead(ADS_DATA);

  //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bits[1] = digitalRead(ADS_DATA);

    //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bits[2] = digitalRead(ADS_DATA);

    //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bits[3] = digitalRead(ADS_DATA);

    //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bits[4] = digitalRead(ADS_DATA);

    //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bits[5] = digitalRead(ADS_DATA);

    //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bits[6] = digitalRead(ADS_DATA);

    //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bits[7] = digitalRead(ADS_DATA);

    //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bits[8] = digitalRead(ADS_DATA);

    //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bits[9] = digitalRead(ADS_DATA);

    //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bits[10] = digitalRead(ADS_DATA);

    //Setting Reset high
  digitalWrite(ADS_CLOCK,HIGH);
  delay(500);
  //Setting Low
  digitalWrite(ADS_CLOCK,LOW);
  
  delay(50);
  
  //Reading second bit
  bits[11] = digitalRead(ADS_DATA);
  
    
  for(int i = 0; i < 12; i++){
    Serial.print('bit %d:', i+1 );
    Serial.println(bits[i]);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
