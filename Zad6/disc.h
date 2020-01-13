#ifndef disc_h
#define disc_h
#include"morse.h"
#include"fstream"

class disc: public morse
{
	friend class factory;
private:
	disc();
	disc(const disc& b_p);
	disc& operator=(const disc& b_p);
	~disc();
	void makeDot();
	void makeDash();
	void makeSpace();
	void convert(std::string s_p, std::string extInfo);
	void convert(int i_p, std::string extInfo);
	void convert(float f_p, std::string extInfo);
	void setFromInfo(std::string info_p);

	std::ofstream plik;
};

#endif
