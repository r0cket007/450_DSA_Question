/*
    Bishu and Soldiers
    Link: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/bishu-and-soldiers/
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int testcases = 1;
    // cin >> testcases ;
    while (testcases--)
    {
        int n;
        cin >> n;
        vector<int> psol(n), prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> psol[i];
        }
        sort(psol.begin(), psol.end());
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + psol[i];
        }
        int q;
        cin >> q;
        while (q--)
        {
            int sum = 0, total = 0, m;
            cin >> m;
            int pos = upper_bound(psol.begin(), psol.end(), m) - psol.begin();
            cout << pos << " " << prefix[pos];
            cout << endl;
        }
    }
    return 0;
}