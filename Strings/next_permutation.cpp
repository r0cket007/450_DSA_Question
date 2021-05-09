/*
        Next Permutation
        Link: https://practice.geeksforgeeks.org/problems/next-permutation5226/1#
        
        Expected Time Complexity: O(N)
        Expected Auxiliary Space: O(1)
        Constraints:
        1 ≤ N ≤ 10000
*/
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define int long long

//--------------------------------------------------------------------------
vector<int> nextPermutation(int n, vector<int> arr)
{
    int pos = -1;
    for(int i = n - 2; i >= 0 ; i--)
    {
        if( arr[ i ] < arr[ i + 1 ])
        {
            pos = i ;
            break;
        }
    }
    if( pos == -1)
    {
        
        reverse(arr.begin(), arr.end());
        return arr;
    }
    int left = pos + 1 ;
    int right = n - 1 ;
    //binary search
    while(left <= right)
    {
        int mid = left + (right - left) / 2 ;
        if(arr[mid] > arr[pos])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    swap( arr[pos], arr[left - 1] );
    reverse( arr.begin() + pos + 1 , arr.end());
    return arr;
    
}
//--------------------------------------------------------------------------

signed main()
{
    fast;
    int testcases = 1;
    // cin >> testcases;
    while(testcases--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        v = nextPermutation(n, v);
        for(auto i : v)
        {
            cout << i <<" ";
        }
        cout << endl;
    }
    return 0;
}