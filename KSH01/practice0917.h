#pragma once
#include <stdint.h>
#include <type_traits>
class practice0917
{
public:
	void TestPolymorphism();

	void TestPractice1();

	void TestAbstractClass();
};

enum class PlayerState : uint8_t
{
	None = 0,
	OnGround = 1 << 0,
	Jumping = 1 << 1,
	Stunned = 1 << 2,
	Poisoned = 1 << 3,
	Invisible = 1 << 4,
	Invincible = 1 << 5,
	Flying = 1 << 6
};
using StateType = std::underlying_type_t<PlayerState>;
inline PlayerState operator|(PlayerState Left, PlayerState Right)
{
	return static_cast<PlayerState>(static_cast<StateType>(Left) | static_cast<StateType>(Right));
};
inline PlayerState operator&(PlayerState Left, PlayerState Right)
{
	return static_cast<PlayerState>(static_cast<StateType>(Left) & static_cast<StateType>(Right));
};
inline PlayerState operator~(PlayerState inState)
{
	return static_cast<PlayerState>(~static_cast<StateType>(inState));
};
inline PlayerState& operator|=(PlayerState& Left, PlayerState Right)
{
	Left= Left | Right;
	return Left;
};
inline PlayerState& operator&=(PlayerState& Left, PlayerState Right)
{
	Left = Left & Right;
	return Left;
};
