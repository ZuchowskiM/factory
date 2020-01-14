#include<iostream>
#include"factory.h"

int main()
{
	factory f1;
	
	
	f1.setExtInfo("3200 50 100 200 100 10");
	f1.convert("ala");

	for (int i = 0; i < f1.getCurrentSetup().size(); i++)
	{
		std::cout << f1.getCurrentSetup()[i] << std::endl;
	}

	
	f1.setOutput(factory::consoleNumber);
	f1.convert("ala");
	f1.setOutput(factory::discNumber);
	f1.setExtInfo("abba.txt");
	f1.convert("mamma mia");

	for (int i = 0; i < f1.getCurrentSetup().size(); i++)
	{
		std::cout << f1.getCurrentSetup()[i];
	}
	


	f1.setOutput(factory::blinkNumber);
	f1.setExtInfo("300 600 1000");
	f1.convert(123);

	factory f2(f1);

	f2.convert("ala ma kota");
	f2.setOutput(factory::beepNumber);
	f2.convert("zabson to");
	
	

	system("pause");
	return 0;
}