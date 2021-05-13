/*
    PRATA - Roti Prata
    Link: https://www.spoj.com/problems/PRATA/
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
    int get_num(int a, int sum)
    {
        int d = (int)sqrt(a * a + 8 * a * sum);
        d -= a;
        return d / (2 * a);
    }
    bool check(vector<int> &v, int n, int val, int m)
    {
        int prata = 0;
        for (int i = 0; i < n; i++)
        {
            prata += get_num(v[i], val);
            if (prata >= m)
                return true;
        }
        return false;
    }
    int minTime(std::vector<int> &v, int n, int m)
    {
        int l = 1, r = 10 * m * (m + 1) / 2;
        int result = LLONG_MAX;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(v, n, mid, m))
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
    r0cket007 int testcases = 1;
    cin >> testcases;
    while (testcases--)
    {
        int m;
        cin >> m;
        int n;
        cin >> n;
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        Solution obj;
        cout << obj.minTime(v, n, m);
        cout << endl;
    }
    return 0;
}