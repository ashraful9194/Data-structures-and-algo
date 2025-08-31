
///.................This is the task....................
/*
Lab01:Problem

Suppose we have a group of proposed talks with preset start and end times. Design
an algorithm to schedule as the largest possible combined attendance of the
scheduled talks, under the assumptions that once a talk starts, it continues until it
ends, no two talks can proceed at the same time, and a talk can begin at the same
time another one ends. Assume that talk j begins at time sj (where s stands for
start) and ends at time ej (where e stands for end).

Example: Consider seven talks with these start times, end times and number of
attendances,
Talk 1: start 8 a.m., end 10 a.m., attendance = 35
Talk 2: start 9 a.m., end 11 a.m., attendance = 30
Talk 3: start 10:30 a.m., end 12 noon, attendance = 25
Talk 4: start 9:30 a.m., end 1 p.m., attendance = 20
Talk 5: start 8:30 a.m., end 2 p.m., attendance = 15
Talk 6: start 11 a.m., end 2 p.m., attendance = 10
Talk 7: start 1 p.m., end 2 p.m., attendance = 5

Solution: selected talk = {1,3,7}, total attendance = 65

Input:
First n indicate number of talk (n=0 indicates end of file), next n line
contains talk number (<100), start times (24H format), end time (24H
format) and attendance number (<=1000).

Output:
Print selected talk no. and total attendances

Sample input output:
Input
7
1 8.00 10.00 35
2 9.00 11.00 30
3 10.30 12.00 25
4 9.30 13.00 20
5 8.30 14.00 15
6 11.00 14.00 10
7 13.00 14.00 5
0
Output
1 3 7 65

*/
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
double start_time[105],end_time[105];
int attendance[105];
int dp[105][30];
int n;
int solve(int pos,int pre)
{
    if(pos>n) return 0;
    int &ans=dp[pos][pre];
    if(ans!=-1) return ans;

    if(start_time[pos]>=pre)
    {
        int x=solve(pos+1,pre);
        int y=solve(pos+1,end_time[pos])+attendance[pos];
        return ans=max(x,y);
    }
    else
    return ans=solve(pos+1,pre);
}
void solution_printing(int pos,int pre,int max_attendance)
{
    if(pos>n) return;
    if(dp[pos+1][pre]==max_attendance)
        solution_printing(pos+1,pre,max_attendance);
    else
    {
        cout<<pos<<" ";
        solution_printing(pos+1,end_time[pos],max_attendance-attendance[pos]);
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     while(cin>>n)
     {
         if(n==0) break;
         int idx;
         for(int i=1; i<=n; i++)
         {
             cin>>idx>>start_time[i]>>end_time[i]>>attendance[i];
         }
         memset(dp,-1,sizeof dp);
         int max_attendance=solve(1,0);
         solution_printing(1,0,max_attendance);
         cout<<max_attendance<<endl;
     }
}


