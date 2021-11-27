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
/*
struct cmp{
bool operator()(const pii &a,const pii &b)
{
    if(a.first==b.first) return a.second<b.second;///second value small to big
    else return a.first>b.first;///first value big to small
}
};
///in pq true means swap required  ,false means swap  not required...
set<pii,cmp>st;
priority_queue<pii,deque<pii>,cmp>pq;
*/
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
}

