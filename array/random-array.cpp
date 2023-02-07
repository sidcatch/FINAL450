
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int randomNumber(int min, int max)
{

    float normalized = (float)rand() / RAND_MAX;
    int result = (max - min + 1) * normalized + min;
    return result;
}

int main()
{
    // vector<int> randomNumbers;

    unordered_set<int> uniqueRandomNumbers;

    int min = 1, max = 10;

    srand(time(nullptr));
    for (int i = 0; i < 1000; i++)
    {
        int r = randomNumber(min, max);
        // randomNumbers.push_back(r);
        uniqueRandomNumbers.insert(r);
    }

    // for (int i = 0; i < randomNumbers.size(); i++)
    //     cout << randomNumbers[i] << ", ";
    // cout << endl;

    for (int number : uniqueRandomNumbers)
    {
        cout << number << ", ";
    }

    cout << endl;
    return 0;
}
