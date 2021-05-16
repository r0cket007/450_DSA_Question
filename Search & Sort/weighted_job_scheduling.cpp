/*
    Weighted Job Scheduling
    Link: https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/
*/
#include <bits/stdc++.h>
using namespace std;
//-------------------------------------------------------------------------
struct Job
{
    int start, finish, profit;
};
bool solve(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}
int Search(Job jobs[], int index)
{
    int l = 0, r = index - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                l = mid + 1;
            else
                return mid;
        }
        else
            r = mid - 1;
    }
    return -1;
}
int findMaxProfit(Job arr[], int n)
{
    sort(arr, arr + n, solve);
    std::vector<int> table(n);
    table[0] = arr[0].profit;
    for (int i = 1; i < n; i++)
    {
        int sum = arr[i].profit;
        int l = Search(arr, i);
        if (l != -1)
            sum += table[l];
        table[i] = max(sum, table[i - 1]);
    }
    int result = table[n - 1];
    return result;
}
//------------------------------------------------------------------------
int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findMaxProfit(arr, n);
    return 0;
}