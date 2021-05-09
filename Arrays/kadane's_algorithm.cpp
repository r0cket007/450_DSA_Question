/*
	Minimum number of jumps

	Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

	Q.	Given an array arr of N integers. Find the contiguous sub-array with maximum sum. 
	
	-----------------------------------------------------
	Input:
	N=11 
	arr=1 3 5 8 9 2 6 7 6 8 9 

	Output: 
	3 
	
	Explanation: 
	First jump from 1st element to 2nd 
	element with value 3. Now, from here 
	we jump to 5th element with value 9, 
	and from here we will jump to last. 
	-----------------------------------------------------
	
	Expected Time Complexity: O(N)
	Expected Auxiliary Space: O(1)

	Medium
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
//---------------------------------------------------------------------------------

int minJumps(int arr[], int n)
{
       int steps = 0 ;
       int i = 0 ;
       int mx = arr[ 0 ];
       while( i < n - 1 )
       {
            steps ++ ;
            int temp = mx ;
            if( temp <= 0 ) 
                return -1;
            mx = 0 ;
            
            while( i < n && i < temp )
            {
                i ++ ;
                mx = max( mx , arr[ i ] + i ) ;
            }
            if( i > n - 1 ) 
                break ;
       }
       return steps ;
}

//------------------------------------------------------------------------------------
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
		cout << minJumps( arr , n ) ;
	}
	return 0 ;
}