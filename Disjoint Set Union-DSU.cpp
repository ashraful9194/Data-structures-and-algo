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
int parent[10000];
void make_set(int node)///create a set of single element
{
    parent[node]=node;
}
int find_set(int node)///Find the representative of  a set......
{
     if(node==parent[node]) return  node;
    return parent[node]=find_set(parent[node]);///set the main  representative for all traversed nodes....
}
void union_sets(int a,int b)///find if two nodes are in the same set or not........
{
    a=find_set(a);
    b=find_set(b);
    if(a==b) cout<<"In the same set."<<endl;
    else {
        cout<<"In the different sets."<<endl;
        parent[b]=a;
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
}


