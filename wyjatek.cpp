#include <iostream>
#include <stdexcept>
#include "wyjatek.h"

using namespace std;

const char* blankField::what()const throw()
{
	return "Dbajac o strukture programu prosze nie zostawiać pustych atrybutow obiektow. Zamykanie...";
}
