/*
   Funktion:        Sicherheitsschaltung mit Zwei Tastern und einer LED; Beide Taster gedrückt-Lampe AN;
   Programierer:    Eric Junker
   letzte Änderung: 08.12.2020
   Version:         1.0
   Hardware:        Pin 7 güne LED
                    Pin 10 Taster Eins
                    Pin 11 Taster Zwei
*/


#include <OneButton.h>                          //Bibliothek wird eingebunden, um Taster prellen -softwaretechnisch- zu unterbinden

OneButton tasterEins(10, false);                //Taster Eins wird auf Pin 10 deklariert
OneButton tasterZwei(11, false);                //Taster Zwei wird auf Pin 11 deklariert

bool merkerTaster1 = false;
bool merkerTaster2 = false;
#define grueneLed_Eins 7


void setup()
{
  pinMode(grueneLed_Eins, OUTPUT);
 
  tasterEins.attachLongPressStart(Funktion_Taster_Eins_Start);
  tasterEins.attachLongPressStop(Funktion_Taster_Eins_Stop);
  tasterZwei.attachLongPressStart(Funktion_Taster_Zwei_Start);
  tasterZwei.attachLongPressStop(Funktion_Taster_Zwei_Stop);

}

void loop()
{
  tasterEins.tick();
  tasterZwei.tick();
  
  if ((merkerTaster1 == true) && (merkerTaster2 == true))
  {
    digitalWrite(grueneLed_Eins, HIGH);
  }
  else
  {
    digitalWrite(grueneLed_Eins, LOW);
  }

}

void Funktion_Taster_Eins_Start()
{
  merkerTaster1 = true;
}

void Funktion_Taster_Zwei_Start()
{
  merkerTaster2 = true;
}
void Funktion_Taster_Eins_Stop()
{
  merkerTaster1 = false;
}
void Funktion_Taster_Zwei_Stop()
{
  merkerTaster2 =false;
}


