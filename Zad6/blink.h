#ifndef blink_h
#define blink_h
#include"morse.h"
#define _WIN32_WINNT 0x403
#include <windows.h>

class blink: public morse
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

	int dotSleepTime;
	int dashSleepTime;
	int SpaceSleepTime;
};

#endif