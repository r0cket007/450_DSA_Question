/*
    Count triplets with sum smaller than X 
    Link: https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        long long ans = 0;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            int target = sum - arr[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                if (arr[l] + arr[r] < target)
                {
                    ans += (r - l);
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return ans;
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int N = 5, X = 12 ;
        int arr[] = {5, 1, 3, 4, 7};
        Solution obj;
        cout << obj.countTriplets(arr, N, X);
         cout << endl;
    }
    return 0 ;
}