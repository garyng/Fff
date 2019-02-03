#pragma once
#include "IRemovable.h"

class IGui : public IRemovable
{
public:
	virtual ~IGui() = default;
	virtual void Render() = 0;
};
