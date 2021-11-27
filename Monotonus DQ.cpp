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
#define endl '\n'
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};

int main()
{
    ///find largest number with smallest index of every element of an array......
    ///decreasing dq
    /*
    5
30 40 20 30 50
40 50 30 50 -1
    */
    deque<pair<int,int>>dq;
    int n;
    cin>>n;
    int a[n+6];
    int ans[n+4];

    for(int i=0; i<n; i++)
        cin>>a[i];
    dq.push_back({a[0],0});
    for(int i=1; i<n; i++)
    {

        while(!dq.empty() && dq.back().first<a[i])
        {
            ans[dq.back().second]=a[i];
            dq.pop_back();
        }
        dq.push_back({a[i],i});
    }
    ans[n-1]=-1;
    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

