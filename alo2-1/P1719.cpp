#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int mat[150][150];
    int dp[150][150];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mat[i][j];
        }
    }

    dp[1][1] = mat[1][1];
    for(int i=2;i<=n;i++){
        dp[1][i] = dp[1][i-1] + mat[1][i];
        dp[i][1] = dp[i-1][1] + mat[i][1];
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + mat[i][j] -dp[i-1][j-1];
        }
    }





}