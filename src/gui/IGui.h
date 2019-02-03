#pragma once

class IGui
{
public:
	virtual ~IGui() = default;
	virtual void Render() = 0;
};