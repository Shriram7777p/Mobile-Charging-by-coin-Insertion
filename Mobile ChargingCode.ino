// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int i,j,x=0,c=0,status=0,flage=0,temp=0;
void setup() {
  lcd.begin(16, 2);
  pinMode(8, OUTPUT);//Output pin
  pinMode(6, INPUT);//Input pin
   for(int i=200; i<=210; i=i+1)
  {
    lcd.setCursor(0,0);
    lcd.print("Coin Detection Based");// Projet Display 
    lcd.scrollDisplayRight();
    lcd.setCursor(0,1);
    lcd.print("Mobile Charging System");
    lcd.scrollDisplayRight();
    delay(i+5);
  } 
}
void coin_acceptor()
{
      lcd.setCursor(0,0);
      lcd.print("Type 1 COIN INSERTED");// After incertion of coin type 1
      delay(1000);  
      lcd.clear();
      lcd.setCursor(0,0);
      digitalWrite(8,HIGH);
      lcd.print("MOBILE CHARGING ");// charge for 2 Minutes
      for(int j=1;j>=0;j--)
      {
      for(int i=59;i>=0;i--)
      {
        lcd.setCursor(0, 1);
        if(i>9)lcd.print(" ");
        else lcd.print(" ");
        lcd.print(j);
        lcd.print(":");
        lcd.print(i);
        delay(1000);
      }
      }
    digitalWrite(8,LOW);
    lcd.clear();
    c=0;
}
void coin_acceptor2()
{
      lcd.setCursor(0,0);
      lcd.print("Type 2 COIN INSERTED");// After Incertion of coin type 2
      delay(1500);  
      lcd.clear();
      lcd.setCursor(0,0);
      digitalWrite(8,HIGH);
      lcd.print("MOBILE CHARGING ");// Charge for 5 Minutes
      for(int j=4;j>=0;j--)
      {
      for(int i=59;i>=0;i--)
      {
        lcd.setCursor(0, 1);
        if(i>9)lcd.print(" ");
        else lcd.print(" ");
        lcd.print(j);
        lcd.print(":");
        lcd.print(i);
        delay(1000);
      }
      }
    digitalWrite(8,LOW);
    c=0;
    lcd.clear();
}
void coin_acceptor3()
{
      lcd.setCursor(0,0);
      lcd.print("RS:Type 3 COIN INSERTED ");// After Incertion of coin type 3
      delay(1500);  
      lcd.clear();
      lcd.setCursor(0,0);
      digitalWrite(8,HIGH);
      lcd.print("MOBILE CHARGING ");// Charge mobile for 15  Minutes
      for(int j=14;j>=0;j--)
      {
      for(int i=59;i>=0;i--)
      {
        lcd.setCursor(0, 1);
        if(i>9)lcd.print(" ");
        else lcd.print(" ");
        lcd.print(j);
        lcd.print(":");
        lcd.print(i);
        delay(1000);
      }
      }
    digitalWrite(8,LOW);
    c=0;
    lcd.clear();
}
void coin_acceptor4()
  {
      lcd.setCursor(0,0);
      lcd.print("Tupe 4 COIN INSERTED ");// After Incertion of coin type 4
      delay(1500);  
      lcd.clear();
      lcd.setCursor(0,0);
      digitalWrite(8,HIGH);
      lcd.print("MOBILE CHARGING ");//Mobile Charing for 30 Minutes 
      for(int j=29;j>=0;j--)
      {
      for(int i=59;i>=0;i--)
      {
        lcd.setCursor(0, 1);
        if(i>9)lcd.print(" ");
        else lcd.print(" ");
        lcd.print(j);
        lcd.print(":");
        lcd.print(i);
        delay(1000);
      }
      }
    digitalWrite(8,LOW);
    c=0;
    lcd.clear();
}
void check()
{ 
    if(c>7 && c<12 && flage==4){
        coin_acceptor4();
    }if(c>4 && c<8 && flage==3){
        coin_acceptor3();
    }if(c>1 && c<5 && flage==2){
        coin_acceptor2();
    }else if(c>0 && c<2 && flage==1 ){
        coin_acceptor();
    }
}
//loop code
void loop() {
G:lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" INSERT COIN ");
  lcd.setCursor(0,1);
  lcd.print(c);
  delay(100);
  status = digitalRead(6);
  while(status==LOW){
            c++;
            if(c==1){
            flage=1;
        }
            break;
  }
  if(temp<12){
        temp++;
        goto G;
    }else 
    {
        temp=0;
        goto H;
    }
 H: if(c>7 && c<12){
        flage=4;
    }if(c>3 && c<8){
        flage=3;
    }if(c>1 && c<5){
        flage=2;
    }
  check();
}
