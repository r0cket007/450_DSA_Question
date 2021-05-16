/*
    In-Place Merge Sort
    Link: https://www.geeksforgeeks.org/in-place-merge-sort/
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
void mergersort(vector<int> &v, const int l, const int mid, const int r)
{
    int i = mid;
    int j = mid + 1;
    while(i >= l && j <= r)
    {
        if(v[i] > v[j])
        {
            swap(v[i], v[j]);
            i--, j ++;
        }
        else break;
    }
    sort(v.begin() + l, v.begin() + mid + 1);
    sort(v.begin() + mid + 1, v.begin() + r + 1);
}
void merge(vector<int> &v, int l, int r)
{
    if(l >= r)
        return;
    {
        int mid = (r + l)>>1 ;
        merge(v, l, mid);  
        merge(v, mid + 1, r);
        mergersort(v, l, mid, r);
    }
}
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        vector<int> v = {4, 6, 1, 5, 7, 8, 3};
        merge(v, 0, v.size() - 1);
        for(auto i : v)
        {
            cout << i << " ";
        }
        cout << endl ;
    }
    return 0 ;
}