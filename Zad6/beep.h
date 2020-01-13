#ifndef beep_h
#define beep_h
#include"morse.h"
#include<Windows.h>


class beep: public morse
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


	int m_frequency;  // przechowuje czestotliwosc dla sygna³u dŸwiêkowego 
	int m_dotTime;    // przechowuje czas trwania sygna³u dŸwiêkowego dla kropki
	int m_dashTime;   // przechowouje czas trwania sygna³u dŸwiêkowego dla kreski
	int m_pause;      // przechowuje czas trwania pauzy miêdzy dŸwiêkami w ramach jednego znaku . i -
	int m_spacePause; // przechowuje czas trwania pauzy spacji w ci¹gu znaków
	int m_charPause;  // przechowuje czas pauzy odtwarzania dzwiêku znaku
};

#endif