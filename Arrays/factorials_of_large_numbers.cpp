/*
	Factorials of large numbers

	Link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

	Q.	Given an integer N, find its factorial.

	
	-----------------------------------------------------
	Input: N = 10
	
	Output: 3628800
	
	Explanation :
	10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
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
int N = 1e6 + 1 ;
//---------------------------------------------------------------------------------------
void multiply( std::vector<int> &v , int b ) 
{
	int x = b ;
	int carry = 0 ;
	int n = v.size( ) ;
	for( int i = 0 ; i < n ; i ++ )
	{
		int y = v[ i ] ;
		int prod = x * y + carry ;
        carry = prod / 10 ;
        prod %= 10 ;
        v[ i ] = prod ;
	}
	while( carry )
	{
		v.push_back( carry % 10 ) ;
		carry /= 10 ;
	}
}
vector<int> factorial(int N)
{
    std::vector<int> ans{ 1 };
    for( int i = 1 ; i <= N ; i ++ )
    {
        multiply( ans , i );
    }
    reverse( ans.begin(), ans.end()	) ;
    return ans ;
    
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
		std::vector<int> v = factorial( 30 );
		cout << endl ;
	}
	return 0 ;
}