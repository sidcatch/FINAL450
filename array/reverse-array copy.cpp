#include <bits/stdc++.h>
using namespace std;

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < a.size(); i++)
        {
            cin >> a[i];
        }

        int leftIndex = 0;
        int rightIndex = a.size() - 1;

        while (leftIndex < rightIndex)
        {
            int temp = a[rightIndex];
            a[rightIndex] = a[leftIndex];
            a[leftIndex] = temp;

            leftIndex++;
            rightIndex--;
        }

        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}