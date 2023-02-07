#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a{1, 101, 2, 3, 100, 4, 5};

    int m[a.size()];

    for (int i = 0; i < a.size(); i++)
        m[i] = a[i];

    for (int i = 1; i < a.size(); i++)
        for (int j = i - 1; j >= 0; j--)
            if (m[j] + a[i] > m[i] && a[j] < a[i])
                m[i] = m[j] + a[i];

    cout << *max_element(m, m + a.size()) << endl;

    return 0;
}