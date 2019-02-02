#pragma once
#include <algorithm>
#include <vector>
#include <memory>
#include "IMutator.h"

class IMutable
{
protected:
	std::vector<std::shared_ptr<IMutator>> _mutators{};

public:
	virtual ~IMutable() = default;

	virtual void Attach(const std::shared_ptr<IMutator>& mutator)
	{
		_mutators.push_back(mutator);
	}

	virtual void TryDetach()
	{
		_mutators.erase(
			std::remove_if(_mutators.begin(), _mutators.end(), [&](std::shared_ptr<IMutator> mutator)
			{
				const bool canDetach = mutator->CanDetach();
				if (canDetach)
				{
					mutator->OnDetach();
				}
				return canDetach;
			}), _mutators.end());
	}

	virtual void Mutate()
	{
		for (auto&& mutator : _mutators)
		{
			mutator->Apply();
		}
	}
};
