#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
typedef long long ll;
const int inf=0x3f3f3f3f;
const int inn=0x80808080;
using namespace std;
const int maxm=105;
int g[maxm][maxm];
int p[maxm*maxm*maxm];
int ans[maxm*maxm*maxm],cnt;
int n,m;
void input(){
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char t=getchar();
            g[i][j]=(t=='1')?1:inf;
            if(i==j)g[i][j]=0;
        }
        getchar();
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&p[i]);
    }
}
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}
void solve(){
    ans[++cnt]=p[1];
    int dis=0;
    for(int i=2;i<=m;i++){
        dis+=g[p[i-1]][p[i]];
        if(dis>g[ans[cnt]][p[i]]){
            ans[++cnt]=p[i-1];
            dis=g[ans[cnt]][p[i]];
        }
    }
    ans[++cnt]=p[m];
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++){
        printf("%d ",ans[i]);
    }
}
int main(){
    ///codeforces problem :C. Anna, Svyatoslav and Maps


    input();
    floyd();
    solve();
    return 0;
}
