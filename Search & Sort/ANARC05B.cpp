/*
    PRATA - ANARC05B
    Link: https://www.spoj.com/problems/ANARC05B/
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
//--------------------------------------------------------------------
class Solution
{
public:
    int minSum(std::vector<int> &v1, int n, std::vector<int> &v2, int m)
    {
        unordered_set<int> c, common;
        for (int i = 0; i < n; i++)
        {
            c.insert(v1[i]);
        }
        for (int i = 0; i < m; i++)
        {
            if (binary_search(v1.begin(), v1.end(), v2[i]))
            {
                common.insert(v2[i]);
            }
        }
        int ans = 0;
        int temp_sum_1 = 0, temp_sum_2 = 0, counter_1 = 0, counter_2 = 0;
        while (common.empty() == false)
        {
            while (counter_1 < n && common.find(v1[counter_1]) == common.end())
            {
                temp_sum_1 += v1[counter_1++];
            }
            while (counter_2 < m && common.find(v2[counter_2]) == common.end())
            {
                temp_sum_2 += v2[counter_2++];
            }
            common.erase(v1[counter_1]);
            ans += max(temp_sum_1, temp_sum_2);
            temp_sum_1 = temp_sum_2 = 0;
        }
        while (counter_1 < n)
        {
            temp_sum_1 += v1[counter_1++];
        }
        while (counter_2 < m)
        {
            temp_sum_2 += v2[counter_2++];
        }
        return ans + max(temp_sum_2, temp_sum_1);
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1;
    // cin >> testcases ;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        std::vector<int> v1(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v1[i];
        }
        int m;
        cin >> m;
        std::vector<int> v2(m);
        for (int i = 0; i < m; i++)
        {
            cin >> v2[i];
        }
        Solution obj;
        cout << obj.minSum(v1, n, v2, m);
        cout << endl;
    }
    return 0;
}
