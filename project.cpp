#include <Adafruit_Fingerprint.h>  
#include <SoftwareSerial.h> 
#include "U8glib.h"            
U8GLIB_SSD1306_128X64 u8g(12, 11, 8, 9, 10);
SoftwareSerial       mySerial(3, 2); 
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int L = 5;
int E = 6;
void setup(){
  Serial.begin(9600);
  Serial.println("fingertest");
  
  // SET PIN AS OUTPUT
  pinMode(L, OUTPUT);
  pinMode(E, OUTPUT);
  

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
  Serial.println("Waiting for valid finger...");
}
void loop(){
u8g.firstPage();  
  do {u8g.setFont(u8g_font_unifont);  
u8g.setPrintPos(30, 20); 
u8g.print("Hold up");
u8g.setPrintPos(20, 40);
u8g.print("your finger");
    // функции отрисовки
  } while( u8g.nextPage() );

  if(finger.getImage()         == FINGERPRINT_OK){
 if(finger.image2Tz()         == FINGERPRINT_OK){
if(finger.fingerFastSearch() == FINGERPRINT_OK){
igitalWrite (E, HIGH); delay(100);
    u8g.firstPage();  
  do {u8g.setFont(u8g_font_unifont);  
u8g.setPrintPos(40, 35); 
u8g.print("Open!"); 
    // функции отрисовки
  } while( u8g.nextPage() ); delay(7000);
  u8g.firstPage();  
  do {u8g.setFont(u8g_font_unifont);  
u8g.setPrintPos(0, 35); 
u8g.print("Close after 3..."); 
    // функции отрисовки
  } while( u8g.nextPage() ); delay(1000);
  u8g.firstPage();  
  do {u8g.setFont(u8g_font_unifont);  
u8g.setPrintPos(0, 35); 
u8g.print("Close after 2...!"); 
    // функции отрисовки
  } while( u8g.nextPage() ); delay(1000);
  u8g.firstPage();  
  do {u8g.setFont(u8g_font_unifont);  
u8g.setPrintPos(0, 35); 
u8g.print("Close after 1..."); 
    // функции отрисовки
  } while( u8g.nextPage() ); delay(1000);
  u8g.firstPage();  
  do {u8g.setFont(u8g_font_unifont);  
u8g.setPrintPos(0, 20); 
u8g.print(""); 
digitalWrite (E, LOW); delay(100);
    // функции отрисовки
  } while( u8g.nextPage() );
    Serial.print("Found ID=");
    Serial.print(finger.fingerID); 
    Serial.print(", with confidence of ");
    Serial.println(finger.confidence); delay(100);
  }}}
  delay(500);                                          
void draw(void) {
  u8g.setFont(u8g_font_unifont); 
  u8g.setPrintPos(0, 20); 
  u8g.print("Hold up");
}
