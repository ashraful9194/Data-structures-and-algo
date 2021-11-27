#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
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
     orderedSet<int>st;
     st.insert(10);
     st.insert(30);
     st.insert(33);
     st.insert(3);
     st.insert(5);
     int x=st.order_of_key(7);///find number of element strictly less than 7.....
     cout<<x<<endl;
     /// Finding the element in specific index.....................................
    /// in the set using * because
    ///  find_by_order returns an iterator
    cout << *(st.find_by_order(3))<< endl;
}


