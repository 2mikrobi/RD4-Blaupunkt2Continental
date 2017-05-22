//Arduino ProMini 5V 16Mhz
/* Continental Keypad
 * 1 1  Down
 * 1 2  Source
 * 1 3  Ta
 * 1 4  6
 * 1 5
 * 2 1  Esc
 * 2 2  3
 * 2 3  Right
 * 2 4  4
 * 2 5  Dark
 * 3 1  List
 * 3 2  2
 * 3 3  OK
 * 3 4  Tone
 * 3 5  1
 * 4 1  
 * 4 2  Eject
 * 4 3  Menu
 * 4 4
 * 4 5  Mode
 * 5 1  Left
 * 5 2  Band
 * 5 3  Up
 * 5 4  5
 * 5 5
 */
#define SerialDebug false
#include "DigitalIO.h"

//piny podłączone pod panel
#define BlaupunktPanelWiersz0 15 //A1 
#define BlaupunktPanelWiersz1 16 //A2
#define BlaupunktPanelWiersz2 17 //A3
#define BlaupunktPanelWiersz3 18 //A4
#define BlaupunktPanelWiersz4 19 //A5

#define BlaupunktPanelKolumna0 2
#define BlaupunktPanelKolumna1 3
#define BlaupunktPanelKolumna2 4
#define BlaupunktPanelKolumna3 5
#define BlaupunktPanelKolumna4 6

//piny podłączone do radia
//definicja pinów podłączonych do radia
//kolejnosc 10,rx,tx,10
#define Wradio1 0 //rx
#define Wradio2 10 //10
#define Wradio3 14 //a0
#define Wradio4 1 //tx 
#define Wradio5 11 //11

//wyjścia!!!!!!!!!!!
#define Kradio1 12 //12
#define Kradio2 9 //9
#define Kradio3 8 //8
#define Kradio4 7 //7
#define Kradio5 13 //13

DigitalPin<BlaupunktPanelWiersz0> w0;
DigitalPin<BlaupunktPanelWiersz1> w1;
DigitalPin<BlaupunktPanelWiersz2> w2;
DigitalPin<BlaupunktPanelWiersz3> w3;
DigitalPin<BlaupunktPanelWiersz4> w4;
  
DigitalPin<BlaupunktPanelKolumna0> k0;
DigitalPin<BlaupunktPanelKolumna1> k1;
DigitalPin<BlaupunktPanelKolumna2> k2;
DigitalPin<BlaupunktPanelKolumna3> k3;
DigitalPin<BlaupunktPanelKolumna4> k4;

DigitalPin<Wradio1> wradio1;
DigitalPin<Wradio2> wradio2;
DigitalPin<Wradio3> wradio3;
DigitalPin<Wradio4> wradio4;
DigitalPin<Wradio5> wradio5;

DigitalPin<Kradio1> kradio1;
DigitalPin<Kradio2> kradio2;
DigitalPin<Kradio3> kradio3;
DigitalPin<Kradio4> kradio4;
DigitalPin<Kradio5> kradio5;

int kolumna,wiersz;

void setup() {
  
  w0.mode(INPUT_PULLUP);
  w1.mode(INPUT_PULLUP);
  w2.mode(INPUT_PULLUP);
  w3.mode(INPUT_PULLUP);
  w4.mode(INPUT_PULLUP);

  k0.mode(OUTPUT);
  k1.mode(OUTPUT);
  k2.mode(OUTPUT);
  k3.mode(OUTPUT);
  k4.mode(OUTPUT);

  wradio1.mode(INPUT);
  wradio2.mode(INPUT);
  wradio3.mode(INPUT);
  wradio4.mode(INPUT);
  wradio5.mode(INPUT);

  kradio1=HIGH;
  kradio2=HIGH;
  kradio3=HIGH;
  kradio4=HIGH;
  kradio5=HIGH;
  kradio1.mode(OUTPUT);
  kradio2.mode(OUTPUT);
  kradio3.mode(OUTPUT);
  kradio4.mode(OUTPUT);
  kradio5.mode(OUTPUT);
  kradio1=HIGH;
  kradio2=HIGH;
  kradio3=HIGH;
  kradio4=HIGH;
  kradio5=HIGH;
  if (SerialDebug) Serial.begin(9600);
  
}
void pressKey(int kkolumna,int kwiersz)
{
int x=0;
#define petla  for(long int i=0;i<180000;i++)
//#define petla  for(long int i=0;i<15000u;i++)
  if ((kwiersz==1)&(kkolumna==1)) petla {kradio1=wradio1;};
  if ((kwiersz==1)&(kkolumna==2)) petla {kradio2=wradio1;};
  if ((kwiersz==1)&(kkolumna==3)) petla {kradio3=wradio1;};
  if ((kwiersz==1)&(kkolumna==4)) petla {kradio4=wradio1;};
  if ((kwiersz==1)&(kkolumna==5)) petla {kradio5=wradio1;};

  if ((kwiersz==2)&(kkolumna==1)) petla {kradio1=wradio2;};
  if ((kwiersz==2)&(kkolumna==2)) petla {kradio2=wradio2;};
  if ((kwiersz==2)&(kkolumna==3)) petla {kradio3=wradio2;};
  if ((kwiersz==2)&(kkolumna==4)) petla {kradio4=wradio2;};
  if ((kwiersz==2)&(kkolumna==5)) petla {kradio5=wradio2;};

  if ((kwiersz==3)&(kkolumna==1)) petla {kradio1=wradio3;};
  if ((kwiersz==3)&(kkolumna==2)) petla {kradio2=wradio3;};
  if ((kwiersz==3)&(kkolumna==3)) petla {kradio3=wradio3;};
  if ((kwiersz==3)&(kkolumna==4)) petla {kradio4=wradio3;};
  if ((kwiersz==3)&(kkolumna==5)) petla {kradio5=wradio3;};

  if ((kwiersz==4)&(kkolumna==1)) petla {kradio1=wradio4;};
  if ((kwiersz==4)&(kkolumna==2)) petla {kradio2=wradio4;};
  if ((kwiersz==4)&(kkolumna==3)) petla {kradio3=wradio4;};
  if ((kwiersz==4)&(kkolumna==4)) petla {kradio4=wradio4;};
  if ((kwiersz==4)&(kkolumna==5)) petla {kradio5=wradio4;};

  if ((kwiersz==5)&(kkolumna==1)) petla {kradio1=wradio5;};
  if ((kwiersz==5)&(kkolumna==2)) petla {kradio2=wradio5;};
  if ((kwiersz==5)&(kkolumna==3)) petla {kradio3=wradio5;};
  if ((kwiersz==5)&(kkolumna==4)) petla {kradio4=wradio5;};
  if ((kwiersz==5)&(kkolumna==5)) petla {kradio5=wradio5;};

  kradio1=HIGH;
  kradio2=HIGH;
  kradio3=HIGH;
  kradio4=HIGH;
  kradio5=HIGH;
};

void GetKolumna()
{
 kolumna=0;
 kolumna=(k4 << 4) | (k3 << 3) | (k2 << 2) | (k1 << 1) | (k0); 

}
void GetWiersz(){
 GetKolumna();
 wiersz=0;
 wiersz=(w4 << 4) | (w3 << 3) | (w2 << 2) | (w1 << 1) | (w0); 
}

void GoPress(char klawisz[20],int k,int w)
{
 if (SerialDebug) Serial.println(klawisz);
 pressKey(k,w);  
}
void ShowKey()
{
  char klawisz[20];
   if (wiersz!=B11111) 
   {
     if ((kolumna==B11101)&(wiersz==B11110)) GoPress("AUDIO"  ,4,5);
     if ((kolumna==B11101)&(wiersz==B11011)) GoPress("SOURCE" ,1,2);
     if ((kolumna==B11110)&(wiersz==B11011)) GoPress("TRIP"   ,4,5);
     if ((kolumna==B11101)&(wiersz==B11101)) GoPress("BAND"   ,5,2);
     if ((kolumna==B11110)&(wiersz==B11101)) GoPress("CLIM"   ,4,5);
     if ((kolumna==B11101)&(wiersz==B10111)) GoPress("DARK"   ,2,5);
     if ((kolumna==B11011)&(wiersz==B11110)) GoPress("ESC"    ,2,1);
     if ((kolumna==B11110)&(wiersz==B10111)) GoPress("MENU"   ,4,3);
     if ((kolumna==B11101)&(wiersz==B01111)) GoPress("TONE"   ,3,4);
     if ((kolumna==B11011)&(wiersz==B11101)) GoPress("UP"     ,5,3);
     if ((kolumna==B11011)&(wiersz==B10111)) GoPress("DOWN"   ,1,1);
     if ((kolumna==B11011)&(wiersz==B11011)) GoPress("LEFT"   ,5,1);
     if ((kolumna==B10111)&(wiersz==B11011)) GoPress("RIGHT"  ,2,3);
     if ((kolumna==B11011)&(wiersz==B01111)) GoPress("OK"     ,3,3);
     if ((kolumna==B10111)&(wiersz==B11110)) GoPress("TA"     ,1,3);
     if ((kolumna==B10111)&(wiersz==B11101)) GoPress("LIST"   ,3,1);
     if ((kolumna==B10111)&(wiersz==B10111)) GoPress("PTY"    ,1,3);
     if ((kolumna==B10111)&(wiersz==B01111)) GoPress("1"      ,3,5);
     if ((kolumna==B01111)&(wiersz==B11101)) GoPress("2"      ,3,2);
     if ((kolumna==B01111)&(wiersz==B10111)) GoPress("3"      ,2,2);
     if ((kolumna==B01111)&(wiersz==B11110)) GoPress("4"      ,2,4);
     if ((kolumna==B01111)&(wiersz==B11011)) GoPress("5"      ,5,4);
     if ((kolumna==B01111)&(wiersz==B01111)) GoPress("6"      ,1,4);
     if ((kolumna==B11110)&(wiersz==B11110)) GoPress("EJECT"  ,4,2);
    /* 
     Serial.print(kolumna,BIN);
     Serial.print("---");
     Serial.println(wiersz,BIN);
     */
   } 
   
}
void loop() {
 k4=1; k3=1; k2=1; k1=1; k0=0; GetWiersz(); ShowKey();
 k4=1; k3=1; k2=1; k1=0; k0=1; GetWiersz(); ShowKey();
 k4=1; k3=1; k2=0; k1=1; k0=1; GetWiersz(); ShowKey();
 k4=1; k3=0; k2=1; k1=1; k0=1; GetWiersz(); ShowKey();
 k4=0; k3=1; k2=1; k1=1; k0=1; GetWiersz(); ShowKey();
}
