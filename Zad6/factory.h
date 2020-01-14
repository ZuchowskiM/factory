#ifndef factory_h
#define factory_h
#include"beep.h"
#include"console.h"
#include "disc.h"
#include "blink.h"

class factory
{
public:
	factory();
	factory(const factory& f_p);
	factory& operator=(const factory& f_p);
	~factory();
	void convert(std::string s_p) const;
	void convert(int i_p) const;
	void convert(float f_p) const;
	void setExtInfo(std::string s_p);
	void setOutput(int i_p);
	static const int beepNumber = 1;
	static const int consoleNumber = 2;
	static const int discNumber = 3;
	static const int blinkNumber = 4;
	const std::string& getExtInfo() const;
	const std::vector<std::string> getCurrentSetup() const;
	

private:
	morse* m_m;
	std::string extInfo;

};

#endif