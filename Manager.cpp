#include "Manager.h"
#include "Employee.h"
#include <string>
using namespace std;

Manager :: Manager(string n, double w, double h, double b) : Employee (n, w, h) // Calls the base class constructor, initialized with name, wage, and hours, then assigns the bonus.
{
managerBonus = b;
}
Manager :: Manager() : Employee ("", 0, 0){
    managerBonus=0;
}

double Manager :: calcPay(){
double pay = Employee::calcPay(); // Calls the calcPay function from the Employee.cpp file, then adds a bonus to the result. 
pay += managerBonus;
return pay;
}

double Manager :: getBonus() const{ //Returns the bonus. Is not used in the program, but it felt wrong not to have the private member variable accessible.
    return managerBonus;
}