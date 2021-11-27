#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int Trie[1000][30];
int stop[1000];
int cnt;
void insert(string s,int n)
{
    int node=0;
    for(int i=0; i<n; i++)
    {
        int x=s[i]-'a';
        if(!Trie[node][x]) Trie[node][x]=++cnt;
        node=Trie[node][x];
    }
    stop[node]=1;
}
int search(string s,int n )
{
    int node=0;
    for(int i=0; i<n; i++)
    {
        int x=s[i]-'a';
        node=Trie[node][x];
        if(!node) return  0;
    }
    return stop[node];
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int n;
     cin>>n;
     for(int i=0; i<n; i++)
     {
         string s;
         cin>>s;
         insert(s,s.size());
     }
     int q;
     cin>>q;
     while(q--)
     {
         string s;
         cin>>s;
         if(search(s,s.size())) cout<<"Found"<<endl;
         else cout<<"Not Found"<<endl;
     }
}

