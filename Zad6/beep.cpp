#include "beep.h"



beep::beep(): morse()
{
}

beep::beep(const beep& b_p): morse(b_p)
{

}

beep& beep::operator=(const beep& b_p)
{
	morse::operator=(b_p);
	/////nie zapomnij o warunku pamieci/////
}

beep::~beep()
{
}
