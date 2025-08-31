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
int dp[10000];
int can_win(int n)
{
    if(n==0 || n==1) return 0;
    if(can_win(n-2)==0 || can_win(n-3)==0 || can_win(n-5)==0) return 1;
    else
      return 0;
}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     ///A game between computer and me ...Each step one can take 2/3/5 marbles from the table..Who can't take
     ///2/3/5 marble lose the game...Given marbles.. Who  will win the game..find out.....................
     ///computer takes the first move...
     int t;
     cin>>t;
     while(t--)
     {
           int n;
     cin>>n;
     int x=can_win(n);///first player can win???
     if(x) cout<<"computer"<<endl;
     else cout<<"me"<<endl;

     }
}


