/*
    SUBSUMS - Subset Sums
    Link: https://www.spoj.com/problems/SUBSUMS/
*/
#include <bits/stdc++.h>
#define int long long 
using namespace std;
//--------------------------------------------------------------------
class Solution
{
public:
    int ans = 0;
    void getSubsets(vector<int> &s, vector<int> &temp, int start, int siz)
    {
        for (int j = 0; j < pow(2, siz); j++)
        {
            int sum = 0;
            for (int i = start; i <= start + siz; i++)
            {
                if (j&(1<<(i - start)))
                {
                    sum += s[i];
                }
            }
            temp.push_back(sum);
        }
    }
    int subsets(vector<int> &s, int a, int b)
    {
        int n = s.size();
        vector<int>::iterator low, high;
        vector<int> left, right;
        getSubsets(s, left, 0, n >> 1);
        getSubsets(s, right, n >> 1, (n+1) >> 1);
        sort(right.begin(), right.end());
        for (int i = 0; i < left.size(); i++)
        {
            low = lower_bound(right.begin(), right.end(), a - left[i]);
            high = upper_bound(right.begin(), right.end(), b - left[i]);
            ans += (high - right.begin()) - (low - right.begin());
        }
        return ans;
    }
};
//--------------------------------------------------------------------
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int testcases = 1;
    // cin >> testcases;
    while (testcases)
    {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        Solution obj;
        cout << obj.subsets(v, a, b);
        cout << endl;
    }
    return 0;
}
