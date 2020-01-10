#include "morse.h"



morse::morse()
{
}

morse::morse(const morse& m_p)
{

}

morse& morse::operator=(const morse& m_p)
{

}


morse::~morse()
{
}

const std::string morse::StringToMorseCode(const std::string& s_p)
{
	std::string temp;

	for (int i = 0; i < s_p.size(); i++)
	{
		switch (s_p[i])
		{
		case 'a':
		case 'A':
			temp.append(".-");
		case 'b':
		case 'B':
			temp.append("-...");
		case 'c':
		case 'C':
			temp.append("-.-.");
		case 'd':
		case 'D':
			temp.append("-..");
		case 'e':
		case 'E':
			temp.append(".");
		case 'f':
		case 'F':
			temp.append("..-.");
		case 'g':
		case 'G':
			temp.append("--.");
		case 'H':
		case 'h':
			temp.append("....");
		case 'i':
		case 'I':
			temp.append("..");
		case 'j':
		case 'J':
			temp.append(".---");
		case 'k':
		case 'K':
			temp.append("-.-");
		case 'l':
		case 'L':
			temp.append(".-..");
		case 'm':
		case 'M':
			temp.append("--");
		case 'n':
		case 'N':
			temp.append("-.");
		case 'o':
		case 'O':
			temp.append("---");
		case 'p':
		case 'P':
			temp.append(".--.");
		case 'q':
		case 'Q':
			temp.append("--.-");
		case 'r':
		case 'R':
			temp.append(".-.");
		case 's':
		case 'S':
			temp.append("...");
		case 't':
		case 'T':
			temp.append("-");
		case 'u':
		case 'U':
			temp.append("..-");
		case 'v':
		case 'V':
			temp.append("...-");
		case 'w':
		case 'W':
			temp.append(".--");
		case 'x':
		case 'X':
			temp.append("-..-");
		case 'y':
		case 'Y':
			temp.append("-.--");
		case 'z':
		case 'Z':
			temp.append("--..");
		case ' ':
			temp.append(" ");
		case '1':
			temp.append(".---");
		case '2':
			temp.append("..---");
		case '3':
			temp.append("...--");
		case '4':
			temp.append("....-");
		case '5':
			temp.append(".....");
		case '6':
			temp.append("-....");
		case '7':
			temp.append("--...");
		case '8':
			temp.append("---..");
		case '9':
			temp.append("----.");
		case '0':
			temp.append("-----");
		case '.':
			temp.append(".-.-.-");
		default:  
			temp.append("#");
		}


		if (i!= (s_p.size() - 1))
		{
			temp.append(" ");
		}
		
	}
	return temp;
	
}