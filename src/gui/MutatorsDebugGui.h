#pragma once
#include "IGui.h"
#include "mutators/IMutator.h"
#include "mutators/MutatorFactory.h"
#include "mutators/OnFoodEffect.h"
#include "objects/player/Player1.h"
#include "mutators/OnLightningStrikeEffect.h"
#include "mutators/OnFreezedEffect.h"
#include "mutators/OnDashingEffect.h"

class MutatorsDebugGui : public IGui
{
private:
	std::shared_ptr<ILogger> _logger;
	std::shared_ptr<MutatorFactory> _mutatorFactory;
public:


	MutatorsDebugGui(const std::shared_ptr<ILogger>& logger, const std::shared_ptr<MutatorFactory>& mutatorFactory)
		: _logger(logger),
		  _mutatorFactory(mutatorFactory)
	{
	}

	void Render() override
	{
		ImGui::BeginDefault("Mutators");
		RenderButton<OnFoodEffect, Player1>();
		RenderButton<OnLightningStrikeEffect, Player1>();
		RenderButton<OnFreezedEffect, Player1>();
		RenderButton<OnDashingEffect, Player1>();
		ImGui::End();
	}

	template <class TMutator, class TObject, class = IsBaseOf<TMutator, IMutator>, class = IsBaseOf<TObject, IObject>>
	void RenderButton()
	{
		std::string name = nameof<TMutator>();
		std::string player = nameof<TObject>();

		if (ImGui::Button(("Attach " + name + " to " + player).c_str()))
		{
			_mutatorFactory->Attach<TMutator, TObject>();
			_logger->Debug("Attached %1% to %2%", {name, player});
		}
	}
};
