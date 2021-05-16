/*
	Maximum Product Subarray

	Link: https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

	Q.	Given an array Arr that contains N integers 
		(may be positive, negative or zero). Find the product of the maximum product subarray.

	
	-----------------------------------------------------
	Input:
	N = 5
	Arr[] = {6, -3, -10, 0, 2}

	Output: 180
	
	Explanation: Subarray with maximum product
	is  6, -3, -10 which gives product as 180.
	-----------------------------------------------------
	Input:
	N = 6
	Arr[] = {2, 3, 4, 5, -1, 0}
	Output: 120
	Explanation: Subarray with maximum product
	is 2, 3, 4, 5 which gives product as 120.
	-----------------------------------------------------
	
	Expected Time Complexity : O(N)
	Expected Auxilliary Space : O(1)

*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
//---------------------------------------------------------------------------------------
long long maxProduct(int *arr, int n) 
{
    long long pos = 1 ;
    long long neg = 1 ;
    long long answer = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        if( arr[ i ] == 0 )
        {
            answer = max( answer , pos ) ;
            neg = 1 ;
            pos = 1 ;
        }
        else if( arr[ i ] > 0 )
        {
            pos = pos * arr[ i ] ;
            neg *= arr[ i ] ;
        }
        else
        {
            neg *= arr[ i ] ;
            long long temp = pos * arr[ i ] ;
            pos = max( 1LL , neg );
            neg = temp ;
            
        }
        answer = max( answer , pos ) ;
    }
    return answer ;
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
		int n ;
		cin >> n ;
		int arr[ n ] ;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[ i ] ;
		}
		cout << maxProduct( arr , n ) ;
		cout << endl ;
	}
	return 0 ;
}