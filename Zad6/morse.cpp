/*
		Klasa "morse"
		plik .cpp
		Autor: Micha³ ¯uchowski
*/


#include "morse.h"



morse::morse()
{
	//EMPTY
}

morse::morse(const morse& m_p)
{
	//EMPTY
}

morse& morse::operator=(const morse& m_p)
{
	return *this;
}


morse::~morse()
{
	//EMPTY
}

const std::string morse::ToMorseCode(const std::string& s_p)
{
	std::string temp;

	for (int i = 0; i < s_p.size(); i++)
	{
		switch (s_p[i])
		{
		case 'a':
		case 'A':
			temp.append(".-");
			break;
		case 'b':
		case 'B':
			temp.append("-...");
			break;
		case 'c':
		case 'C':
			temp.append("-.-.");
			break;
		case 'd':
		case 'D':
			temp.append("-..");
			break;
		case 'e':
		case 'E':
			temp.append(".");
			break;
		case 'f':
		case 'F':
			temp.append("..-.");
			break;
		case 'g':
		case 'G':
			temp.append("--.");
			break;
		case 'H':
		case 'h':
			temp.append("....");
			break;
		case 'i':
		case 'I':
			temp.append("..");
			break;
		case 'j':
		case 'J':
			temp.append(".---");
			break;
		case 'k':
		case 'K':
			temp.append("-.-");
			break;
		case 'l':
		case 'L':
			temp.append(".-..");
			break;
		case 'm':
		case 'M':
			temp.append("--");
			break;
		case 'n':
		case 'N':
			temp.append("-.");
			break;
		case 'o':
		case 'O':
			temp.append("---");
			break;
		case 'p':
		case 'P':
			temp.append(".--.");
			break;
		case 'q':
		case 'Q':
			temp.append("--.-");
			break;
		case 'r':
		case 'R':
			temp.append(".-.");
			break;
		case 's':
		case 'S':
			temp.append("...");
			break;
		case 't':
		case 'T':
			temp.append("-");
			break;
		case 'u':
		case 'U':
			temp.append("..-");
			break;
		case 'v':
		case 'V':
			temp.append("...-");
			break;
		case 'w':
		case 'W':
			temp.append(".--");
			break;
		case 'x':
		case 'X':
			temp.append("-..-");
			break;
		case 'y':
		case 'Y':
			temp.append("-.--");
			break;
		case 'z':
		case 'Z':
			temp.append("--..");
			break;
		case ' ':
			temp.append(" ");
			break;
		case '1':
			temp.append(".---");
			break;
		case '2':
			temp.append("..---");
			break;
		case '3':
			temp.append("...--");
			break;
		case '4':
			temp.append("....-");
			break;
		case '5':
			temp.append(".....");
			break;
		case '6':
			temp.append("-....");
			break;
		case '7':
			temp.append("--...");
			break;
		case '8':
			temp.append("---..");
			break;
		case '9':
			temp.append("----.");
			break;
		case '0':
			temp.append("-----");
			break;
		case '.':
			temp.append(".-.-.-");
			break;
		default:  
			temp.append("#");
			break;
		}


		if (i!= (s_p.size() - 1))
		{
			temp.append(" ");
		}
		
	}
	//nie zwracam referencji poniewaz obiekt temp jest utworzony w funcji i
	//i zostanie zniszczony po wyjsciu z metody
	return temp;
	
}
