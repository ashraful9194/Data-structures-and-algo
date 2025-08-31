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


bool cmp(const pii &a,const pii &b)
{
    if(a.first==b.first) return a.second<b.second;///second value small to big
    else return a.first>b.first;///first value big to small
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     deque<pii>dq;
     dq.push_back({10,4});
     dq.push_back({10,3});
     dq.push_back({5,6});
     dq.push_back({7,8});
   sort(dq.begin(),dq.end(),cmp);
   while(!dq.empty())
   {
      pii p= *dq.begin();
      cout<<p.first<<" "<<p.second<<endl;
      dq.pop_front();
   }
}


