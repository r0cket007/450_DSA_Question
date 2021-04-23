/*
	Rearrange array in alternating positive & negative items with O(1) extra space

	Link: https://www.geeksforgeeks.org/rearrange-array-in-alternating-positive-negative-items-with-o1-extra-space-set-2/
	
	Q.	Given an array of positive and negative numbers, arrange them in an alternate 
		fashion such that every positive number is followed by negative and vice-versa. 
		Order of elements in output doesn’t matter. Extra positive or negative elements 
		should be moved to end

	
	-----------------------------------------------------
	Input :
	arr[] = {-2, 3, 4, -1}
	
	Output :
	arr[] = {-2, 3, -1, 4} OR {-1, 3, -2, 4}
	-----------------------------------------------------
	
	Expected Time Complexity: O(n)
	Expected Auxiliary Space: O(1)

*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
int N = 1e6 + 1 ;
//---------------------------------------------------------------------------------------
void rearrange(int arr[], int n)
{
    int i = -1, j = n;
 
    // shift all negative values to the end
    while (i < j)
    {
        while(i <= n - 1 and arr[i] > 0)
            i += 1;
        while (j >= 0 and arr[j] < 0)
            j -= 1;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    if (i == 0 || i == n)
        return;
    int k = 0;
    while (k < n && i < n)
    {
        swap(arr[k], arr[i]);
        i = i + 1;
        k = k + 2;
    }
}
//-----------------------------------------------------------------------------------------
signed main( )
{
	#ifndef ONLINE_JUDGE
    r0cket007
    #endif
	int testcases = 1 ;
	// cin >> testcases ;
	while( testcases -- )
	{
		int arr[6] = {2, 3, -4, -1, 6, -9};
    	int n = sizeof(arr)/sizeof(arr[0]);
   		rearrange(arr, n);
   		for( auto i : arr )
   		{
   			cout << i << " " ;
   		}
		cout << endl ;
	}
	return 0 ;
}