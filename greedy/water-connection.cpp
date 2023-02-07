// There are n houses and p water pipes in Geek Colony. Every house has at most one pipe going into it and at most one pipe going out of it. Geek needs to install pairs of tanks and taps in the colony according to the following guidelines.
// 1. Every house with one outgoing pipe but no incoming pipe gets a tank on its roof.
// 2. Every house with only one incoming and no outgoing pipe gets a tap.
// The Geek council has proposed a network of pipes where connections are denoted by three input values: ai, bi, di denoting the pipe of diameter di from house ai to house bi.
// Find a more efficient way for the construction of this network of pipes. Minimize the diameter of pipes wherever possible.
// Note: The generated output will have the following format. The first line will contain t, denoting the total number of pairs of tanks and taps installed. The next t lines contain three integers each: house number of tank, house number of tap, and the minimum diameter of pipe between them.

#include <iostream>
#include <limits.h>
#include <unordered_map>
#include <vector>

using namespace std;

void installTapsAndTanks(int network[][3], int numOfHouses, int numOfPipes)
{
    vector<int> housesInstalledWithTaps;
    vector<int> housesInstalledWithTanks;
    vector<int> minDiametersBtwTapsAndTanks;

    unordered_map<int, int> startingHouses;
    unordered_map<int, int> endingHouses;
    unordered_map<int, int> startingHousesPipeDiameter;

    for (int i = 0; i < numOfPipes; i++)
    {
        startingHouses[network[i][0]] = network[i][1];
        endingHouses[network[i][1]] = network[i][0];
        startingHousesPipeDiameter[network[i][0]] = network[i][2];
    }

    for (int i = 1; i <= numOfHouses; i++)
    {
        if (startingHouses.find(i) != startingHouses.end() && endingHouses.find(i) == endingHouses.end())
        {
            // cout << i << " ";

            housesInstalledWithTaps.push_back(i);
            int minDiameterBtwTapAndTank = startingHousesPipeDiameter[i];

            int j = i;

            while (startingHouses.find(j) != startingHouses.end())
            {
                if (minDiameterBtwTapAndTank > startingHousesPipeDiameter[j])
                    minDiameterBtwTapAndTank = startingHousesPipeDiameter[j];
                j = startingHouses[j];
            }
            housesInstalledWithTanks.push_back(j);
            minDiametersBtwTapsAndTanks.push_back(minDiameterBtwTapAndTank);
            // cout << j << " ";
            // cout << minDiameterBtwTapAndTank << " ";
        }
    }

    cout << housesInstalledWithTaps.size() << endl;
    for (int i = 0; i < housesInstalledWithTaps.size(); i++)
        cout << housesInstalledWithTaps[i] << " " << housesInstalledWithTanks[i] << " " << minDiametersBtwTapsAndTanks[i] << endl;
}

int main()
{
    int numOfHouses = 9, numOfPipes = 6;

    int network[][3] = {{7, 4, 98}, {5, 9, 72}, {4, 6, 10}, {2, 8, 22}, {9, 7, 17}, {3, 1, 66}};

    installTapsAndTanks(network, numOfHouses, numOfPipes);

    return 0;
}