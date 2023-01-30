#include <UTFT.h>
#include <Touch.h>
#include <MapleFreeRTOS900.h>

void vTaskfunction1(void * pvParameter);
UTFT myGLCD(ILI9325D_16, PD11, PD5, PD7, PC1);
Touch ttouch(PA6, PB6, PA5, PB7, PA7);



int Time_green = 2000;
int Time_yellow = 500;
int Time_red = 3000;



int limitswitch = PA0;
int state = LOW;
int Value;

void vTaskfunction1(void * pvParameter){ // Ampel auf display
myGLCD.drawRect(30,30,200,220);

myGLCD.drawCircle(45,45,200,220);
myGLCD.drawCircle(50,50,200,220);
myGLCD.drawCircle(55,55,200,220);

}

void vTaskfunction2(void * pvParameter) //Amperl auf dem Board
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
  digitalWrite(LED_red,HIGH);
}


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(limitswitch, INPUT);



xTaskCreate(vTaskfunction1, "task 1", 100, NULL,1,NULL);
xTaskCreate(vTaskfunction2,"Task 2",100,NULL,1,NULL);
vTaskStartScheduler();

}

void loop() {
  // put your main code here, to run repeatedly:
  Value = digitalRead(limitswitch);

  if(Value != state){
    state = Value;
    Serial.println("Sensor value =");
    
    if(state == 0){
      Serial.println("target detected.");
      delay(500);
    } else {
      Serial.println("No target detected");
      delay(500);
    }
  }
}
