// C++ code
#include<LiquidCrystal.h>
int PHOTOSENSOR = 0;

int TMP = A1;

int GAS_SENSOR = 0;

const int rs = 10, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 


float celsius;

void setup()
{
  pinMode(A0, INPUT);    //set pin to take the input
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(TMP,INPUT);
  
  pinMode(13, OUTPUT);    //set pins to take the output
  pinMode(12, OUTPUT);
  
  Serial.begin(9600);    //band rate-9600 bits per second
  lcd.begin(16,2);    //16 columns and 2 rows that can accomodate
  
}

void loop()
{
  GAS_SENSOR = map(analogRead(A2), 0, 1023, 0, 255);
  PHOTOSENSOR = map(analogRead(A0), 0, 1023, 0, 255);
  //Serial.println(GAS_SENSOR);
  if (GAS_SENSOR > 21) {
    digitalWrite(13, HIGH);
    tone(13, 548668578, 300); // play tone 300 (Frequency = 548668578 Hz)
  } else {
    digitalWrite(13, LOW);
  }
  //Serial.println(PHOTOSENSOR);
  if (PHOTOSENSOR < 131) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  
    celsius = ((analogRead(TMP)*0.004882814)-0.5)*100;
    //Serial.println(analogRead(TMP));
  	
  
    int a = analogRead(A3);
    //Serial.println(a);
    if(a==1018)
    {
    lcd.setCursor(0,0);
    lcd.print("Security Breach");
    delay(200);
    lcd.clear();
    }
    else
    {
    lcd.setCursor(0,1);
	lcd.print("Temp: ");
  	lcd.print(celsius);
	lcd.print(" C");
  	delay(100);
  	lcd.clear();
    }
  delay(10); // Delay a little bit to improve simulation performance
}
