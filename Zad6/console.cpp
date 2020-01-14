#include "console.h"



console::console(): morse()
{

}

console::console(const console& b_p): morse(b_p)
{

}


console& console::operator=(const console& b_p)
{
	if (this != &b_p)
	{
		morse::operator=(b_p);
	}

	return *this;
}

console::~console()
{

}

void console::makeDot()
{
	std::cout << ".";
}

void console::makeDash()
{
	std::cout << "-";
}

void console::makeSpace()
{
	std::cout << " ";
}


void console::convert(std::string s_p, std::string extInfo)
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



void console::convert(int i_p, std::string extInfo)
{
	setFromInfo(extInfo);
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

void console::convert(float f_p, std::string extInfo)
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

void console::setFromInfo(std::string info_p)
{
	//EMPTY
}

morse* console::clone() const
{
	return (new console(*this));
}

const std::vector<std::string> console::getCurrentSetup() const
{
	std::vector<std::string> CurrentSetup;
	return CurrentSetup;
}