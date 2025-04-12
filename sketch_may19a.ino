
#include <Adafruit_Fingerprint.h> 
#include <SoftwareSerial.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
SoftwareSerial mySerial(2, 3);
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{

   lcd.init();         // initialize the lcd
  lcd.backlight();    // Turn on the LCD screen backlight
  Serial.begin(9600);
  while (!Serial); 
  delay(100);
  pinMode(13,OUTPUT);
  Serial.println("Program Dasar Akses Sidik Jari Arduino");
  Serial.println("https://www.cronyos.com");

  // set the data rate for the sensor serial port
  finger.begin(57600);
       lcd.setCursor(0, 0);
  lcd.print("Anmol kumar ");
  delay(3000);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");

 
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
  Serial.println("Waiting for valid finger...");

     lcd.setCursor(0, 1);
  lcd.print("PLACE FINGER    ");
  delay(3000);
}

void loop()                     // run over and over again
{
  getFingerprintID();
  delay(50);            //don't ned to run this at full speed.
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
           lcd.setCursor(0, 1);
  lcd.print("IMAGE TAKEN     ");
  delay(3000);
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.println(".");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");

         lcd.setCursor(0, 1);
  lcd.print("FOUND FINGER    ");
  delay(3000);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("DIDN'T MATCH    ");
  delay(2000);
   lcd.setCursor(0, 1);
  lcd.print("PLACE FINGER    ");
  delay(1000);
  
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 

 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 
  digitalWrite(13,HIGH);

     lcd.setCursor(0, 1);
  lcd.print("GATE OPEN       ");
  
  delay(2000);
  digitalWrite(13,LOW);

  
   lcd.setCursor(0, 1);
  lcd.print("GATE CLOSE     ");
  
  delay(2000);

   lcd.setCursor(0, 1);
  lcd.print("PLACE FINGER    ");
  delay(3000);
  return finger.fingerID;
}
