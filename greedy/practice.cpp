#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

void printJobScheduling(Job jobs[], int n)
{
    vector<Job> result;
    bool slots[n];

    sort(jobs, jobs + n, compare);

    for (int i = 0; i < n; i++)
        slots[i] = true;

    for (int i = 0; i < n; i++)
    {
        Job curr = jobs[i];

        for (int i = curr.deadline - 1; i >= 0; i--)
        {
            if (slots[i])
            {
                result.push_back(curr);
                slots[i] = false;
                break;
            }
        }
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i].id << " ";
}

bool comp(Job a, Job b)
{
    return a.deadline > b.deadline;
}

// bool comp(const struct Job &a, const struct Job &b)
// {
//     if (a.deadline != b.deadline)
//         return (a.deadline > b.deadline);
//     return (a.profit > b.profit);
// }

struct Comparator
{
    bool operator()(Job a, Job b)
    {
        return a.profit < b.profit;
    }
};

void printJobSchedulingPriorityQueue(Job jobs[], int n)
{

    sort(jobs, jobs + n, comp);

    vector<Job> result;

    priority_queue<Job, vector<Job>, Comparator> maxHeap;

    for (int i = 0; i < n; i++)
    {
        int slots_available;
        if (i == n - 1)
            slots_available = jobs[i].deadline;

        else
            slots_available = jobs[i].deadline - jobs[i + 1].deadline;

        maxHeap.push(jobs[i]);

        while (slots_available > 0 and !maxHeap.empty())
        {
            Job currJob = maxHeap.top();
            maxHeap.pop();

            slots_available--;

            result.push_back(currJob);
        }
    }
    // sort(result.begin(), result.end(), compare);

    for (int i = 0; i < result.size(); i++)
        cout << result[i].id << " ";
}

int main()
{

    Job arr[] = {{0, 2, 100}, {1, 1, 19}, {2, 2, 27}, {3, 1, 25}, {4, 3, 15}};
    // Job arr[] = {{0, 2, 100}, {2, 2, 27}, {3, 1, 25}, {1, 1, 19}, {4, 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs \n";

    printJobScheduling(arr, n); //  |2|0|4| | |

    cout << endl;
    printJobSchedulingPriorityQueue(arr, n);
    return 0;
}
