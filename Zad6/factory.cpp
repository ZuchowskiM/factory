/*
		Klasa "disc"
		plik .cpp
		Autor: Micha³ ¯uchowski
*/

#include "factory.h"



factory::factory()
{
	//domyœlnie tryb dzialania fabryki to beep
	m_m = new beep();
}

factory::factory(const factory& f_p)
{
	m_m = nullptr;

	//tutaj korzystamy z polimorficznego konstruktora kopiuj¹cego
	//bo nie wiemy jaki obiekt aktualnie znajduje sie pod wkaznikiem m_m
	m_m = f_p.m_m->clone();
	//mo¿na to by³o te¿ rozwi¹zaæ dodaj¹c zmienna która mówi w jakim trybie jest obecnie fabryka

	extInfo = f_p.extInfo;

}

factory& factory::operator=(const factory& f_p)
{
	if (this != &f_p)
	{
		delete m_m;
		m_m = f_p.m_m->clone();
		extInfo = f_p.extInfo;
	}
	return *this;
}

factory::~factory()
{
	delete m_m;
}

void factory::convert(std::string s_p) const
{
	//uzna³em ¿e wys³anie kartki i zaaplikowanie jej w linii produkcyjnej
	//bedzie nastepowac dopiero wtedy kiedy ja uruchomimy 
	m_m->convert(s_p, extInfo);
}

void factory::convert(int i_p) const
{
	m_m->convert(i_p, extInfo);
}

void factory::convert(float f_p) const
{
	m_m->convert(f_p, extInfo);
}

void factory::setExtInfo(std::string s_p)
{
	extInfo = s_p;
}

void factory::setOutput(int FactoryOperatingMode)
{
	//uzna³em ¿e jeœli user poda b³êdny argument nie wp³ynie to na jego tryb dzia³ania
	//bo móg³ podaæ dobry
	if (FactoryOperatingMode == factory::beepNumber)
	{
		delete m_m;
		m_m = new beep();
	}
	else if (FactoryOperatingMode == factory::consoleNumber)
	{
		delete m_m;
		m_m = new console();
	}
	else if (FactoryOperatingMode == factory::discNumber)
	{
		delete m_m;
		m_m = new disc();
	}
	else if(FactoryOperatingMode == factory::blinkNumber)
	{
		delete m_m;
		m_m = new blink();
	}
}

const std::string& factory::getExtInfo() const
{
	return extInfo;
}

const std::vector<std::string> factory::getCurrentSetup() const
{
	return (m_m->getCurrentSetup());
}