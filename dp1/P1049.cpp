#include <bits/stdc++.h>
using namespace std;

int main(){
    int V,n;
    cin>>V;
    cin>>n;
    int v[50];
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int dp[20010];//最大物品体积
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j = V;j>=v[i];j--){
            dp[j] = max(dp[j],dp[j-v[i]]+v[i]);

        }
        
    }
    cout<<V-dp[V];
}