/*
		Klasa "console"
		Opis: Klasa pochodna po morse, jej definicje metod umo¿liwiaja wyœwietlanie kodu morse w konsoli
		Autor: Micha³ ¯uchowski
		Data utworzenia: 08.01.2020
		Data poprawki/edycja: 15.12.2020
*/

#ifndef console_h
#define console_h
#include"morse.h"

//dzieczinie private umieœci wszystko w sk³adnikach prywatnych
//po tej klasie pochodnej nie zamierzamy dziedziczyæ tym bardziej w tym wzorcu
class console : private morse
{
	friend class factory;
private:
	console();
	console(const console& b_p);
	console& operator=(const console& b_p);
	~console();
	void makeDot();
	void makeDash();
	void makeSpace();
	void convert(std::string s_p, std::string extInfo);
	void convert(int i_p, std::string extInfo);
	void convert(float f_p, std::string extInfo);
	void setFromInfo(std::string info_p);
	morse* clone() const;
	const std::vector<std::string> getCurrentSetup() const;

};

#endif