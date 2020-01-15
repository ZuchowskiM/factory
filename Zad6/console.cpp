/*
		Klasa "console"
		plik .cpp
		Autor: Micha� �uchowski
*/


#include "console.h"



console::console(): morse()
{
	//EMPTY
}

console::console(const console& b_p): morse(b_p)
{
	//EMPTY
}


console& console::operator=(const console& b_p)
{
	if (this != &b_p)
	{
		//mimo �e operator= morse nic nie robi to wywo�uje go dla porz�dku i nawyku
		morse::operator=(b_p);
	}

	return *this;
}

console::~console()
{
	//EMPTY
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
	//ustalamy informacje 
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
	//zwracamy now� instancj� obiektu stworzon� na bazie obecnego za pomoc� konst. kopiuj�cego
	return (new console(*this));
}

const std::vector<std::string> console::getCurrentSetup() const
{
	//tutaj setup b�dzie akurat pusty
	std::vector<std::string> CurrentSetup;
	return CurrentSetup;
}