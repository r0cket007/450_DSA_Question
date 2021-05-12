/*
    Kth smallest number again
    Link: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/kth-smallest-number-again-2/

*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
signed main()
{
    int testcases = 1 ;
    cin >> testcases ;
    while( testcases -- )
    {
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        int i = 0;
        for (int j = 1; j < n; j++)
        {
            if (v[i].second >= v[j].first)
                v[i].second = max(v[i].second, v[j].second);
            else
            {
                i++;
                v[i] = v[j];
            }
        }
        while (q--)
        {
            int k;
            cin >> k;
            int ans = -1;
            for(int j = 0; j <= i; j++)
            {
                if((k - 1 + v[j].first) <= v[j].second)
                {
                    ans = v[j].first + k - 1;
                    break;
                }
                else
                    k = k - (v[j].second - v[j].first + 1);
            }
            cout << ans << "\n";
        }
        cout << endl ;
    }
    return 0 ;
}