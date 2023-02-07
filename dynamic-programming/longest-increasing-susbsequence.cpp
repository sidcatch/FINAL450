#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a{2, 5, 3, 7, 11, 8, 10, 13, 6};

    int m[a.size()];

    for (int i = 0; i < a.size(); i++)
        m[i] = 1;

    for (int i = 1; i < a.size(); i++)
        for (int j = i - 1; j >= 0; j--)
            if (m[j] + 1 > m[i] && a[j] < a[i])
                m[i] = m[j] + 1;

    cout << *max_element(m, m + a.size()) << endl;

    return 0;
}