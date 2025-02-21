#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;

    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    bool graph[50][50];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>graph[i][j];
            //graph[j][i] = graph[i][j];
        }

    }
    vector<int> dp(n+1,0);
    vector<int> pre(n+1,-1);
    //dp[i] 表示以第i个地窖结尾的地雷数量
    int ans = 0;
    int ansi = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(graph [j][i] == 1 and dp[j] > dp[i]){
                dp[i] = dp[j];
                pre[i] = j;
            }
        }
        dp[i] += a[i];
        if(dp[i] > ans){
            ans = dp[i];
            ansi = i;
        }
    }
    vector<int> res;
    register int temp = ansi;
    while(temp != -1){
        res.push_back(temp);
        temp = pre[temp];
    }
    reverse(res.begin(),res.end());
    
    temp = 0;
    for(auto it:res){
        cout<<it;
        if(temp < res.size()-1){
            cout<<" ";
        }
        temp++;
    }
    cout<<endl;
    cout<<ans;


}