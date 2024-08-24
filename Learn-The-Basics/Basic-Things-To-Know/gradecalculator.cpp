/*
Marks System:-
90+: O
80-89: E
70-79: A
60-69: B
50-59: C
40-49: D
*/

#include <iostream>
using namespace std;
int main()
{

    int marks;
    cout << "Enter your marks: ";
    cin >> marks;
    if (marks >= 90)
    {
        cout << "O grade!";
    }
    else if (marks <= 89 && marks >= 80)
    {
        cout << "E grade!";
    }
    else if (marks <= 79 && marks >= 70)
    {
        cout << "A grade!";
    }
    else if (marks <= 69 && marks >= 60)
    {
        cout << "B grade.";
    }
    else if (marks <= 59 && marks >= 50)
    {
        cout << "C grade.";
    }
    else if (marks <= 49 && marks >= 40)
    {
        cout << "D grade.";
    }
    else
    {
        cout << "You have failed.";
    }
    return 0;
}