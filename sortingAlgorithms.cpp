#include <iostream>
using namespace std;

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
void Bubblesort(int A[], int n)
{
    int numPasses = 0;
    for (int pass = 0; pass < n - 1; pass++)
    {

        for (int c = 0; c < (n - pass - 1); c++)
        {
            if (A[c] > A[c + 1])
            {
                swap(A[c], A[c + 1]);
            }
            numPasses++;
            printArray(A, n);
        }
    }
    cout << "Bubble Sort Completed in " << numPasses << " "
         << "passes" << endl;
}
void Selectionsort(int A[], int n)
{
    int numPasses = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
            numPasses++;
            printArray(A, n);
        }
        swap(A[min], A[i]);
    }
    cout << "Selection Sort Completed in " << numPasses << " "
         << "passes" << endl;
}
void Insertionsort(int A[], int n)
{
    int j, numPasses = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        int key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
            numPasses++;
            printArray(A, n);
        }
        A[j + 1] = key;
    }
    cout << "Insertion sort completed in " << numPasses << " "
         << " passes." << endl;
}
int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    cout << "Original array: ";
    printArray(arr, 10);

    Bubblesort(arr, 10);
    cout << "Bubble sorted array: ";
    printArray(arr, 10);

    Insertionsort(arr, 10);
    cout << "Insertion sorted array: ";
    printArray(arr, 10);

    Selectionsort(arr, 10);
    cout << "Selection sorted array: ";
    printArray(arr, 10);

    return 0;
}