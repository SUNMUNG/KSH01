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
	/*Car car = Car("��������");
	car.Accel();

	Car* pcar = new Car("���� �Ҵ�");
	pcar->Accel();
	delete pcar;
	pcar = nullptr;*/

	Animal panda = Animal("�Ǵ�",1.0f,1);
	panda.Eat();
	panda.MakeSound();
	panda.Move();
	panda.Sleep();
	panda.ShowInfo();


	
}
