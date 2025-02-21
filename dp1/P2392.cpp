#include <bits/stdc++.h>
using namespace std;

int dp_min_time(int a[],int n,int sum){
    vector<int> dp(sum / 2 + 1, 0);//维护dp，i表示时间，dp[i] 表示时间也表示目标花费,优化目标是找到能干到最接近1/2时间的时间
    //memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j = sum/2;j>=a[i];j--){
            if (j >= a[i]) { 
            dp[j] = max(dp[j],dp[j - a[i]] + a[i]);
            }
        }

    }
    int t = sum - dp[sum/2];
    return max(dp[sum/2],t);

}

int main(){
    //ios::sync_with_stdio(false);
    
    int s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int sum1,sum2,sum3,sum4 = 0;
    int a[100],b[100],c[100],d[100];
    for(int i=1;i<=s1;i++){
        cin>>a[i];
        sum1 += a[i];
    }
    for(int i=1;i<=s2;i++){
        cin>>b[i];
        sum2 += b[i];
    }
    for(int i=1;i<=s3;i++){
        cin>>c[i];
        sum3 += c[i];
    }
    for(int i=1;i<=s4;i++){
        cin>>d[i];
        sum4 += d[i];
    }

    int res1 = dp_min_time(a,s1,sum1);
    int res2 = dp_min_time(b,s2,sum2);
    int res3 = dp_min_time(c,s3,sum3);
    int res4 = dp_min_time(d,s4,sum4);
    cout<<res1+res2+res3+res4;


}