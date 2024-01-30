#include <iostream>
#include <vector>
using namespace std;

struct ElementCount
{
    int element;
    int count;
};

void moreThanNbyK(int arr[], int n, int k)
{
    if (k < 2)
        return;

    // Step 1: Create an array of size k-1 to store elements and counts
    vector<ElementCount> temp(k - 1);

    // Initialize count of all potential candidates as 0
    for (int i = 0; i < k - 1; i++)
        temp[i].count = 0;

    // Step 2: Process all elements of input array
    for (int i = 0; i < n; i++)
    {
        int j;

        // Check if arr[i] is already present in temp[]
        for (j = 0; j < k - 1; j++)
        {
            if (temp[j].element == arr[i])
            {
                temp[j].count += 1;
                break;
            }
        }

        // If arr[i] is not present in temp[]
        if (j == k - 1)
        {
            int l;

            // Check if there is any position in temp[] where arr[i] can be added
            for (l = 0; l < k - 1; l++)
            {
                if (temp[l].count == 0)
                {
                    temp[l].element = arr[i];
                    temp[l].count = 1;
                    break;
                }
            }

            // Decrease count of all other elements if there is no vacant position in temp[]
            if (l == k - 1)
                for (l = 0; l < k - 1; l++)
                    temp[l].count -= 1;
        }
    }

    // Step 3: Check actual counts of potential candidates in temp[]
    for (int i = 0; i < k - 1; i++)
    {
        int ac = 0; // actual count

        for (int j = 0; j < n; j++)
            if (arr[j] == temp[i].element)
                ac++;

        // If count is more than n/k, then print it
        if (ac > n / k)
            cout << "Number: " << temp[i].element << ", Count: " << ac << "\n";
    }
}

int main()
{
    int arr[] = {4, 5, 6, 7, 8, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    moreThanNbyK(arr, n, k);
    return 0;
}

// The concept behind finding elements that appear more than n/k times in an array without using hash tables involves a smart extension of the Boyer-Moore Majority Vote algorithm. Let's break it down:

// Understanding the Boyer-Moore Majority Vote Algorithm: This algorithm is originally designed to find a majority element in an array, i.e., an element that appears more than n/2 times. It does so by maintaining a single candidate and a count. The count is increased when the candidate element is found and decreased when a different element is found. If the count reaches zero, a new candidate is chosen.

// Extending to n/k Scenario: When we want to find elements that appear more than n/k times, we extend this idea. Since there can be at most k-1 such elements (because if there were k or more, they couldn't all appear more than n/k times), we maintain k-1 candidates and their counts.

// Maintaining Candidates and Counts:

// You start with an array of k-1 potential candidates, each with a count initialized to zero.
// As you iterate through the elements of the input array, for each element, you do one of the following:
// If the element matches one of the candidates, you increase that candidate's count.
// If the element doesn't match any candidate and there is a candidate whose count is zero, you replace this candidate with the new element, setting the count to one.
// If the element doesn't match any candidate and all candidates have a count greater than zero, you decrease the count of each candidate by one.
// Why Decrease Counts?: The idea behind decreasing counts is that if an element is a true candidate (appears more than n/k times), it will not be completely eliminated by these decrements. This is because it has enough frequency to stay in the race, while the non-candidates will eventually have their counts reduced to zero and be replaced.

// Second Pass for Verification: After processing the entire array, the k-1 candidates are potential answers, but their counts may not be accurate (due to decrements). So, you need to make another pass through the array to count the actual occurrences of these candidates and determine if they indeed appear more than n/k times.

// Result: The elements that are confirmed to appear more than n/k times in this second pass are the required elements.

// This approach efficiently narrows down potential candidates using a constant amount of space (O(k)) and requires two passes through the array, making the time complexity O(n). It's a clever use of the majority vote concept adapted for a more generalized scenario.
