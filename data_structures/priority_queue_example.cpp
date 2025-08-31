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

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ///max heap priority queue//From big to small
     priority_queue<int>pq;
     pq.push(10);
     pq.push(9);
     pq.push(15);
     pq.push(10);
     while(!pq.empty())
     {
         cout<<pq.top()<<endl;
         pq.pop();
     }
     ///min heap priority queue//From small to big
    priority_queue<int,vector<int>,greater<int> >pq2;
      pq2.push(10);
     pq2.push(9);
     pq2.push(15);
     pq2.push(10);
     while(!pq2.empty())
     {
         cout<<pq2.top()<<endl;
         pq2.pop();
     }
///contains multiple same value...but set can't.....

}


