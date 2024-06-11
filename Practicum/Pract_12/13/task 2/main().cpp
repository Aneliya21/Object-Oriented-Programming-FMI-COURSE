#include <iostream>
#include "Company.h"

int main()
{
    Company c(5);
    
    Worker w("worker", 24, 5000.0, 4);
    Trainee t("trainee", 23, 3400.4, 120);
    PaidTrainee p("paid trainee", 34, 4000.2, 5, 54, 3.4);

    c.addWorker(w);
    c.addTrainee(t);
    c.addPaidTrainee(p);
    c.addTrainee(t);
    c.addPaidTrainee(p);
    c.addWorker(w);
    c.addPaidTrainee(p);

    c.printAll();
}