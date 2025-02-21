#include <bits/stdc++.h>
using namespace std;




int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int a[1000];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int dp[1000];//方法数,在花费i元时
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i];j--){
            dp[j] = dp[j]+ dp[j-a[i]];

        }
        
    }
    cout<<dp[m];
}