#include<iostream>
#include"factory.h"

int main()
{
	factory f1;

	f1.setExtInfo("3200 50 100 200 100 10");
	f1.convert("ala");
	f1.setOutput(factory::consoleNumber);
	f1.convert("ala");
	f1.setOutput(factory::discNumber);
	f1.setExtInfo("abba.txt");
	f1.convert("mamma mia");

	f1.setOutput(factory::blinkNumber);
	f1.setExtInfo("300 600 1000");
	f1.convert(123);
	

	system("pause");
	return 0;
}