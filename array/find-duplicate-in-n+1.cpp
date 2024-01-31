#include <iostream>
#include <vector>

int findDuplicate(std::vector<int> &nums)
{
    int tortoise = nums[0];
    int hare = nums[0];

    do
    {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    tortoise = nums[0];
    while (tortoise != hare)
    {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;
}

int main()
{
    std::vector<int> nums = {1, 3, 4, 2, 2};
    std::cout << "The duplicate number is " << findDuplicate(nums) << std::endl;
    return 0;
}
