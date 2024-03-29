/*
		Klasa "console"
		Opis: Klasa pochodna po morse, jej definicje metod umożliwiaja wyświetlanie kodu morse w konsoli
		Autor: Michał Żuchowski
		Data utworzenia: 08.01.2020
		Data poprawki/edycja: 15.12.2020
*/

#ifndef console_h
#define console_h
#include"morse.h"

//dzieczinie private umieści wszystko w składnikach prywatnych
//po tej klasie pochodnej nie zamierzamy dziedziczyć tym bardziej w tym wzorcu
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