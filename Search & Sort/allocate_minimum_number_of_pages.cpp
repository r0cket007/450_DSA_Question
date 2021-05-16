/*
    Allocate minimum number of pages
    Link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
 public :
    bool check(int arr[], int n, int m, int sum)
    {
        int sum_till_now = 0;
        int student = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > sum)
                return false;
            sum_till_now += arr[i];
            if (sum_till_now > sum)
            {
                student++;
                sum_till_now = arr[i];
                if (student > m)
                    return false;
            }
        }
        return true;
    }
    int findPages(int arr[], int n, int m)
    {
        if (n < m)
            return -1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int l = 0, r = sum;
        int result = INT_MAX;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(arr, n, m, mid))
            {
                result = min(result, mid);
                r = mid - 1;
            }

            else
                l = mid + 1;
        }
        return result;
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int N = 4, A[] = {12, 34, 67, 90}, M = 2;
        Solution obj;
        cout << obj.findPages(A, N, M);
        cout << endl;
    }
    return 0 ;
}