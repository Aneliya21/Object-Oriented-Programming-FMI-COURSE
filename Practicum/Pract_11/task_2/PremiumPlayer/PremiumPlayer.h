#pragma once
#include "Player.h"

class PremiumPlayer : public Player {

public:
	PremiumPlayer(const char* name);
	PremiumPlayer(const PremiumPlayer& other);
	PremiumPlayer(PremiumPlayer&& other) noexcept;

	PremiumPlayer& operator=(const PremiumPlayer& other);
	PremiumPlayer& operator=(PremiumPlayer&& other) noexcept;

	bool levelUp() override;

	~PremiumPlayer();

protected:
	void setName(const char* newName);

private:
	void copyFrom(const PremiumPlayer& other);
	void moveFrom(PremiumPlayer&& other);
	void free();

	char* name = nullptr;
};

