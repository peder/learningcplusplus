#pragma once
class Sequence
{
private:
	static unsigned int _current;

public:
	Sequence() { }

	unsigned int getNext()
	{
		return (++_current);
	}
};