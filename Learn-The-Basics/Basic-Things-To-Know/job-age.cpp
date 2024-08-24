/*
if age < 18 then not eligible for job
if age >= 18 then eligile for job
if 50 <= age <=59 then eligible but retiring sooon
if age>59 then not eligible*/

#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;
    if (age < 18)
    {
        cout << "You're not eligible for a job yet.";
    }
    else if (age < 59)
    {
        cout << "You're eligible for a job. \n";
        if (age >= 50)
        {
            cout << "However, you're reaching our retirement age soon.";
        }
    }
    else
    {
        cout << "You're past our retirement age.";
    }

    return 0;
}