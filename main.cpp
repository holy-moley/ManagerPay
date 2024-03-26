/*
# Author:           Travis Burkhardt
# BannerID:         001398102
# Course:           CS 181
# Assignment:       PA4
# Date Assigned:    Monday, March 18, 2024
# Date/Time Due:    Saturday, March 30, 2024 -- 11:55 pm
# Description:      This program will exercise ObjectOriented concepts with C++.
# Certification of Authenticity:
 I certify that this assignment is entirely my own work.

Note: The Employee.h and Employee.cpp files included here were not my work, as they were provided with the assignment.
I was told not to change them, but the employee.h header file causes massive errors in itself and everything else without using the std namespace, apparently due to the use of strings.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Manager.cpp"
#include "Employee.cpp"
using namespace std;


int main(){
cout << "Enter number of managers: ";
int manCap;
cin >> manCap; //User input for how many managers they want.
cin.ignore();
Manager *ptr;
ptr = new Manager [manCap];

// Prompts the user to create the array. 
for (int i = 0; i<manCap;i++){
    //Variable declaration.
   
    string name;
    double wage;
    double hours;
    double bonus;
    //User input.
    cout << endl << "Enter manager " << i << " name: ";
    getline(cin, name);
    cout << "Enter manager " << i << " hourly wage: ";
    cin >> wage;
    cin.ignore();
    cout << "Enter manager " << i << " hours worked: ";
    cin >> hours;
    cin.ignore();
    cout << "Enter manager " << i << " bonus: ";
    cin >> bonus;
    // Assigns the pointer to a dynamically created Manager object, then assigns the array's 'current' position to that value.
    ptr[i] = Manager {name, wage, hours, bonus};
    cin.ignore();
}

double paySum = 0;
double payAvg;
int maxPay = 0; // Note, this value does not actually indicate the maximum pay, only the index of the worker who has it. 

// Iterates through the loop, adding to the pay sum and checking to see if the current position has the highest pay so far. 
for(int i = 0; i < manCap; i++){
    paySum += ptr[i].calcPay();
    if(ptr[i].calcPay() > maxPay){
        maxPay = i;
    }
}
payAvg = paySum / manCap;
cout << "The manager with the most pay is " << ptr[maxPay].getName() << ", who is paid $" << fixed << setprecision(2) << ptr[maxPay].calcPay() << ".\n" ;
cout << "Average pay is $" << payAvg << ".";
delete[] ptr;
cout << "Press enter to exit the program.";
return 0;
}
