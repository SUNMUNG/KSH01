#include <crtdbg.h>
#include <stdio.h>
#include <cstring>
#include <random>
#include <string>
#include <iostream>
#include "practice0916.h"
#include "Car.h"
#include "Animal.h"


//Practice0916::Practice0916()
//{
//}
//
//Practice0916::~Practice0916()
//{
//}

void Practice0916::ClassInstance()
{
	/*Car car = Car("지역변수");
	car.Accel();

	Car* pcar = new Car("동적 할당");
	pcar->Accel();
	delete pcar;
	pcar = nullptr;*/

	Animal panda = Animal("판다",1.0f,1);
	panda.Eat();
	panda.MakeSound();
	panda.Move();
	panda.Sleep();
	panda.ShowInfo();


	
}
