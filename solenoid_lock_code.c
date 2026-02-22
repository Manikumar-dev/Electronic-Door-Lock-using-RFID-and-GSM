
#include <stdio.h>
#include <string.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial (8, 9); //  RX, TX
char ch;
int led = 13;
int relay = 10;
int count = 0;
char *c1="160052EE72D8"; 
void setup()
{  
  mySerial.begin(9600);
  Serial.begin(9600);  
  pinMode(led,OUTPUT);
  pinMode(relay,OUTPUT);    
  digitalWrite(led,1);
  delay(700);
  digitalWrite(led,0);
  delay(700);  
  digitalWrite(led,1);
  delay(700);
  digitalWrite(led,0);
}
void loop()
{
  String ddata = "";  
  int flag = 0;   
  while(1)
  {        
        count = 0; 
        delay(160);
        if (Serial.available() > 0)
        {  
          i = 0;
          while(1)
          {
             char inChar = Serial.read();
               if(strcmp(inChar, c1) == 0)
               {
                    digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level) 
                    digitalWrite(relay, HIGH);   // turn the LED on (HIGH is the voltage level) 
                     mySerial.println("AT+CMGF=1");
                     delay(200);
                     mySerial.println("AT+CMGS=\"+919100326021\"");
                     delay(300);
                     mySerial.println("*** Authorised ***");
                     delay(200);
                    delay(3000);                
                    digitalWrite(relay, LOW);   // turn the LED on (HIGH is the voltage level) 
                    break;  
               }
               else
               {     
                    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)                   
                     mySerial.println("AT+CMGF=1");
                     delay(200);
                     mySerial.println("AT+CMGS=\"+919100326021\"");
                     delay(300);
                     mySerial.println("***ALERT*** Un-Authorised ");
                     delay(200);
                    digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level) 
                    break;  
                
               }
             }
          }
        }
  }
}
