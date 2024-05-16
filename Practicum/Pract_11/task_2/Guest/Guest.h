#pragma once
#include "Player.h"
#include "Time.h"

class Guest : public Player {

public:
	Time leftToPlay;

private:
	bool levelUp() override;
};

