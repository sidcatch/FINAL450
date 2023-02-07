#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 3, 2};

    int m[a.size()];

    for (int i = 0; i < a.size(); i++)
        m[i] = 1;

    for (int i = 1; i < a.size(); i++)
        for (int j = 0; j < i; j++)
            if (m[j] + 1 > m[i] && abs(a[j] - a[i]) == 1)
                m[i] = m[j] + 1;

    cout << *max_element(m, m + a.size()) << endl;

    return 0;
}
