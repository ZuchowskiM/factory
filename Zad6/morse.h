/*
		Klasa "morse"
		Opis: dostarcza abstrakcjn¹ klasê bazow¹ obraz na bazie której mo¿emy zbudowaæ klasy pochodne i  
		dostarcza podstawowe deklaracje metod dla klas pochodnych
		Autor: Micha³ ¯uchowski
		Data utworzenia: 08.01.2020
		Data poprawki/edycja: 15.12.2020
*/

#ifndef morse_h
#define morse_h
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
class factory;


class morse
{
//wybra³em zaprzyjaŸnienie jako sposób odciecia dostêpu userowi do sk³adników klas fabrykuj¹cych
//uzna³em ¿e skoro dajemy userowi fabrykê to nie dajemu mu poszczególnych linii produkcyjnych
friend class factory;
protected:
	morse();
	morse(const morse& m_p);
	morse& operator=(const morse& m_p);
	virtual ~morse();//virtual, dziedziczenie itp.
	virtual void makeDot() = 0;
	virtual void makeDash() = 0;
	virtual void makeSpace() = 0;
	virtual void convert(std::string s_p, std::string extInfo)=0;
	virtual void convert(int i_p, std::string extInfo)=0;
	virtual void convert(float f_p, std::string extInfo)=0;

	//metoda zamienia string na string ale w kodzie morse
	const std::string ToMorseCode(const std::string& s_p);

	//poliformiczny konstruktor kopiuj¹cy, przydatnny w kontruktorze kopiujacym fabryki
	virtual morse* clone() const = 0;
	
	//metoda zwraca vector ze wartoscia konkretnych pol w string z klasy pochodnej
	virtual const std::vector<std::string> getCurrentSetup() const = 0;
};

#endif