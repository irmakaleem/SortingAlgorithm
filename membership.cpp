#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to perform linear search
int linear_search(string arr[], int n, string key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// Function to perform binary search
int binary_search(string arr[], int l, int r, string key)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] > key)
        {
            return binary_search(arr, l, mid - 1, key);
        }

        return binary_search(arr, mid + 1, r, key);
    }

    return -1;
}

int main()
{
    const int N1 = 1000;
    const int N2 = 10000;

    string *arr1 = new string[N1];
    string *arr2 = new string[N2];

    // Open the membership file
    ifstream file("membership.txt");

    // Read the names from the file
    for (int i = 0; i < N2; i++)
    {
        string name;
        string phone_number;
        file >> name >> phone_number;

        if (i < N1)
        {
            arr1[i] = name;
        }

        arr2[i] = name;
    }

    file.close();

    // Test the linear search algorithm
    string key = "Elena";
    auto start = high_resolution_clock::now();
    int index = linear_search(arr2, N2, key);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if (index != -1)
    {
        cout << "Found " << key << " at index " << index << " using linear search algorithm" << endl;
    }
    else
    {
        cout << "Could not find " << key << " using linear search algorithm" << endl;
    }

    cout << "Time taken for linear search algorithm with " << N2 << " elements: " << duration.count() << " microseconds" << endl;

    // Test the binary search algorithm
    key = "Elena";
    start = high_resolution_clock::now();
    index = binary_search(arr2, 0, N2 - 1, key);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    if (index != -1)
    {
        cout << "Found " << key << " at index " << index << " using binary search algorithm" << endl;
    }
    else
    {
        cout << "Could not find " << key << " using binary search algorithm" << endl;
    }

    cout << "Time taken for binary search algorithm with " << N2 << " elements: " << duration.count() << " microseconds" << endl;

    delete[] arr1;
    delete[] arr2;

    return 0;
}
