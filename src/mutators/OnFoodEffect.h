#pragma once
#include "IMutator.h"
#include "objects/ObjectFactory.h"

class OnFoodEffect : public IMutator
{
private:
	std::shared_ptr<ObjectFactory> _objectFactory;
	std::shared_ptr<IObject> _particle;
public:


	OnFoodEffect(const std::shared_ptr<ObjectFactory>& objectFactory)
		: _objectFactory(objectFactory)
	{
	}

	void Apply() override;

	bool CanDetach() override;
	void OnInit() override;
	void OnDetach() override;
};
