#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
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
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     st.insert({10,5});
     st.insert({5,6});
     st.insert({7,3});
     st.insert({7,2});
     st.insert({10,4});
     while(!st.empty())
     {
         pii p=*st.begin();
         cout<<p.first<<" "<<p.second<<endl;
         st.erase(st.begin());
     }
}


