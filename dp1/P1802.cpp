#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;//n是数量 x是有的资源
    long long dp[1010][1010];
    int lose[1010],win[1010],use[1010];
    for(int i=1;i<=n;i++){
        cin>>lose[i]>>win[i]>>use[i];
    }
   

    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(use[i] >j){
                dp[i][j] = dp[i-1][j] + lose[i];
            }
            else{
                dp[i][j] = max( dp[i-1][j] + lose[i],dp[i-1][j-use[i]] + win[i]);

            }
        }
    }

    cout<<dp[n][x] * 5;
}