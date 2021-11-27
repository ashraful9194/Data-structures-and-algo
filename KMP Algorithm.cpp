#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
string s;
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
///prefix function/LPS function(longest prefix suffix function)/Failure function
///find longest length of prefix=suffix...of substr(0,idx) in lps[idx].....
vector<int>lps(100005,0);
///naive implementation......
/*
void lps_function()
{
    int n=s.size();
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= i; k++)
            if (s.substr(0, k) == s.substr(i-k+1, k))
                lps[i] = k;
}
*/
///Efficient approach..........
void lps_func()
{
    int n=s.size();
    for(int i=1; i<n; i++)
    {
        int j=lps[i-1];
        while(j>0 && s[i]!=s[j])
            j=lps[j-1];
        if(s[i]==s[j])
            ++j;
        lps[i]=j;
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>s;
     lps_func();
     for(int i=0; i<s.size(); i++)
        cout<<lps[i]<<" ";
     cout<<endl;
     ///Aplications.........
     ///1-Find if a string s appear in string t...Just find the lps of :(s+#+t)...if lps[idx]==s.size() then yes...time complexity...O(n+m)...



}


