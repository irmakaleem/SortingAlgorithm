#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define color options
string colors[5] = {"red", "green", "blue", "yellow", "orange"};

// Define tube array
string tubes[4] = {"", "", "", ""};

// Function to check if the colors are sorted
bool is_sorted()
{
    for (int i = 0; i < 3; i++)
    {
        if (tubes[i] > tubes[i + 1])
        {
            return false;
        }
    }
    return true;
}

// Function to check if the color transfer is valid
bool is_valid_transfer(int source, int dest)
{
    if (tubes[source] == "")
    {
        return false;
    }
    if (tubes[dest] == "")
    {
        return true;
    }
    if (tubes[source] == tubes[dest])
    {
        return true;
    }
    return false;
}

// Function to transfer a color between tubes
void transfer_color(int source, int dest)
{
    tubes[dest] = tubes[source];
    tubes[source] = "";
}

// Main function for the game
int main()
{
    std::cout << "\033[31mRed text\033[0m" << std::endl;    // red text
    std::cout << "\033[32mGreen text\033[0m" << std::endl;  // green text
    std::cout << "\033[33mYellow text\033[0m" << std::endl; // yellow text
    std::cout << "\033[34mBlue text\033[0m" << std::endl;   // blue text

    // Initialize random seed
    srand(time(NULL));

    // Randomly select three colors
    string color1 = colors[rand() % 5];
    string color2 = colors[rand() % 5];
    string color3 = colors[rand() % 5];

    // Assign colors to test tubes
    int tube1 = rand() % 4;
    int tube2 = rand() % 4;
    int tube3 = rand() % 4;

    // Make sure all tubes have at least one color
    while (tube1 == tube2 || tube1 == tube3 || tube2 == tube3)
    {
        tube1 = rand() % 4;
        tube2 = rand() % 4;
        tube3 = rand() % 4;
    }

    tubes[tube1] = color1;
    tubes[tube2] = color2;
    tubes[tube3] = color3;

    // Print out initial tube setup
    cout << "Initial tube setup: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Tube " << i + 1 << ": " << tubes[i] << endl;
    }

    // Player turn loop
    int source, dest;
    while (!is_sorted())
    {
        // Get source and destination tubes from player
        cout << "Enter source tube (1-4): ";
        cin >> source;
        cout << "Enter destination tube (1-4): ";
        cin >> dest;

        // Check if transfer is valid and transfer color
        if (is_valid_transfer(source - 1, dest - 1))
        {
            transfer_color(source - 1, dest - 1);
        }
        else
        {
            cout << "Invalid transfer." << endl;
        }

        // Print out updated tube setup
        for (int i = 0; i < 4; i++)
        {
            cout << "Tube " << i + 1 << ": " << tubes[i] << endl;
        }
    }

    // Game over
    cout << "Congratulations, you sorted the colors!" << endl;

    return 0;
}