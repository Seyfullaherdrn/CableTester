#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <String.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

const int l[]={10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};//Input Pins,
int a=28;   //number of input pins
int c[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,25,26,27,28,29,30};//55 pin read
const int d[]={1,2,3,4,5,6,7,8}; // 8 pin read
const int k[]={A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15}; //Arduino Pin to read
int f[]={0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,29,28,30,27,25,26,1,2,3,4,5,6,7,8};//value to be
int s[]={1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};//array to write the read value
int t[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,3,4,1,2,6,8};
int e[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,3,4,1,2,6,8};

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
static const unsigned char PROGMEM image_data_Saraarray[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xf8, 0x7f, 0xff, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 
    0xff, 0xc0, 0x1f, 0xff, 0xe1, 0xff, 0xc0, 0x00, 0x0f, 0x00, 0x00, 0x01, 0xff, 0x00, 0x7f, 0xff, 
    0xff, 0x80, 0x07, 0xff, 0xc0, 0xff, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x1f, 0xff, 
    0xff, 0x00, 0x07, 0xff, 0xc0, 0xfe, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x1f, 0xff, 
    0xff, 0x00, 0x03, 0xff, 0xc0, 0xfc, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x78, 0x00, 0x0f, 0xff, 
    0xff, 0x00, 0x03, 0xff, 0xc0, 0xfc, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x78, 0x00, 0x0f, 0xff, 
    0xfe, 0x00, 0x03, 0xff, 0xc0, 0xfc, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x07, 0xff, 
    0xfe, 0x07, 0x01, 0xff, 0xc0, 0xf8, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x03, 0xf8, 0x18, 0x07, 0xff, 
    0xfe, 0x07, 0x80, 0xff, 0xc0, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xff, 0xf0, 0x1c, 0x03, 0xff, 
    0xfe, 0x07, 0x80, 0xff, 0xc0, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xff, 0xf0, 0x1c, 0x03, 0xff, 
    0xfe, 0x07, 0x80, 0xff, 0xc0, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xff, 0xe0, 0x1e, 0x01, 0xff, 
    0xfe, 0x07, 0xc0, 0xff, 0xc0, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xff, 0xe0, 0x3e, 0x01, 0xff, 
    0xfe, 0x07, 0xc0, 0x7f, 0xc0, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xff, 0xe0, 0x3e, 0x01, 0xff, 
    0xfe, 0x07, 0xe0, 0x3f, 0xc0, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xff, 0xc0, 0x3f, 0x01, 0xff, 
    0xfe, 0x07, 0xe0, 0x3f, 0xc0, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0x01, 0xff, 0x80, 0x7f, 0x00, 0xff, 
    0xfe, 0x07, 0xe0, 0x3f, 0xc0, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0x01, 0xff, 0x80, 0x7f, 0x80, 0xff, 
    0xfe, 0x07, 0xf0, 0x3f, 0xc0, 0xf0, 0x00, 0x00, 0x07, 0xff, 0x01, 0xff, 0x80, 0xff, 0x80, 0xff, 
    0xfe, 0x07, 0xf0, 0x1f, 0xc0, 0xf0, 0x00, 0x00, 0x07, 0xff, 0x01, 0xff, 0x80, 0xff, 0x80, 0x7f, 
    0xfe, 0x07, 0xf8, 0x1f, 0xc0, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0x01, 0xff, 0x00, 0xff, 0xc0, 0x7f, 
    0xfe, 0x07, 0xf8, 0x1f, 0xc0, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0x01, 0xff, 0x00, 0x00, 0x00, 0x7f, 
    0xfe, 0x07, 0xf8, 0x1f, 0xc0, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x7f, 
    0xfe, 0x07, 0xf8, 0x0f, 0xc0, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x7f, 
    0xfe, 0x07, 0xf8, 0x07, 0xc0, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x3f, 
    0xfe, 0x07, 0xfc, 0x07, 0xc0, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x3f, 
    0xfe, 0x07, 0xfc, 0x07, 0xc0, 0xf0, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xfc, 0x07, 0xff, 0xf0, 0x1f, 
    0xfe, 0x07, 0xfc, 0x07, 0xc0, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0x01, 0xf8, 0x07, 0xff, 0xf8, 0x1f, 
    0xfe, 0x07, 0xfc, 0x03, 0x80, 0xf8, 0x0f, 0xff, 0xff, 0xff, 0x01, 0xf8, 0x07, 0xff, 0xf8, 0x1f, 
    0xfe, 0x07, 0xfe, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0x01, 0xf8, 0x07, 0xff, 0xf8, 0x1f, 
    0xfe, 0x07, 0xff, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x07, 0xff, 0x01, 0xf0, 0x0f, 0xff, 0xfc, 0x0f, 
    0xfe, 0x07, 0xff, 0x00, 0x03, 0xfe, 0x00, 0x00, 0x03, 0xff, 0x01, 0xf0, 0x0f, 0xff, 0xfc, 0x07, 
    0xfe, 0x07, 0xff, 0xc0, 0x07, 0xff, 0x00, 0x00, 0x07, 0xff, 0x01, 0xf0, 0x1f, 0xff, 0xfe, 0x07, 
    0xfe, 0x0f, 0xff, 0xe0, 0x0f, 0xff, 0x80, 0x00, 0x0f, 0xff, 0x81, 0xf8, 0x1f, 0xff, 0xfe, 0x0f, 
    0xff, 0x1f, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xfc, 0x7f, 0xff, 0xff, 0x1f, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};


float Vout = 0.00;
float Vin = 0.00;
float R1 = 100000.00; //  R1 (100K) 
float R2 = 10000.00; //  R2 (10K) 
float val = 0.0;




void

setup() {

Serial.begin(115200);
for(int i = 0; i<=14;i++){
 // int analogInputi=k[i];
pinMode(k[i],INPUT);
}
for(int i = 22; i<=53;i++){
  pinMode(i,OUTPUT);
  }
 if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000); // Pause for 2 seconds
 
  // Clear the buffer.
  display.clearDisplay();
  
  // Draw bitmap on the screen
  display.drawBitmap(0, 0, image_data_Saraarray, 128, 64, 1);
  display.display();
  delay(2000);
 display.clearDisplay();
}


void loop() {
 
  


 for(int i = 22; i<=a;i++){
  
    digitalWrite(i,HIGH);
   
    Serial.print("Input  ");
 display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.setCursor(5, 0);
  display.print(F("INPUT " ));
  display.println(l[i-22], DEC);

    Serial.println(i-12);
    s[i-22]=0;
    t[i-22]=0;
     //delay(500);  
    //analogInput = analogRead(A2);
  //for(int i = 0; i<=15;i++){
    val=analogRead(k[0]);
    delay(500);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
                           //
          //
    //Serial.println(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
     
      display.print("OUTPUT ");
      display.println(c[0]);
      delay(300);
       s[i-22]= c[0];
     
     
         }
      else if(  Vin>=2 &   Vin<=6){
      Serial.println("Output Pin 26 ");
      display.print("OUTPUT ");
      display.println(c[15]);
      delay(300);
     s[i-22]=c[15];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            }
  
   val=analogRead(k[1]);
   delay(500);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
   //Serial.println(Vout); 
   // Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println(" Output 2 ");
      display.print("OUTPUT  ");
      display.println(c[1]);
      delay(200);
         s[i-22]=c[1];
        
         }
      else if(  Vin>=2 &   Vin<=6){
      Serial.println("Output 27 PASS");
     display.print("OUTPUT  ");
      display.println(c[16]);
      delay(200);
     s[i-22]=c[16];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            }

  val=analogRead(k[2]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
  //Serial.println(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println(" Output 3 ");
    display.print("OUTPUT  ");
      display.println(c[2]);
      delay(200);
         s[i-22]=c[2];
     
     
         }
      else if(  Vin>=2 &   Vin<=6){
      Serial.println("Output 28 ");
      display.print("OUTPUT  ");
      display.println(c[17]);
      delay(200);
     s[i-22]=c[17];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            }
   val=analogRead(k[3]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
//    Serial.println(Vout); 
  //  Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println("Output 4 ");
      display.print("OUTPUT  ");
      display.println(c[3]);
      delay(200);
       s[i-22]=c[3];
       // Serial.println("Output");
       // Serial.println(s[i]);
         }
      else if(  Vin>=2 &   Vin<=6){
      Serial.println("Output 29 ");
      display.print("OUTPUT  ");
      display.println(c[18]);
      delay(200);
     s[i-22]=c[18];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            }
     val=analogRead(k[4]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
//    Serial.println(Vout); 
  //  Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println(" Output 5 ");
      display.print("OUTPUT  ");
      display.println(c[4]);
      delay(200);
     s[i-22]=c[4];         }
      else if(  Vin>=2 &   Vin<=6){
      Serial.println("Output 30 ");
     display.print("OUTPUT  ");
      display.println(c[19]);
      delay(200);
     s[i-22]=c[19];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            }
   val=analogRead(k[5]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
    //Serial.print(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=11){
     // Serial.print(1);
      //delay(100);
      Serial.println(" Output 6 ");
      display.print("OUTPUT  ");
      display.println(c[5]);
      delay(200);
      s[i-22]=c[5];  
     
         }
      else if(  Vin>=2 &   Vin<=11){
     // Serial.println("Pin 8 PASS");
      display.print("8 PinOUT ");
      display.println(d[0]);
      delay(200);
     //s[i-24]=d[0];
     t[i-22]=d[0];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            } 
   val=analogRead(k[6]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
    //Serial.println(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println(" Output 7 ");
      display.print("OUTPUT ");
      display.println(c[6]);
      delay(200);
      s[i-22]=c[6];  
     
         }
      else if(  Vin>=2 &   Vin<=6){
     // Serial.println("Pin 8 PASS");
      display.print("8 PinOUT ");
      display.println(d[2]);
      delay(200);
     //s[i-20]=d[2];
     t[i-22]=d[2];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            }
  val=analogRead(k[7]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
    //Serial.println(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println("Output 8 ");
      display.print("OUTPUT ");
      display.println(c[7]);
      delay(200);
      s[i-22]=c[7];  
     
         }
      else if(  Vin>=2 &   Vin<=6){
      //Serial.println("Pin 8 PASS");
       display.print("8 PinOUT ");
      display.println(d[3]);
      delay(200);
     //s[i-20]=d[3];
     t[i-22]=d[3];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            } 
  val=analogRead(k[8]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
    //Serial.println(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println(" Output 9 ");
      display.print("OUTPUT ");
      display.println(c[8]);
      delay(200);
      s[i-22]=c[8];  
     
         }
      else if(  Vin>=2 &   Vin<=6){
      //Serial.println("Pin 8 PASS");
       display.print("8 PinOUT ");
      display.println(d[4]);
      delay(200);
     //s[i-15]=d[4];
     t[i-22]=d[4];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            } 
  val=analogRead(k[9]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
    //Serial.println(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println("Output 10 ");
      display.print("OUTPUT ");
      display.println(c[9]);
      delay(200);
      s[i-22]=c[9];  
     
         }
      else if(  Vin>=2 &   Vin<=6){
      //Serial.println("Pin 8 PASS");
       display.print("8 PinOUT ");
      display.println(d[1]);
      delay(200);
     //s[i-24]=d[1];
     t[i-22]=d[1];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            } 
val=analogRead(k[10]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
    //Serial.println(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println("Output 11 ");
      display.print("OUTPUT ");
      display.println(c[10]);
      delay(200);
      s[i-22]=c[10];  
     
         }
      else if(  Vin>=2 &   Vin<=6){
      //Serial.println("Pin 8 PASS");
       display.print("8 PinOUT ");
      display.println(d[5]);
      delay(200);
     t[i-22]=d[5];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            } 
  val=analogRead(k[11]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
    //Serial.println(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println("Output 12 ");
      display.print("OUTPUT ");
      display.println(c[11]);
      delay(200);
     s[i-22]=c[11];  
         }
      else if(  Vin>=2 &   Vin<=6){
      //Serial.println("Pin 8 PASS");
       display.print("8 PinOUT ");
      display.println(d[7]);
      delay(200);
     t[i-22]=d[7];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            } 
            
 val=analogRead(k[12]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
    //Serial.println(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println(" Output  13 ");
      display.print("OUTPUT ");
      display.println(c[12]);
      delay(200);
     s[i-22]=c[12];  
         }
      else if(  Vin>=2 &   Vin<=6){
      //Serial.println("Pin 8 PASS");
       display.print("8 PinOUT ");
      display.println(d[6]);
      delay(200);
     t[i-22]=d[6];
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            }
val=analogRead(k[13]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
    //Serial.println(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println(" Output 14 ");
      display.print("OUTPUT ");
      display.println(c[13]);
      delay(200);
     s[i-22]=c[13];  
         }
      else if(  Vin>=2 &   Vin<=6){
      //Serial.println("Pin 8 PASS");
      delay(200);
     
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            } 
            
val=analogRead(k[14]);
   Vout = (val/1023)*5; // t[]  Vout
    Vin  = Vout / (R2/(R1+R2)); /// r[] Vin
    delay(100);                       //
          //
    //Serial.println(Vout); 
    //Serial.println( Vin); 
    //
   if (  Vin<0.09) {
     Vin=0.0;
   }
     if (  Vin>=10){
     // Serial.print(1);
      //delay(100);
      Serial.println(" Output 25 ");
      display.print("OUTPUT ");
      display.println(c[14]);
      delay(200);
     s[i-22]=c[14];  
         }
      else if(  Vin>=2 &   Vin<=6){
      //Serial.println("Pin 8 PASS");
      delay(200);
     
          }
      else {
      //Serial.println(" FAIL");
      delay(200);
     
            } 
          
    display.display();   
   delay(1000); // Show initial text
    display.clearDisplay();
    delay(300);
    
             if ( s[(i-22)]==f[i-22]){
                Serial.println("GECTI");  
                Serial.println(s[i-22]); }
             else{
          Serial.println(" HATA");
         display.setCursor(5, 20);
         display.print(F("HATA " ));
         display.println(l[i-22], DEC);
         display.display(); 
         delay(1000);// Show initial text
         delay(1000);
          
           return ;
                  }
              if ( t[(i-22)]==e[i-22]){
                Serial.println("GECTI");  
                Serial.println(t[i-22]); }
             else{
          Serial.println(" HATA");
         display.setCursor(5, 20);
         display.print(F("HATA " ));
         display.println(l[i-22], DEC);
         display.display(); 
         delay(1000);// Show initial text
         delay(1000);
          
           break ;
                  }
      
digitalWrite(i,LOW);
delay(500);

  }
  display.clearDisplay();
   display.setCursor(5, 20);
display.print("TEST BITTI");
display.display(); 
delay(2000);
display.clearDisplay();
}
