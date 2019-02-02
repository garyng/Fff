#include "pch.h"
#include "NullMutator.h"

void NullMutator::Apply()
{
}

bool NullMutator::CanDetach()
{
	return false;
}
