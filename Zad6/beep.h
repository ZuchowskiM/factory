#ifndef beep_h
#define beep_h
#include"morse.h"
#include<Windows.h>

class beep: public morse
{
public:
	beep();
	beep(const beep& b_p);
	beep& operator=(const beep& b_p);
	~beep();
	void makeDot();
	void makeDash();
	void makeSpace();
	void convert(std::string s_p);
	void convert(int i_p);
	void convert(float f_p);
	
private://znajdz przyklad ze nie private
	int m_frequency;  // przechowuje czestotliwosc dla sygna�u d�wi�kowego 
	int m_dotTime;    // przechowuje czas trwania sygna�u d�wi�kowego dla kropki
	int m_dashTime;   // przechowouje czas trwania sygna�u d�wi�kowego dla kreski
	int m_pause;      // przechowuje czas trwania pauzy mi�dzy d�wi�kami w ramach jednego znaku . i -
	int m_spacePause; // przechowuje czas trwania pauzy spacji w ci�gu znak�w
	int m_charPause;  // przechowuje czas pauzy odtwarzania dzwi�ku znaku
};

#endif