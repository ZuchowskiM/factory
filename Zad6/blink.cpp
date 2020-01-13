#include "blink.h"



blink::blink(): morse()
{
	dotSleepTime = 300;
	dashSleepTime = 600;
	SpaceSleepTime = 1000;
}

blink::blink(const blink& b_p): morse(b_p)
{
	dotSleepTime = b_p.dotSleepTime;
	dashSleepTime = b_p.dashSleepTime;
	SpaceSleepTime = b_p.SpaceSleepTime;
}

blink& blink::operator=(const blink& b_p)
{
	if (this != &b_p)
	{
		morse::operator=(b_p);
		dotSleepTime = b_p.dotSleepTime;
		dashSleepTime = b_p.dashSleepTime;
		SpaceSleepTime = b_p.SpaceSleepTime;
	}

	return *this;
}

blink::~blink()
{

}


void blink::makeDot()
{
	INPUT in[2];                                //przygotuj strukture na dwa zdarzenia in[0] wcisniecie klawisza
												//in[1] wycisniecie klawisza
	in[0].type = INPUT_KEYBOARD;                //wcisniecie klawisza na klawiaturze
	in[0].ki.wVk = VK_CAPITAL;                    //jaki klawisz - CAPSLOCK
	in[0].ki.wScan = 0;
	in[0].ki.time = 0;
	in[0].ki.dwFlags = 0;                        //jesli 0 to akcja wcisniecia klawisza
	in[0].ki.dwExtraInfo = 0;

	in[1] = in[0];                                //szykujemy strukture na wycisniecie klawisza. Jest taka sama poza
	in[1].ki.dwFlags = KEYEVENTF_KEYUP;            //tym ze teraz wykonujemy akacje wycisniecia klawisza

	for (int i = 0; i < 2; i++)                    // wykonaj 6 razy petle
	{
		::SendInput(2, in, sizeof(INPUT));        // wyslij w kolejke komunikatow 2 zdarzenia opisane strukturami zaczynajacymi
												// sie na wskazniku in.
												// oznacza to symulacje pracy urzytkownika. W naszym przypadku urzytkownik
												// wcisnal a potem wycisnal klawisz CAPSLOCK
												//powoduje to zmiane stanu diody CAPSLOCK
		::Sleep(dotSleepTime);                            // czekamy 300msec zanim pojdziemy dalej
	}
}

void blink::makeDash()
{
	INPUT in[2];                                //przygotuj strukture na dwa zdarzenia in[0] wcisniecie klawisza
												//in[1] wycisniecie klawisza
	in[0].type = INPUT_KEYBOARD;                //wcisniecie klawisza na klawiaturze
	in[0].ki.wVk = VK_CAPITAL;                    //jaki klawisz - CAPSLOCK
	in[0].ki.wScan = 0;
	in[0].ki.time = 0;
	in[0].ki.dwFlags = 0;                        //jesli 0 to akcja wcisniecia klawisza
	in[0].ki.dwExtraInfo = 0;

	in[1] = in[0];                                //szykujemy strukture na wycisniecie klawisza. Jest taka sama poza
	in[1].ki.dwFlags = KEYEVENTF_KEYUP;            //tym ze teraz wykonujemy akacje wycisniecia klawisza

	for (int i = 0; i < 2; i++)                    // wykonaj 6 razy petle
	{
		::SendInput(2, in, sizeof(INPUT));        // wyslij w kolejke komunikatow 2 zdarzenia opisane strukturami zaczynajacymi
												// sie na wskazniku in.
												// oznacza to symulacje pracy urzytkownika. W naszym przypadku urzytkownik
												// wcisnal a potem wycisnal klawisz CAPSLOCK
												//powoduje to zmiane stanu diody CAPSLOCK
		::Sleep(dashSleepTime);                            // czekamy 300msec zanim pojdziemy dalej
	}
}

void blink::makeSpace()
{
	Sleep(SpaceSleepTime);
}

void blink::convert(std::string s_p, std::string extInfo)
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



void blink::convert(int i_p, std::string extInfo)
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

void blink::convert(float f_p, std::string extInfo)
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

void blink::setFromInfo(std::string info_p)
{
	std::istringstream streamFromString(info_p);
	streamFromString >> dotSleepTime;
	streamFromString >> dashSleepTime;
	streamFromString >> SpaceSleepTime;
}