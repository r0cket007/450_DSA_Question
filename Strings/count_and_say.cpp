/*
    Count and Say 
    LINK : https://leetcode.com/problems/count-and-say/
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
const int MAX = 500; 

//-----------------------------------------------------------------------------------
int counter = 1 ;
string solve(string txt, int n)
{
    if(counter == n)
        return txt;
    int i = 0 ;
    string pat ;
    while(i < txt.length())
    {
        char ch = txt[i] ;
        int ct = 0;
        while(ch==txt[i])
        {
            i++;
            ct++;    
        }      
        pat += (char)(ct+'0') ;
        pat += ch ;     
    }
    counter ++ ;
    return solve( pat , n );
}

string countAndSay(int n) 
{
    return solve("1",n);
}

//-------------------------------------------------------------------------------------
signed main( )
{
    #ifndef ONLINE_JUDGE
    r0cket007
    #endif
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int n = 12 ;
        cout << countAndSay(n);
    }
    return 0 ;
}
