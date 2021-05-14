/*
    PRATA - ANARC05B
    Link: https://www.spoj.com/problems/ANARC05B/
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define r0cket007 in out
//--------------------------------------------------------------------
class Solution
{
public:
    long long ans = 0;
    long long a, b;
    vector<long long> getSubsets(vector<long long> &s, int start, int siz)
    {
        vector<long long> temp;
        for (int j = 0; j < pow(2, siz); j++)
        {
            long long sum = 0;
            for (int i = start; i <= start + siz; i++)
            {
                if (j & (1 << (i - start)))
                {
                    sum += s[i];
                }
            }
            temp.push_back(sum);
        }
        return temp;
    }
    int subsets(vector<long long> &s, int a, int b)
    {
        int n = s.size();
        vector<long long>::iterator low, high;
        vector<long long> left = getSubsets(s, 0, n / 2);
        vector<long long> right = getSubsets(s, n / 2, n & 1 ? n / 2 + 1 : n / 2);
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
    // r0cket007
    int testcases = 1;
    cin >> testcases;
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
