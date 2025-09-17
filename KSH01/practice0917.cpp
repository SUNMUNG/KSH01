#include "practice0917.h"
#include "Tiger.h"
#include "Eagle.h"
#include "Whale.h"
#include "Horse.h"
#include "Shape.h"

void practice0917::TestPolymorphism()
{
	Tiger* ptiger = new Tiger("호랑이");
	Eagle* peagle = new Eagle("독수리");
	printf("호랑이 이동\n");
	ptiger->Move();
	printf("독수리 이동\n");
	peagle->Move();

	printf("동물 이동\n");
	Animal* pAnimal = ptiger;
	pAnimal->Move();

	// C 스타일 캐스팅(위험)
	//Tiger* pTempTiger = (Tiger*)pAnimal;
	//pTempTiger->Hunt();
	//((Tiger*)pAnimal)->Hunt();
	// 
	Tiger* pTempTiger = dynamic_cast<Tiger*>(pAnimal);
	// 
	// pAnimal->Hunt(); // 사용 불가능

	delete pTempTiger;
	pTempTiger = nullptr;
	
	delete pAnimal;
	pAnimal = nullptr;

	delete peagle;
	peagle = nullptr;

	delete ptiger;
	ptiger = nullptr;

}

void practice0917::TestPractice1()
{
	Animal* pAnimal[4];

	pAnimal[0] = new Tiger("호랑이");
	pAnimal[1] = new Whale("고래");
	pAnimal[2] = new Horse("말");
	pAnimal[3] = new Eagle("독수리");

	//dynamic_cast<Tiger*>(pAnimal[0])->Hunt();
	//dynamic_cast<Whale*>(pAnimal[1])->Swim();
	//dynamic_cast<Horse*>(pAnimal[2])->Ride();
	//dynamic_cast<Eagle*>(pAnimal[3])->Fly();
	
	for (int i = 0; i < 4; i++)
	{
		pAnimal[i]->MakeSound();
		pAnimal[i]->Move();
	}
	
	for (int i = 0; i < 4; i++) {
		delete pAnimal[i];
		pAnimal[i] = nullptr;
	}
}

void practice0917::TestAbstractClass()
{
	//Shape* pShape = new Shape();

	enum class Color2
	{
		Red = 0,
		Green,
		Blue
	};
	enum class Fruit2
	{
		Apple = 0,
		Orange,
		Banana
	};
	Color2 myColor2 = Color2::Red;
	Color2 myColor3 = Color2::Green;
	Fruit2 myFruit2 = Fruit2::Apple;
	if (myColor2 == myColor3)
	{
	}
	PlayerState state = PlayerState::None;
	state = static_cast<PlayerState>(static_cast<int>(state) | static_cast<int>(PlayerState::OnGround));
	state = state | PlayerState::OnGround;
	state = state & PlayerState::OnGround;
	state |= PlayerState::OnGround;
	state &= PlayerState::OnGround;
}
