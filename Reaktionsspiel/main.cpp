#include <wiringPi.h>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
// "LED-Pin: wiringPi-Pin 0" entspricht "BCM_GPIO 17".
// Bei einer Initialisierung mit wiringPiSetupSys muss die BCM-Nummerierung verwendet werden.
// Wenn Sie eine andere Pin-Nummer wählen, verwenden Sie die BCM-Nummerierung, und
// aktualisieren Sie außerdem unter "Eigenschaftenseiten" > "Buildereignisse" den Remote-Postbuildereignisbefehl,
// der den GPIO-Export zum Einrichten von wiringPiSetupSys verwendet.
//Von Sd nach Ethernet port
#define	ROT1	4 
#define GELB1	17
#define GRUEN1	22
#define	ROT2	10
#define GELB2	9
#define GRUEN2	11
#define Taste1	7
#define Taste2	18
void Blink();
void PingpongL(int);
void PingpongR(int);
void Gamestart(int,bool);
void Gameover();
void lightsout();
using namespace std;


	int main(void)
	{
		srand(time(NULL));
		bool gameisrunning = false;
		bool ballamenderechts = false;
		bool ballamendelinks = false;
		int Intdelay = 200;
		bool pressed = false;
		wiringPiSetupSys();
		pinMode(Taste1, INPUT);
		pinMode(Taste2, INPUT);

		pinMode(ROT1, OUTPUT);
		pinMode(GELB1, OUTPUT);
		pinMode(GRUEN1, OUTPUT);

		pinMode(ROT2, OUTPUT);
		pinMode(GELB2, OUTPUT);
		pinMode(GRUEN2, OUTPUT);

		while (true)
		{
			/*if (gameisrunning == false)
			{
				int help = 0;
				gameisrunning = true;
				help = rand() % 2 + 1;
				if (help == 1)
				{
					digitalWrite(GRUEN2, HIGH);
					delay(20);
					digitalWrite(GRUEN2, LOW);
					PingpongL(Intdelay, ballamenderechts);
				}
				if (help == 2)
				{
					digitalWrite(ROT1, HIGH);
					delay(200);
					digitalWrite(ROT1, LOW);
					cout << "Links";
					PingpongR(Intdelay, ballamendelinks);
					ballamendelinks = true;
				}
			}*/
			if (gameisrunning == false)
			{
				if (digitalRead(Taste2) == 1 && digitalRead(Taste1) == 1)
				{
					Intdelay = 200;
					gameisrunning = true;
					lightsout();
					Gamestart(Intdelay, ballamenderechts);
					ballamenderechts = true;
				}
			}
			if (gameisrunning == true)
			{

				if (ballamendelinks == true)
				{

					delay(50);
					if (digitalRead(Taste2) == 1)
					{
						ballamendelinks = false;
						PingpongL(Intdelay);
						ballamenderechts = true;
						if (Intdelay >= 100)
						{
							Intdelay = Intdelay - 20;
						}
						else
						{

						}
					}
					else
					{
						digitalWrite(ROT1, HIGH);
						delay(200);
						digitalWrite(ROT1, LOW);
						delay(200);
						digitalWrite(ROT1, HIGH);
						delay(200);
						digitalWrite(ROT1, LOW);
						// game over links hat verloren 
						Gameover();
						gameisrunning = false;

					}
				}
				if (ballamenderechts == true)
				{


					delay(50);
					if (digitalRead(Taste1) == 1)
					{
						ballamenderechts = false;
						PingpongR(Intdelay);
						ballamendelinks = true;
						if (Intdelay >= 40)
						{
							Intdelay = Intdelay - 20;
						}
						else
						{

						}
					}
					else
					{
						digitalWrite(GRUEN2, HIGH);
						delay(200);
						digitalWrite(GRUEN2, LOW);
						delay(200);
						digitalWrite(GRUEN2, HIGH);
						delay(200);
						digitalWrite(GRUEN2, LOW);
						//gameover rechts hat verloren
						Gameover();
						gameisrunning = false;
					}
				}
			}
		}


		return 0;
	}
void Gamestart(int Intdelay, bool ballamenderechts)
{
	
	PingpongL(Intdelay);
	ballamenderechts = true;


}
void Blink()
{

	digitalWrite(ROT1, HIGH);  // Ein
	digitalWrite(GELB1, HIGH);
	digitalWrite(GRUEN1, HIGH);

	digitalWrite(ROT2, HIGH);
	digitalWrite(GELB2, HIGH);
	digitalWrite(GRUEN2, HIGH);
	delay(500); // ms
	digitalWrite(ROT1, LOW);
	digitalWrite(GELB1, LOW);
	digitalWrite(GRUEN1, LOW);

	digitalWrite(ROT2, LOW);
	digitalWrite(GELB2, LOW);
	digitalWrite(GRUEN2, LOW);// Aus
	delay(500);
}
void PingpongL(int Intdelay) // Spiel ball von Links(von Schalter sicht) nach Rechts
{
	digitalWrite(GRUEN2, HIGH);
	delay(Intdelay);
	digitalWrite(GRUEN2, LOW);
	delay(Intdelay);
	digitalWrite(GELB2, HIGH);
	delay(Intdelay);
	digitalWrite(GELB2, LOW);
	delay(Intdelay);
	digitalWrite(ROT2, HIGH);
	delay(Intdelay);
	digitalWrite(ROT2, LOW);
	delay(Intdelay);
	digitalWrite(GRUEN1, HIGH);
	delay(Intdelay);
	digitalWrite(GRUEN1, LOW);
	delay(Intdelay);
	digitalWrite(GELB1, HIGH);
	delay(Intdelay);
	digitalWrite(GELB1, LOW);
	delay(Intdelay);
	digitalWrite(ROT1, HIGH);
	delay(Intdelay);
	digitalWrite(ROT1, LOW);
	delay(Intdelay);

}
void PingpongR(int Intdelay)
{
	digitalWrite(ROT1, HIGH);
	delay(Intdelay);
	digitalWrite(ROT1, LOW);
	delay(Intdelay);
	digitalWrite(GELB1, HIGH);
	delay(Intdelay);
	digitalWrite(GELB1, LOW);
	delay(Intdelay);
	digitalWrite(GRUEN1, HIGH);
	delay(Intdelay);
	digitalWrite(GRUEN1, LOW);
	delay(Intdelay);
	digitalWrite(ROT2, HIGH);
	delay(Intdelay);
	digitalWrite(ROT2, LOW);
	delay(Intdelay);
	digitalWrite(GELB2, HIGH);
	delay(Intdelay);
	digitalWrite(GELB2, LOW);
	delay(Intdelay);
	digitalWrite(GRUEN2, HIGH);
	delay(Intdelay);
	digitalWrite(GRUEN2, LOW);
	delay(Intdelay);

}
void Gameover()
{
	digitalWrite(ROT2, HIGH);

	digitalWrite(GRUEN1, HIGH);
	delay(20);
	digitalWrite(ROT2, LOW);
	digitalWrite(GRUEN1, LOW);
	digitalWrite(GELB2, HIGH);
	digitalWrite(GELB1, HIGH);
	delay(20);
	digitalWrite(GELB2, LOW);
	digitalWrite(GELB1, LOW);
	digitalWrite(ROT1, HIGH);
	digitalWrite(GRUEN2, HIGH);
	digitalWrite(ROT2, HIGH);
	digitalWrite(GRUEN1, HIGH);

}
void lightsout()
{
	digitalWrite(ROT1, LOW);
	digitalWrite(GELB1, LOW);
	digitalWrite(GRUEN1, LOW);

	digitalWrite(ROT2, LOW);
	digitalWrite(GELB2, LOW);
	digitalWrite(GRUEN2, LOW);
}


