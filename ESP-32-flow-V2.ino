#define FlowPin1 18
#define FlowPin2 19

float pulseCount1 ;
float pulseCount2 ;


// read pulses from a sensor ( hall effect based water flow sensor )

  bool stat1_ ;
  bool stat2_ ;

  static bool aa_1 = true, bb_1 = true;
  static bool aa_2 = true, bb_2 = true;
  static uint32_t currentMillis = 0, previousMillis = 0;
  
void setup()
{
  Serial.begin(115200);
  
}

void loop()
{

  stat1_ = digitalRead(FlowPin1);   // make sure you pull this up
  stat2_ = digitalRead(FlowPin2);   // make sure you pull this up
  if ( stat1_ && aa_1 ) {  // high , detecting RISE
    aa_1 = false;
    bb_1 = true;
    pulseCount1++;   // increment counter
  }
  if ( stat2_ && aa_2 ) {  // high , detecting RISE
    aa_2 = false;
    bb_2 = true;
    pulseCount2++;   // increment counter
  }

  if ( ! stat1_ && bb_1 ) {  // low
    bb_1 = false;
    aa_1 = true;
  }
  if ( ! stat2_ && bb_2 ) {  // low
    bb_2 = false;
    aa_2 = true;
  }




// 開始計算每秒鐘的流速


  currentMillis = millis();

 if ( currentMillis - previousMillis >= 1000 )  {  // interval is 1 sec
     previousMillis = currentMillis;



 
  Serial.print("Pin1 p/s:");
  Serial.print(pulseCount1);
  Serial.print(" Pin2 p/s:");
  Serial.println(pulseCount2);
  
  pulseCount1 = 0;  // reset the counter
  pulseCount2 = 0;  // reset the counter
}




}
