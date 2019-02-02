#pragma once
#include "IGui.h"

class DockSpaceGui : public IGui
{
private:
	bool _showSettings = true;
public:
	void Render() override;
};
