#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

int main()
{

    int marks[] = {80, 65, 70, 85, 90, 75, 60, 95, 50, 55, 77, 82, 73, 88, 92, 63, 68, 78, 83, 97, 62, 67, 72, 87, 52, 57, 69, 74, 79, 84, 96, 58, 64, 71, 76, 81, 86, 91, 53, 98, 94};

    // Calculate the size of the array
    int n = sizeof(marks) / sizeof(marks[0]);

    bubbleSort(marks, n);

    cout << "Sorted marks: ";
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }
    cout << endl;

    int search_mark;
    cout << "Enter a mark to search: ";
    cin >> search_mark;

    int search_index = binarySearch(marks, n, search_mark);

    if (search_index == -1)
    {
        cout << "The mark " << search_mark << " was not found." << endl;
    }
    else
    {
        cout << "The mark " << search_mark << " was found at index " << search_index << "." << endl;
    }

    return 0;
}
