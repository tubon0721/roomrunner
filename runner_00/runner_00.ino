//int human=0;
const int sensorPIN=13;
//float time_s=0;
#define len_run 1;
int loopCount=0;
int count=0;
int prevSensor=100;
int sensor;
int prevOnTime=0;;
int MIN_ON_TIME;
//unsigned long 
int nowTime;
//unsigned long 
int elapsedOnTime;
/*int onetime(int etime){
  if(etime>)
}*/


void setup()
{
  pinMode(sensorPIN, INPUT);    
  Serial.begin( 9600 );
}


void loop() {
  sensor = digitalRead(sensorPIN)==1;
  /*if(cnt%10000==0)
    sensor=true;
  else
    sensor=false;
  cnt++;*/
  
  if(prevSensor != sensor){
    /*if(count%2==1)
        MIN_ON_TIME=elapsedOnTime;
    else
        MIN_ON_TIME=1000;*/
    //Serial.print("MIN_ON_TIME：" );
    //Serial.print(MIN_ON_TIME);Serial.print("\n");
    if(sensor){
      nowTime = millis();
      elapsedOnTime = nowTime - prevOnTime;
      
      //if(elapsedOnTime>MIN_ON_TIME){
        loopCount++;
        //float kmph = oneTime(elapsedOnTime)/1000.0f;
        //float kmph = elapsedOnTime/5000.0f;
        //Serial.print(kmph);
        //Serial.print("km/h "); 
  
        float totalkm = loopCount * len_run;
        float kmph = 5050.0f/elapsedOnTime;
        Serial.print(kmph);
        Serial.print("km/h "); 
        Serial.print("total:");
        if(totalkm<1000000){
          Serial.print(totalkm);
          Serial.print("m ");
        }
        else{
          Serial.print(totalkm );
          Serial.print("km ");
        }
        Serial.print("elapsedTime:");
        Serial.print(elapsedOnTime);
        Serial.print("msec ");
        prevOnTime=nowTime;
        
        Serial.print("count：");
        Serial.print(count);
        Serial.print("\n");
        
      //}
      count++;
    }
    //else
     // Serial.println("but");
  }
  prevSensor = sensor;
}
