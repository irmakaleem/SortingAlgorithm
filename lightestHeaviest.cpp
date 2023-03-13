#include <iostream>
using namespace std;
void BubbleSort(int a[])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < (15 - i - i); j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int arr[15] = {35, 20, 10, 25, 30, 35, 15, 07, 16, 15, 45, 50, 14, 22, 33};
    cout << "Before Arranging Lightest to Heaviest  " << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << " ";
    }
    BubbleSort(arr);

    cout << endl
         << "After Arranging Lightest to Heaviest  " << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
