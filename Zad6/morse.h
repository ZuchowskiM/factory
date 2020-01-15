/*
		Klasa "morse"
		Opis: dostarcza abstrakcjn� klas� bazow� obraz na bazie kt�rej mo�emy zbudowa� klasy pochodne i  
		dostarcza podstawowe deklaracje metod dla klas pochodnych
		Autor: Micha� �uchowski
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
//wybra�em zaprzyja�nienie jako spos�b odciecia dost�pu userowi do sk�adnik�w klas fabrykuj�cych
//uzna�em �e skoro dajemy userowi system sterowania ca�� fabryk� to czemu dawac mu poszczeg�lnych linii produkcyjnych
friend class factory;
protected:
	morse();
	morse(const morse& m_p);
	morse& operator=(const morse& m_p);
	virtual ~morse();//virtual, dziedziczenie itp.
	virtual void makeDot() = 0;
	virtual void makeDash() = 0;
	virtual void makeSpace() = 0;

	//metody convert mo�na zredukowa� definiuj�c je w morsie zamiast za ka�dym razem w klasach pochodnych
	//sposobem dzialania convert bedzie mozna manipulowac poprzez makeDot makeDash... itp.
	//zmniejszy to ilosc kodu kt�ry w zasadzie jest taki sam jednak kosztem elastycznosci np.
	//gdy przyjdzie doda� kolejn� klas�
	//zdecydowa�em si� na bardziej elastyczne podejscie
	virtual void convert(std::string s_p, std::string extInfo)=0;
	virtual void convert(int i_p, std::string extInfo)=0;
	virtual void convert(float f_p, std::string extInfo)=0;

	//metoda zamienia string na string ale w kodzie morse
	const std::string ToMorseCode(const std::string& s_p);

	//poliformiczny konstruktor kopiuj�cy, przydatny w kontruktorze kopiujacym fabryki.cpp
	virtual morse* clone() const = 0;
	
	//metoda zwraca vector ze wartoscia konkretnych pol w string z klasy pochodnej
	virtual const std::vector<std::string> getCurrentSetup() const = 0;

	//podawac kolejne wartosci dla zmiennych oddzielajac je spacja,
	//ustawione sa w kolejnosci takiej jak zmienne w polach klasy liczac od gory do dolu
	virtual void setFromInfo(std::string info_p) = 0;
};

#endif