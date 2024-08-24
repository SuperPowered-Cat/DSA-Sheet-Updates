#include <iostream>
using namespace std;

void rev(int arr[], int a, int b)
{

    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;

    if (!(a <= b))
    {
        rev(arr, a + 1, a - 1);
    }
}

int main()
{
    cout << "Enter the size of the array: " << endl;
    int n;
    cin >> n;
    int A[n];
    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " ";
        cin >> A[i];
    }

    cout << "Original array: " << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    rev(A, 0, n - 1);
    cout << "Reversed array: " << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}