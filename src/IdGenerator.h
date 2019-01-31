#pragma once
class IdGenerator
{
private:
	unsigned int _next = 0;
public:
	unsigned int Next()
	{
		return _next++;
	}
};