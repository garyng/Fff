#pragma once
#include "IMutator.h"
#include "objects/player/Player.h"

class PlayerKeyboardMutator : public IMutator
{
private:
	std::shared_ptr<Player> _player{};
public:
	void Apply() override;

	bool CanDetach() override;

	void OnInit() override;
};
