#include<iostream>
#include"factory.h"

int main()
{
	factory f1;

	f1.convert("ala");

	for (int i = 0; i < f1.getCurrentSetup().size(); i++)
	{
		std::cout << f1.getCurrentSetup()[i] << std::endl;
	}

	f1.convert(234.0f);
	f1.convert(23);

	f1.setOutput(factory::consoleNumber);
	f1.convert("ala");
	f1.convert(234.0f);
	f1.convert(23);

	f1.setOutput(factory::discNumber);
	f1.setExtInfo("abba.txt");
	f1.convert("mamma mia");

	for (int i = 0; i < f1.getCurrentSetup().size(); i++)
	{
		std::cout << f1.getCurrentSetup()[i] << std::endl;
	}

	f1.setExtInfo("300 600 1000");
    f1.setOutput(factory::blinkNumber);
	f1.convert(77543);

	f1.setExtInfo("");
	f1.setOutput(factory::beepNumber);
	f1.convert("ala");

	std::cout << f1.getExtInfo() << std::endl;

	factory f2(f1);

	f2.setOutput(factory::consoleNumber);
	f2.convert("ala ma kota");
	f2.setExtInfo("3200 50 100 100 200 20");
	f2.setOutput(factory::beepNumber);
	f2.convert("kot ma ale");
	
	f1 = f2;

	f1.convert("kot ma ale");

	system("pause");
	return 0;
}