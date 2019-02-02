#pragma once
#include "IMutator.h"

class NullMutator : public IMutator
{
public:
	void Apply() override;
	bool CanDetach() override;
};
