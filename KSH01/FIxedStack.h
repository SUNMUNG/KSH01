#pragma once
class FIxedStack

{
public:

	void Push(int Invalue);

	int Pop();

	int Top();

	inline bool isFull() const {
		return TopIndex == (StackCapacity - 1);
	}
	 
	inline bool isEmpty() const {
		return TopIndex == Empty;
	}
 
	inline int GetSize() const {
		return TopIndex + 1;
	}
private:
	static constexpr int StackCapacity = 10;
	static constexpr int Empty = -1;
	int TopIndex = Empty;
	int Data[StackCapacity];
};
