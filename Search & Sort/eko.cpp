/*
    EKO
    Link: https://www.spoj.com/problems/EKO/
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
 public:
    bool check(std::vector<int> &v, int n, int val, int m)
    {
        int curr_sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(val >= v[i])
                continue;
            curr_sum += v[i] - val;
            if(curr_sum >= m)
                return true;
        }
        return false;
    }
    int maxLength(std::vector<int> &v, int n, int m)
    {
        int l = 0, r = v.back();
        int result = -1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(check(v, n, mid, m))
            {
                result = max(result, mid);
                l = mid + 1;
            }
            else 
                r = mid - 1;
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
        int n, m;
        cin >> n;
        cin >> m;
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        Solution obj;
        cout << obj.maxLength(v, n, m);
        cout << endl;
    }
    return 0 ;
}