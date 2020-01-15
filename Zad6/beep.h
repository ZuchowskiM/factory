/*
		Klasa "beep"
		Opis: Klasa pochodna po morse, jej definicje metod umo�liwiaja przekonwertowanie danych na kod morse i
		przedstawienie go jako sygna� d�wi�kowy z g�o�nik�w komputera
		Autor: Micha� �uchowski
		Data utworzenia: 08.01.2020
		Data poprawki/edycja: 15.12.2020
*/

#ifndef beep_h
#define beep_h
#include"morse.h"
#include<Windows.h>


class beep: private morse
{
friend class factory;
private:
	beep();
	beep(const beep& b_p);
	beep& operator=(const beep& b_p);
	~beep();
	void makeDot();
	void makeDash();
	void makeSpace();
	void convert(std::string s_p, std::string extInfo);
	void convert(int i_p, std::string extInfo);
	void convert(float f_p, std::string extInfo);
	void setFromInfo(std::string info_p);
	morse* clone() const;
	const std::vector<std::string> getCurrentSetup() const;
	
	int m_frequency;  // przechowuje czestotliwosc dla sygna�u d�wi�kowego 
	int m_dotTime;    // przechowuje czas trwania sygna�u d�wi�kowego dla kropki
	int m_dashTime;   // przechowouje czas trwania sygna�u d�wi�kowego dla kreski
	int m_pause;      // przechowuje czas trwania pauzy mi�dzy d�wi�kami w ramach jednego znaku . i -
	int m_spacePause; // przechowuje czas trwania pauzy spacji w ci�gu znak�w
	int m_charPause;  // przechowuje czas pauzy odtwarzania dzwi�ku znaku


	
};

#endif