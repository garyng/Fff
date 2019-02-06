#pragma once
#include "IMutator.h"
#include "objects/ObjectContainer.h"
#include "config/Config.h"

class OnMagnetEffect : public IMutator
{
private:
	std::shared_ptr<ObjectContainer> _objectContainer;
	std::shared_ptr<Config> _config;
	bool _canDetach = false;
public:


	OnMagnetEffect(const std::shared_ptr<ObjectContainer>& objectContainer, const std::shared_ptr<Config>& config)
		: _objectContainer(objectContainer),
		  _config(config)
	{
	}

	void OnInit() override;
	void Apply() override;
	bool CanDetach() override;
};
