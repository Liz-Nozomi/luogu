#include <bits/stdc++.h>
using namespace std;

int main(){
    int r;
    cin>>r;
    int a[1010][1010];
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    //dp[i][j]:走到[i][j]时能得到的最大和
    int dp[1010][1010];
    dp[1][1] = a[1][1];
    for(int i=2;i<=r;i++){
        dp[i][1] = dp[i-1][1] + a[i][1];
    }
    for(int i=2;i<=r;i++){
        dp[i][i] = dp[i-1][i-1] + a[i][i];
    }
    for(int i=3;i<=r;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + a[i][j];
        }
    }
    int maxn = 0;
    for(int i=1;i<=r;i++){
        if(dp[r][i] > maxn){
            maxn = dp[r][i];
        }
    }
    cout<<maxn;
}