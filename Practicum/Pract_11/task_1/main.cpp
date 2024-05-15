#include "Computer.h"
#include "pc.h"
#include "Laptop.h"
#include "GamingConsole.h"

int main()
{
    Computer** computers = new Computer * [5];

    computers[0] = new Laptop();
    computers[1] = new PC();
    computers[2] = new Laptop();
    computers[3] = new GamingConsole();
    computers[4] = new PC();

    for (int i = 0; i < 5; i++) {
        computers[i]->print_computer_type();
        computers[i]->print_perifer_devices();
        std::cout << std::endl;
    }

    for (int i = 0; i < 5; i++) {
        delete computers[i];
    }

    delete[] computers;
}