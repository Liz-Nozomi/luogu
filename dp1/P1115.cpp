#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[200100];
    int dp[200100];
    //dp[i]以i结尾的段的和。
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    dp[1] = a[1];
    int maxn = a[1];
    for(int i=2;i<=n;i++){
        dp[i] = max( dp[i-1]+a[i], a[i]);//续前一个和从它开始
            if(dp[i] > maxn){
                maxn = dp[i];
            }

        }

    
    cout<<maxn;
    
    
}