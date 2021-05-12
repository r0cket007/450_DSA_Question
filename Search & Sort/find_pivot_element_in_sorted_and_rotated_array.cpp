/*
    Find pivot element in a sorted and rotated array
    Link: http://theoryofprogramming.com/2017/12/16/find-pivot-element-sorted-rotated-array/
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
int findpivot(int arr[], int n)
{
    int l = 0, r = n - 1 ;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(mid > 0 && mid < n - 1 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if( arr[mid] > arr[n - 1])
        {
            l = mid + 1;
        }
        else 
        {
            r = mid - 1;
        }
    }
    return n - 1;
}
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int arr[] = {1, 2, 3, 4, 5};
        int n = 5;
        cout << findpivot(arr, n);
        cout << endl ;
    }
    return 0 ;
}