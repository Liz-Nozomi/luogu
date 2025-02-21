#include <bits/stdc++.h>
using namespace std;

int main(){
    int T,M;
    cin>>T>>M;
    int t[110],v[110];
    for(int i=1;i<=M;i++){
        cin>>t[i]>>v[i];
    }
    int dp[110][1100];//dp[i][t] 花费时间为t时，到第i件物品的总价值
    for(int i=1;i<=M;i++){
        dp[i][0] = 0;
    } 
    dp[1][0] = v[1];
    for(int i=1;i<=M;i++){
        for(int j=0;j<=T;j++){
            if(j >= t[i]){
                dp[i][j] = max( dp[i-1][j], dp[i-1][j-t[i]] + v[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[M][T];

}