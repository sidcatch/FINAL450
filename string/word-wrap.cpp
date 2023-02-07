// Given and array of words and line width, fill the lines
// with the words such that sum of squares of number of
// extra spaces in each line is minimum. A twist to this
// questions is not to count the spaces in the last line

#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> words = {"my", "name", "is", "syed", "also", "I", "am", "a", "software", "developer"};

    int width = 15;

    // for (auto s : words)
    // {
    //     cout << s << " ";
    // }

    cout << endl;

    int cost[words.size()][words.size()];

    for (int i = 0; i < words.size(); i++)
    {
        cost[i][i] = width - words[i].length();
        for (int j = i + 1; j < words.size(); j++)
            cost[i][j] = cost[i][j - 1] - words[j].length() - 1; // subtract new word length (and a space) from remaining space from previous calculation
    }

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i; j < words.size(); j++)
        {
            if (cost[i][j] < 0)
                cost[i][j] = INT_MAX;
            else
                cost[i][j] = cost[i][j] * cost[i][j];
        }
    }

    // for (int i = 0; i < words.size(); i++)
    // {
    //     for (int j = 0; j < words.size(); j++)
    //     {
    //         if (i > j)
    //             cout << -1 << "    ";
    //         else if (cost[i][j] == INT_MAX)
    //             cout << -1 << "    ";
    //         else
    //             cout << cost[i][j] << "    ";
    //     }
    //     cout << endl;
    // }

    int *minCost = new int[words.size()];
    int *result = new int[words.size()];
    for (int i = words.size() - 1; i >= 0; i--)
    {
        minCost[i] = cost[i][words.size() - 1];
        result[i] = words.size();
        for (int j = words.size() - 1; j > i; j--)
        {
            if (cost[i][j - 1] == INT_MAX)
                continue;
            if (minCost[i] > minCost[j] + cost[i][j - 1])
            {
                minCost[i] = minCost[j] + cost[i][j - 1];
                result[i] = j;
            }
        }
    }

    cout << "Minimum cost is " << minCost[0];

    cout << endl;

    // for (int i = 0; i < width; i++)
    //     cout << "_";
    // cout << endl;

    int i = 0;
    int j;
    do
    {
        j = result[i];
        for (int k = i; k < j; k++)
            cout << words[k] << " ";
        cout << endl;
        i = j;
    } while (j < words.size());

    // for (int i = 0; i < width; i++)
    //     cout << "_";
    // cout << endl;

    return 0;
}
