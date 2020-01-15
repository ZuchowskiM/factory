/*
		Klasa "factory"
		Opis: Umo¿liwa korzystanie z calej rodziny obiektów morse za pomoc¹ interfesju tej klasy

		Autor: Micha³ ¯uchowski
		Data utworzenia: 08.01.2020
		Data poprawki/edycja: 15.12.2020
*/

#ifndef factory_h
#define factory_h
#include"beep.h"
#include"console.h"
#include "disc.h"
#include "blink.h"

class factory
{
public:
	factory();//domyœlnie tryb dzialania fabrki to beep
	factory(const factory& f_p);
	factory& operator=(const factory& f_p);
	~factory();
	void convert(std::string s_p) const;
	void convert(int i_p) const;
	void convert(float f_p) const;
	void setExtInfo(std::string s_p);

	//manipulujemy setOutput za pomoc¹ zmiennych podanych pod deklaracja funkcji
	void setOutput(int FactoryOperatingMode);

	///////tryby dzia³ania fabryki//////////
	static const int beepNumber = 1;
	static const int consoleNumber = 2;
	static const int discNumber = 3;
	static const int blinkNumber = 4;
	///////////////////////////////////////

	//zwraca dane z "kartki" która daliœmy fabryce
	const std::string& getExtInfo() const;

	//zwraca ustawienie linii produkcyjnej która aktualnie jest ustawiona
	const std::vector<std::string> getCurrentSetup() const;
	

private:
	morse* m_m;
	std::string extInfo;//"kartka" z naszymi wytycznymi dla linii produkcyjnej

};

#endif