#define len_run 1;
const int sensorPIN=13; int loopCount=0;
int prevSensor=100; int sensor; int prevOnTime=0;   int nowTime;
int elapsedOnTime;  int MIN_ON_TIME = 100;

void hyoji(float sokudo,float kyori,int zikan,int ct)
{
  Serial.print(sokudo);
  Serial.print("km/h "); 
  Serial.print("total:");
  if(kyori<1000000){
    Serial.print(kyori);
    Serial.print("m ");
  }
  else{
    Serial.print(kyori);
    Serial.print("km ");
  }
  Serial.print("elapsedTime:");
  Serial.print(zikan);
  Serial.print("msec ");

   Serial.print("count：");
   Serial.print(ct);
   Serial.print("\n");
}

void setup()
{
  pinMode(sensorPIN, INPUT);    
  Serial.begin( 9600 );
}

void loop() {
  sensor = digitalRead(sensorPIN);
  if(prevSensor != sensor){
    if(sensor){
      nowTime = millis();
      elapsedOnTime = nowTime-prevOnTime;
      if(elapsedOnTime > MIN_ON_TIME){
        loopCount++;
        float totalkm = loopCount * len_run;
        float kmph = 5050.0f/elapsedOnTime;
        hyoji(kmph,totalkm,elapsedOnTime,loopCount);
        prevOnTime = nowTime;               
      }
    }prevSensor = sensor;
  }
}
