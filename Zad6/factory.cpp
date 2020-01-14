#include "factory.h"
#include<typeinfo>



factory::factory()
{
	m_m = new beep();
}

factory::factory(const factory& f_p)
{
	m_m = nullptr;
	m_m = f_p.m_m->clone();
	extInfo = f_p.extInfo;

}

factory& factory::operator=(const factory& f_p)
{
	if (this != &f_p)
	{
		m_m = nullptr;
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

void factory::setOutput(int i_p)
{
	
	if (i_p == factory::beepNumber)
	{
		delete m_m;
		m_m = new beep();
	}
	else if (i_p == factory::consoleNumber)
	{
		delete m_m;
		m_m = new console();
	}
	else if (i_p == factory::discNumber)
	{
		delete m_m;
		m_m = new disc();
	}
	else if(i_p == factory::blinkNumber)
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