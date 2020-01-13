#ifndef factory_h
#define factory_h
#include"beep.h"
#include"console.h"
#include "disc.h"

class factory
{
public:
	factory();
	factory(const factory& f_p);
	factory& operator=(const factory& f_p);
	~factory();
	void convert(std::string s_p);
	void convert(int i_p);
	void convert(float f_p);
	void setExtInfo(std::string s_p);
	void setOutput(int i_p);
	static const int beepNumber = 1;
	static const int consoleNumber = 2;
	static const int discNumber = 3;
private:
	morse* m_m;
	std::string extInfo;

};

#endif