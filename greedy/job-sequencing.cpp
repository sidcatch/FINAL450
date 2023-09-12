// Given a set of N jobs where each jobi has a deadline and profit associated with it.
// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.
// Find the number of jobs done and the maximum profit.
// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

#include <bits/stdc++.h>
using namespace std;

// Proof: let S be the set of jobs, and am be Job with max profit that belongs to S
// To Prove: am belongs some possible maximum profit subset of S
// let A be the possible maximum profile subset, and let aj be the Job with maximum profit tht belongs to A
// If aj = am, then proved
// If aj != am,
// if Daj>=Dam then let A' = A - aj U am
// Since Pam >= Paj & |A'| = |A|, A' is possible maximum profit subset
// if Daj<Dam...

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{

    sort(arr, arr + n, comparison);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {

        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) // "-1" because job with deadline 1 can be placed on slot with index 0
        {

            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";

    cout << endl;
}

bool comp(const struct Job &a, const struct Job &b)
{
    if (a.deadline != b.deadline)
        return (a.deadline < b.deadline);
    return (a.profit < b.profit);
}

struct Comparer
{
    bool operator()(Job left, Job right)
    {
        return (left.profit) < (right.profit);
    }
};

// Fill gap between jobs with largest deadlines. Start by putting largest deadline into priority queue.
void printJobSchedulingPriorityQueue(Job arr[], int n)
{

    sort(arr, arr + n, comp);

    vector<Job> result;

    // auto cmp = [](Job left, Job right) { return (left.profit) < (right.profit); };
    // priority_queue<Job, vector<Job>, decltype(cmp)> relavantJobs(cmp);

    priority_queue<Job, vector<Job>, Comparer> relavantJobs;

    for (int i = n - 1; i > -1; i--)
    {
        int slotsAvailableForRelevantJobs;
        if (i == 0)
        {
            slotsAvailableForRelevantJobs = arr[i].deadline;
        }
        else
        {
            slotsAvailableForRelevantJobs = arr[i].deadline - arr[i - 1].deadline;
        }

        relavantJobs.push(arr[i]);

        while (slotsAvailableForRelevantJobs > 0 && relavantJobs.size() > 0)
        {

            Job job = relavantJobs.top();
            relavantJobs.pop();

            slotsAvailableForRelevantJobs--;

            result.push_back(job);
        }
    }

    sort(result.begin(), result.end(), comp);

    for (Job job : result)
    {
        cout << job.id << " ";
    }
    cout << endl;
}

int main()
{

    Job arr[] = {{0, 2, 100}, {1, 1, 19}, {2, 2, 27}, {3, 1, 25}, {4, 3, 15}};
    // Job arr[] = {{0, 2, 100}, {2, 2, 27}, {3, 1, 25}, {1, 1, 19}, {4, 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs \n";

    printJobScheduling(arr, n); //  |2|0|4| | |

    printJobSchedulingPriorityQueue(arr, n);
    return 0;
}
