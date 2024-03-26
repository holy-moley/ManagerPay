#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
class Manager : public Employee {
private: 
double managerBonus;
public:
double calcPay();
Manager(string n, double w, double h, double b); //Constructor, n = name, w = wage, h = hours, b = bonus.
Manager (); //Default constructor. 
double getBonus() const;
};
#endif