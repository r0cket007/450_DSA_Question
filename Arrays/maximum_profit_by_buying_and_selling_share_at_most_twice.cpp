/*
	Maximum profit by buying and selling a share at most twice 

	Link: https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

	Q.	In daily share trading, a buyer buys shares in the morning and sells them on 
		the same day. If the trader is allowed to make at most 2 transactions in a day, 
		whereas the second transaction can only start after the first one is complete (Sell->buy->sell->buy). 
		Given stock prices throughout the day, find out the maximum profit that a share trader could have made.

	-----------------------------------------------------
	Input:   price[] = {10, 22, 5, 75, 65, 80}
	
	Output:  87
	
	Trader earns 87 as sum of 12, 75 
	Buy at 10, sell at 22, 
	Buy at 5 and sell at 80
	-----------------------------------------------------
	Input:   price[] = {2, 30, 15, 10, 8, 25, 80}
	
	Output:  100
	
	Trader earns 100 as sum of 28 and 72
	Buy at price 2, sell at 30, buy at 8 and sell at 80
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
int maxProfit(int price[], int n)
{
    int* profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;
    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--) 
    {
        if (price[i] > max_price)
            max_price = price[i];
        profit[i]
            = max(profit[i + 1], max_price - price[i]);
    }
    int min_price = price[0];
    for (int i = 1; i < n; i++) 
    {
        if (price[i] < min_price)
            min_price = price[i];
        profit[i] = max(profit[i - 1],
                        profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];
 
    delete[] profit;
 
    return result;
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
		int n , m ;
		cin >> n ;
		int arr[ n ] ;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[ i ] ;
		}
		cout << maxProfit( arr , n ) ;
		cout << endl ;
	}
	return 0 ;
}