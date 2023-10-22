#include <iostream>
#include <queue>

using namespace std;

//Can be done without queue!
int main()
{

    int n = 4;
    int petrols[] = {4, 6, 7, 4};
    int distances[] = {6, 5, 3, 5};
    queue<int> q;

    int petrol = 0;
    int i = 0;
    while (q.size() < 2 || q.front() != q.back())
    {

        petrol += petrols[i];

        // if (petrol >= distances[i])
        // {
        //     petrol -= distances[i];
        //     q.push(i);
        //     i = (i + 1) % n;
        // }
        // else
        // {
        while (!q.empty() && petrol < distances[i])
        {
            int currStartingPoint = q.front();
            q.pop();
            petrol -= petrols[currStartingPoint];
            petrol += distances[currStartingPoint];
        }
        if (petrol >= distances[i])
        {
            petrol -= distances[i];
            q.push(i);
            i = (i + 1) % n;
        }
        else if (q.empty())
        {
            petrol = 0;
            i = (i + 1) % n;
        }
        // }
    }

    cout << q.front() << endl;

    return 0;
}