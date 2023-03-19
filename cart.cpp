#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Item
{
    string name;
    double price;
};

void display_cart(Item cart[], int item_count)
{
    cout << "Cart items: " << endl;
    for (int i = 0; i < item_count; i++)
    {
        cout << cart[i].name << ": " << cart[i].price << " PKR" << endl;
    }
    cout << endl;
}

int binary_search(Item cart[], int item_count, double target_price)
{
    int start = 0;
    int end = item_count - 1;
    int middle;

    while (start <= end)
    {
        middle = (start + end) / 2;

        if (cart[middle].price == target_price)
        {
            return middle;
        }
        else if (cart[middle].price < target_price)
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }

    return -1;
}

int main()
{
    Item cart[20];
    int item_count = 0;

    while (item_count < 20)
    {
        string name;
        double price;

        cout << "Enter product name: ";
        getline(cin, name);

        cout << "Enter product price: ";
        cin >> price;
        cin.ignore();

        if (item_count == 0)
        {
            cart[item_count] = {name, price};
            item_count++;
        }
        else
        {
            int i = item_count - 1;

            while (i >= 0 && cart[i].price < price)
            {
                cart[i + 1] = cart[i];
                i--;
            }

            cart[i + 1] = {name, price};
            item_count++;
        }

        display_cart(cart, item_count);
    }

    int target_price = 1000;
    int index = binary_search(cart, item_count, target_price);

    if (index == -1)
    {
        cout << "No item found above " << target_price << " PKR." << endl;
    }
    else
    {
        cout << "Item found at index " << index << "." << endl;
    }

    return 0;
}
