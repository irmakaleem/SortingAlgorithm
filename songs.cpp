#include <iostream>
using namespace std;
int main()
{
    // Initialize music collection
    int music_collection[] = {2005, 2005, 2005, 2008, 2008, 2012, 2012, 2012, 2012, 2015, 2015, 2015, 2018, 2019, 2019};

    // Count the number of songs in each year
    int counts[19] = {0}; // Initialize array of counts to 0
    for (int i = 0; i < 15; i++)
    {
        counts[music_collection[i] - 2001]++;
    }

    // Find the year with the highest and lowest number of songs
    int max_count = 0, max_year = 0, min_count = 15, min_year = 0;
    for (int i = 0; i < 19; i++)
    {
        if (counts[i] > max_count)
        {
            max_count = counts[i];
            max_year = i + 2001;
        }
        if (counts[i] < min_count && counts[i] > 0)
        {
            min_count = counts[i];
            min_year = i + 2001;
        }
    }

    // Print the results
    cout << "Year\tNumber of Songs\n";
    for (int i = 0; i < 19; i++)
    {
        if (counts[i] > 0)
        {
            cout << i + 2001 << "\t" << counts[i] << "\n";
        }
    }
    cout << "Year with the most songs: " << max_year << " (" << max_count << " songs)\n";
    cout << "Year with the fewest songs: " << min_year << " (" << min_count << " songs)\n";

    return 0;
}
