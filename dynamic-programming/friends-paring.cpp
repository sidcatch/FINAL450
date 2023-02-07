#include <iostream>

using namespace std;

int main()
{
    int n = 4;
    int r[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        if (i <= 2)
            r[i] = i;
        else
            r[i] = r[i - 1] + (i - 1) * r[i - 2];
    }

    cout << r[n] << endl;

    return 0;
}