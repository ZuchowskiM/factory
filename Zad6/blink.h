/*
		Klasa "blink"
		Opis: Klasa pochodna po morse, jej definicje metod umo¿liwiaja przedstawienie kodu morse jako miganie lampki CapsLock
		Autor: Micha³ ¯uchowski
		Data utworzenia: 08.01.2020
		Data poprawki/edycja: 15.12.2020
*/

#ifndef blink_h
#define blink_h
#include"morse.h"
#define _WIN32_WINNT 0x403
#include <windows.h>

class blink: private morse
{
	friend class factory;
private:
	blink();
	blink(const blink& b_p);
	blink& operator=(const blink& b_p);
	~blink();
	void makeDot();
	void makeDash();
	void makeSpace();
	void convert(std::string s_p, std::string extInfo);
	void convert(int i_p, std::string extInfo);
	void convert(float f_p, std::string extInfo);
	void setFromInfo(std::string info_p);
	morse* clone() const;
	const std::vector<std::string> getCurrentSetup() const;

	int dotSleepTime;
	int dashSleepTime;
	int SpaceSleepTime;
};

#endif