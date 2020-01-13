#ifndef morse_h
#define morse_h
#include<iostream>
#include<string>
#include<sstream>
class factory;

class morse
{
friend class factory;
protected:
	morse();
	morse(const morse& m_p);
	morse& operator=(const morse& m_p);
	virtual ~morse();
	virtual void makeDot() = 0;
	virtual void makeDash() = 0;
	virtual void makeSpace() = 0;
	virtual void convert(std::string s_p, std::string extInfo)=0;
	virtual void convert(int i_p, std::string extInfo)=0;
	virtual void convert(float f_p, std::string extInfo)=0;
	const std::string ToMorseCode(const std::string& s_p);

};

#endif