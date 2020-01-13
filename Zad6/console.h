#ifndef console_h
#define console_h
#include"morse.h"


class console : public morse
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

};

#endif