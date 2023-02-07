#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {5, 5, 10, 100, 10, 5};

    if (a.size() == 1)
        return a[0];

    int m[a.size()][2];

    m[0][0] = 0;
    m[0][1] = a[0];

    for (int i = 1; i < a.size(); i++)
    {
        m[i][1] = m[i - 1][0] + a[i];
        m[i][0] = max(m[i - 1][0], m[i - 1][1]);
    }

    cout << max(m[a.size() - 1][0], m[a.size() - 1][1]) << endl;

    return 0;
}