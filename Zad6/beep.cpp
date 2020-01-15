#include "beep.h"



beep::beep(): morse()
{
	m_frequency = 3200;
	m_dotTime = 50;
	m_dashTime = 100;
	m_pause = 100;
	m_spacePause = 200;
	m_charPause = 20;
}

beep::beep(const beep& b_p): morse(b_p)
{
	m_frequency = b_p.m_frequency;
	m_dotTime = b_p.m_dotTime;
	m_dashTime = b_p.m_dashTime;
	m_pause = b_p.m_pause;
	m_spacePause = b_p.m_spacePause;
	m_charPause = b_p.m_charPause;
}

beep& beep::operator=(const beep& b_p)
{
	if (this != &b_p)
	{
		morse::operator=(b_p);
		m_frequency = b_p.m_frequency;
		m_dotTime = b_p.m_dotTime;
		m_dashTime = b_p.m_dashTime;
		m_pause = b_p.m_pause;
		m_spacePause = b_p.m_spacePause;
		m_charPause = b_p.m_charPause;
	}
	
	return *this;
}

beep::~beep()
{
}

void beep::makeDot()
{
	Beep(m_frequency, m_dotTime);
}

void beep::makeDash()
{
	Beep(m_frequency, m_dashTime);
}

void beep::makeSpace()
{
	Sleep(m_spacePause);
}


void beep::convert(std::string s_p, std::string extInfo)
{
	setFromInfo(extInfo);
	std::string temp = ToMorseCode(s_p);

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '-')
		{
			makeDash();
			Sleep(m_pause);
		}
		else if (temp[i] == '.')
		{
			makeDot();
			Sleep(m_pause);
		}
		else
		{
			makeSpace();
		}
		Sleep(m_charPause);
	}
}



void beep::convert(int i_p, std::string extInfo)
{
	setFromInfo(extInfo);
	std::string temp = ToMorseCode(std::to_string(i_p));

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '-')
		{
			makeDash();
			Sleep(m_pause);
		}
		else if (temp[i] == '.')
		{
			makeDot();
			Sleep(m_pause);
		}
		else
		{
			makeSpace();
		}
		Sleep(m_charPause);
	}
}

void beep::convert(float f_p, std::string extInfo)
{
	setFromInfo(extInfo);
	std::string temp = ToMorseCode(std::to_string(f_p));

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '-')
		{
			makeDash();
			Sleep(m_pause);
		}
		else if (temp[i] == '.')
		{
			makeDot();
			Sleep(m_pause);
		}
		else
		{
			makeSpace();
		}
		Sleep(m_charPause);
	}
}

void beep::setFromInfo(std::string info_p)
{
	//zreyzygnowa³em z u¿ywania wyj¹tków poniewa¿ program nie wywraca siê
	//po podaniu blednych argumentow
	//je¿eli argument bêdzie b³edny strumien ustawi wartosc aktualnej zmiennej=0 i zablokuje siê
	std::istringstream streamFromString(info_p);
	streamFromString >> m_frequency;
	streamFromString >> m_dotTime;
	streamFromString >> m_dashTime;
	streamFromString >> m_pause;
	streamFromString >> m_spacePause;
	streamFromString >> m_charPause;
}

morse* beep::clone() const
{
	return (new beep(*this));
}

const std::vector<std::string> beep::getCurrentSetup() const
{
	
	std::vector<std::string> CurrentSetup;
	CurrentSetup.push_back(std::to_string(m_frequency));
	CurrentSetup.push_back(std::to_string(m_dotTime));
	CurrentSetup.push_back(std::to_string(m_dashTime));
	CurrentSetup.push_back(std::to_string(m_pause));
	CurrentSetup.push_back(std::to_string(m_spacePause));
	CurrentSetup.push_back(std::to_string(m_charPause));

	return CurrentSetup;
}