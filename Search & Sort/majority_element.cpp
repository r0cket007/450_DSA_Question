/*
    Majority Element
    Link: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//---------------------------------------------------------------------------------
class Solution{
  public:
    int majorityElement(int arr[], int size)
    {
        
        int var1 = 0;
        int count1 = 0;
        for(int i = 0; i < size; i ++)
        {
            if(count1 == 0)
            {
                var1 = arr[i];
                count1++ ;
            }
            else if(var1 == arr[i])
            {
                count1 ++ ;
            }
            else 
            {
                count1 --;
            }
        }
        count1 = 0;
        for(int i = 0; i < size; i ++)
        {
            if(var1 == arr[i])
            {
                count1 ++ ;
            }
        }
        if(count1 > size / 2)
            return var1 ;
        return -1;
    }
};
//---------------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int n = 5; 
        int A[] = {3,1,3,3,2};
        Solution obj;        
        cout << obj.majorityElement(A, n);
        cout << endl ;
    }
    return 0 ;
}
