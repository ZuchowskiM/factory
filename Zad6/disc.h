/*
		Klasa "disc"
		Opis: Klasa pochodna po morse, jej metody definicje metod umo¿liwiaja przekonwertowanie danych na kod morse i
		zapisanie go na dysku

		Autor: Micha³ ¯uchowski
		Data utworzenia: 08.01.2020
		Data poprawki/edycja: 15.12.2020
*/

#ifndef disc_h
#define disc_h
#include"morse.h"
#include"fstream"

class disc: public morse
{
	friend class factory;
private:
	disc();
	disc(const disc& b_p);
	disc& operator=(const disc& b_p);
	~disc();
	void makeDot();
	void makeDash();
	void makeSpace();
	void convert(std::string s_p, std::string extInfo);
	void convert(int i_p, std::string extInfo);
	void convert(float f_p, std::string extInfo);
	void setFromInfo(std::string info_p);
	morse* clone() const;
	const std::vector<std::string> getCurrentSetup() const;

	std::ofstream plik;
	std::string fileName;
};

#endif
