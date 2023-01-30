
#include<MapleFreeRTOS900.h>
#define LED_green PB0
#define LED_yellow PB1
#define LED_red PB2
#define Switch PC0
#define Analog PA0
void vTaskfunction1(void * pvParameter);
void vTaskfunction2(void * pvParameter);
void vTaskfunction3(void * pvParameter);



int Time_green=2000;
  int Time_yellow=500;
  int Time_red=3000;
int AnalogVal=analogRead(PA0);

void setup() {
pinMode(LED_green,OUTPUT);
pinMode(LED_yellow,OUTPUT);
pinMode(LED_red,OUTPUT);
pinMode(Analog,INPUT_ANALOG);
pinMode(Switch,INPUT_PULLUP);
Serial.begin(115200);


xTaskCreate(vTaskfunction1,"task 1",100,NULL,1,NULL);
xTaskCreate(vTaskfunction2,"Task 2",100,NULL,1,NULL);
xTaskCreate(vTaskfunction3,"Task 3",100,NULL,1,NULL);
vTaskStartScheduler();
  
  

}



void vTaskfunction1(void * pvParameter)
{
  int Counter=0;
  for(;;)
  {
    Serial.println(Counter);
    vTaskDelay(750); 
    if(digitalRead(Switch)==LOW)
  {
    Counter++;
    Serial.println(Counter);
  }
  }
  
}

void vTaskfunction2(void * pvParameter)
{
  for(;;){
 
  
digitalWrite(LED_green,LOW);
  delay(Time_green);
  digitalWrite(LED_green,HIGH);
  digitalWrite(LED_yellow,LOW);
  delay(Time_yellow);
  digitalWrite(LED_yellow,HIGH);
  digitalWrite(LED_red,LOW);
  delay(Time_red);
  digitalWrite(LED_yellow,LOW);
  delay(Time_yellow);
  digitalWrite(LED_yellow,HIGH);
  digitalWrite(LED_red,HIGH);
  
}
}
void vTaskfunction3(void * pvParameter)
{
  
 for(;;)
 {
  
  int AnalogVal= analogRead(PA0);
  if(AnalogVal< 1024)
  {
    Time_green=2000;
    Time_yellow=500;
    Time_red=3000;
  }
  if(1024<=AnalogVal<2048 )
  {
    Time_green=3000;
    Time_yellow=500;
    Time_red=4000;
  }
  if(2048<=AnalogVal<3050 )
  {
    Time_green=4000;
    Time_yellow=500;
    Time_red=5000;

  }

  if(3050<=AnalogVal)
  {
    Time_green=5000;
    Time_yellow=500;
    Time_red=6000;
  }
  Serial.print("Analog = ");
  Serial.println(AnalogVal);
  vTaskDelay(1000);
  }
}



void loop() {
  // put your main code here, to run repeatedly:

}
