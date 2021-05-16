/*
    Maximum and minimum of an array using minimum number of comparisons
    Link: https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
    
    Tournament Method
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//------------------------------------------------------------------------------
class Solution
{
    pair<int,int> mn_mx;
 public:
    pair<int,int> get_max_min(int arr[], int l, int r)
    {
        if(l == r)
        {
            mn_mx.first = mn_mx.second = arr[l];
        }
        else if(l + 1 == r)
        {
            if(arr[l] > arr[r])
            {
                mn_mx.first = arr[r];
                mn_mx.second = arr[l];
            }
            mn_mx.first = arr[l];
            mn_mx.second = arr[r];
        }
        else
        {
            int mid = l + (r -l) / 2;
            pair<int, int> left = get_max_min(arr, l, mid);
            pair<int, int> right = get_max_min(arr, mid + 1, r);
            mn_mx.first = (left.first <= right.first ? left.first : right.first);
            mn_mx.second = (left.second >= right.second ? left.second : right.second);
        }
        return mn_mx;
    }

};
//------------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int arr[] = {1000, 11, 445, 1, 330, 3000};
        int arr_size = 6;
        Solution obj;
        pair<int, int> ans = obj.get_max_min(arr, 0, arr_size - 1);
        cout << ans.first << " " << ans.second;
        cout << endl ;
    }
    return 0 ;
}
/*
    Total number of comparisons: let the number of comparisons be T(n). T(n) can be written as follows: 
    Algorithmic Paradigm: Divide and Conquer 
 
    T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2  
    T(2) = 1
    T(1) = 0
    If n is a power of 2, then we can write T(n) as: 

    T(n) = 2T(n/2) + 2
    After solving the above recursion, we get 

    T(n)  = 3n/2 -2

*/