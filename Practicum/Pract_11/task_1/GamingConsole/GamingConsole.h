#pragma once

#include "Computer.h"

class GamingConsole : public Computer {

public:
	void print_computer_type() const override;
	void print_perifer_devices() const override;
};
