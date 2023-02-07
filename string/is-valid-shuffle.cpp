#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string r, a, b;
    cin >> r >> a >> b;

    string net = a + b;

    sort(r.begin(), r.end());

    sort(net.begin(), net.end());

    if (r == net)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
