#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, greater<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int ternary_search(int lo,int hi)
{
    int res=0;
    while(lo+2<hi)///cause,if len<=3 and we are working with only integer range then ternary will not work.
    {
        int m1=lo+(hi-lo)/3;
        int m2=hi-(hi-lo)/3;
        double op1=check(m1);///always try to check the answer in double..cause,two different middle point
        double op2=check(m2);///can give the same answer in integer
        if(op1<op2)
        {
            res=op2;
            lo=m1+1;
        }
        else
        {
            res=op1;
            hi=m2-1;
        }
    }
   for(int i=lo; i<=hi; i++)
        res=max(res,(int)check(i));
    return res;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

}

