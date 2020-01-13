#include "factory.h"



factory::factory()
{
	m_m = new beep();
}

factory::factory(const factory& f_p)
{
	m_m = nullptr;
	*m_m = *f_p.m_m;
	extInfo = f_p.extInfo;

}

factory& factory::operator=(const factory& f_p)
{
	if (this != &f_p)
	{
		m_m = nullptr;
		*m_m = *f_p.m_m;
		extInfo = f_p.extInfo;
	}
	return *this;
}

factory::~factory()
{
	delete m_m;
}

void factory::convert(std::string s_p)
{
	m_m->convert(s_p, extInfo);
}

void factory::convert(int i_p)
{
	m_m->convert(i_p, extInfo);
}

void factory::convert(float f_p)
{
	m_m->convert(f_p, extInfo);
}

void factory::setExtInfo(std::string s_p)
{
	extInfo = s_p;
}

void factory::setOutput(int i_p)
{
	delete m_m;
	
	if (i_p == factory::beepNumber)
	{
		m_m = new beep();
	}
	else if (i_p == factory::consoleNumber)
	{
		m_m = new console();
	}
	else if (i_p == factory::discNumber)
	{
		m_m = new disc();
	}
	else if(i_p == factory::blinkNumber)//kolejnosc pozmieniac w razie danych zlych
	{
		m_m = new blink();
	}
}