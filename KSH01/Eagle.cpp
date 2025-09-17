#include "Eagle.h"

void Eagle::Fly()
{
	printf("%s : ÇÏ´ÃÀ» ³³´Ï´Ù.\n",name.c_str());
	SetEnergy(Energy - 0.3f);
	printf("----------------------------\n");
}

void Eagle::Move() {
	//Animal::Move();
	printf("µ¶¼ö¸®°¡ ³¯¾Æ´Ù´Õ´Ï´Ù .\n");
}

void Eagle::MakeSound()
{
	printf("³£\n");
	Animal::MakeSound();
}
