#ifndef factory_h
#define factory_h
#include"beep.h"
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
	const int beep = 1;


};

#endif