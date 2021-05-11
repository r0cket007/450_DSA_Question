/*
    Find All Four Sum Numbers
    Link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
public:
    int n;
    vector<pair<int, int>> findPair(vector<int> &arr, int start, int k)
    {
        vector<pair<int, int>> ans;
        int end = n - 1;
        while (start < end)
        {
            if (arr[start] + arr[end] == k)
            {

                ans.push_back({arr[start], arr[end]});
                start++;
                end--;
            }
            else if (arr[start] + arr[end] > k)
            {
                end--;
            }
            else
                start++;
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        n = arr.size();
        sort(arr.begin(), arr.end());
        set<vector<int>> ans;
        for (int i = 0; i < n - 3; i++)
        {
            int target = k - arr[i];
            for (int ii = i + 1; ii < n - 2; ii++)
            {
                int target2 = target - arr[ii];
                for (auto j : findPair(arr, ii + 1, target2))
                {
                    ans.insert({arr[i], arr[ii], j.first, j.second});
                }
            }
        }
        vector<vector<int>> res;
        for (auto i : ans)
        {
            res.push_back(i);
        }
        return res;
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        Solution obj;
        vector<int> v = {10, 2, 3, 4, 5, 7, 8};
        int k = 23;
        vector<vector<int>> ans = obj.fourSum(v, k);
        for(auto i : ans)
        {
            for(auto j : i)
            {
                cout << j << " ";
            }
            cout << "$";
        }
        cout << endl;
    }
    return 0 ;
}