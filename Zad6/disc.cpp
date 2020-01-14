#include "disc.h"



disc::disc() : morse()
{

}

disc::disc(const disc& b_p): morse(b_p)
{
	
}

disc& disc::operator=(const disc& b_p)
{
	if (this != &b_p)
	{
		morse::operator=(b_p);
	}

	return *this;
}

disc::~disc()
{

}

void disc::makeDot()
{
	plik << ".";
}

void disc::makeDash()
{
	plik << "-";
}

void disc::makeSpace()
{
	plik << " ";
}

void disc::convert(std::string s_p, std::string extInfo)
{
	setFromInfo(extInfo);
	std::string temp = ToMorseCode(s_p);

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '-')
		{
			makeDash();

		}
		else if (temp[i] == '.')
		{
			makeDot();

		}
		else
		{
			makeSpace();
		}

	}
	std::cout << std::endl;
}



void disc::convert(int i_p, std::string extInfo)
{
	setFromInfo(extInfo);
	plik.open(fileName);
	std::string temp = ToMorseCode(std::to_string(i_p));

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '-')
		{
			makeDash();

		}
		else if (temp[i] == '.')
		{
			makeDot();

		}
		else
		{
			makeSpace();
		}

	}
	std::cout << std::endl;
}

void disc::convert(float f_p, std::string extInfo)
{
	setFromInfo(extInfo);
	std::string temp = ToMorseCode(std::to_string(f_p));

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '-')
		{
			makeDash();

		}
		else if (temp[i] == '.')
		{
			makeDot();

		}
		else
		{
			makeSpace();
		}

	}
	std::cout << std::endl;
}

void disc::setFromInfo(std::string info_p)
{
	fileName = info_p;
}

morse* disc::clone() const
{
	return (new disc(*this));
}


const std::vector<std::string> disc::getCurrentSetup() const
{
	std::vector<std::string> CurrentSetup;
	CurrentSetup.push_back(fileName);
	return CurrentSetup;
}