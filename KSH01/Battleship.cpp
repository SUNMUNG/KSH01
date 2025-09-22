#include "Battleship.h"

bool Battleship::SunkCheck()
{
	if (this->HP <= 0) {
		return true;
	}
	else {
		return false;
	}
}
