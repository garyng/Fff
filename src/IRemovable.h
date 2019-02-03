#pragma once

class IRemovable
{
protected:
	bool _canRemove = false;
public:
	virtual bool CanRemove() const { return _canRemove; }
	virtual void CanRemove(bool value) { _canRemove = value; }
};
