/*
    Edit Distance 
    LINK : https://practice.geeksforgeeks.org/problems/edit-distance3702/1#
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
const int MAX = 500; 
bool ispar(string x)
{
   stack<char> brace;
   int n = x.length();
   for(int i = 0; i < n; i++)
   {
        if(x[i] == '(' || x[i] == '[' || x[i] == '{')
        {
            if(x[i] == '(')
                brace.push(')');
            else if(x[i] == '[')
                brace.push(']');
            else
                brace.push('}');
        }
        else
        {
            if(brace.empty() || brace.top() != x[i])
            {
                return false;
            }
            brace.pop();
        }
   }
   if( !brace.empty() )
   {
       return false;
   }
   return true;
   
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
        string s = "{[(]})";
        cout << ispar(s);
    }
    return 0 ;
}