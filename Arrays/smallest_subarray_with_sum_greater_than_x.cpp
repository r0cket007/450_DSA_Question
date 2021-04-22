/*
	Smallest subarray with sum greater than x
	
	Link: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1#

	Q. Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than 
	   the given value.

	---------------------------------
	Input:
	A[] = {1, 4, 45, 6, 0, 19}
	x  =  51
	
	Output: 3
	----------------------------------
	Input:
	A[] = {1, 10, 5, 2, 7}
	x  = 9
	
	Output: 1
	----------------------------------
	
	Expected Time Complexity: O(N)
	Expected Auxiliary Space: O(1)

	Easy Tag
*/

#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;



//-------------------------------------------------------------------------
int solve(int arr[], int n, int x)
{
    int left = 0 , right = 0 ;
    int sum = 0 ;
    int answer = INT_MAX ;
    while( right < n )
    {
        sum += arr[ right ] ;
        if( sum > x ) 
        {
            
            while( left < right && sum - arr[ left ] > x )
            {
                sum -= arr[ left ] ;
                left ++ ;
            }
            answer = min( answer , right - left + 1 ) ;
        }
        right ++ ;
    }
    return answer ;
}
//--------------------------------------------------------------------------
signed main( )
{
	#ifndef ONLINE_JUDGE
    r0cket007
    #endif
	int testcases = 1 ;
	// cin >> testcases ;
	while( testcases -- )
	{
		int n , m ;
		cin >> n ;
		cin >> m ;
		int v[ n ] ;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[ i ] ;
		}
		cout << solve( v , n , m ) ;
		cout << endl ;
	}
	return 0 ;
}