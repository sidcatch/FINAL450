#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a;
    cin >> b;

    int aIndex = 0;
    int bIndex = 0;

    bool isRotation = true;

    if (a.length() != b.length())
        isRotation = false;
    else
    {
        while (true)
        {

            if (a[aIndex] == b[bIndex])
            {
                if (aIndex == a.length() - 1)
                {
                    isRotation = true;
                    break;
                }

                aIndex++;
                bIndex = (bIndex + 1) % a.length();
            }
            else
            {

                if (bIndex == a.length() - 1)
                {
                    isRotation = false;
                    break;
                }

                aIndex = 0;
                bIndex = (bIndex + 1) % a.length();
            }
        }
    }

    cout << isRotation << endl;

    return 0;
}