#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

int random(int low, int high)
{
    if (low > high)
        return high;
    return low + (std::rand() % (high - low + 1));
}

int main(int argc, char *argv[])
{
    std::srand(std::time(0));
    for (int i = 0; i < 5; i++)
        std::cout << random(2, 5) << '\n';
    // wait();
}