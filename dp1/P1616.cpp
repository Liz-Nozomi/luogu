#include <bits/stdc++.h>
using namespace std;

int main(){
    int T,m;
    cin>>T>>m;
    int t[10010],v[10010];

    for(int i=1;i<=m;i++){
        
        cin>>t[i]>>v[i];
    }
    long long dp[10000100];//花费t时间得到的最大价值
    memset(dp,0,sizeof(dp));


    for(int i=1;i<=m;i++){
        for(int j = t[i];j<=T;j++){
            dp[j] = max(dp[j],dp[j-t[i]]+v[i]);
        }
    }
    cout<<dp[T];



}