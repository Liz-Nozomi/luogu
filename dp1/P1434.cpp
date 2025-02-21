#include <bits/stdc++.h>

using namespace std;

struct node{
    int i,j,num;
};

bool cmp1(node a,node b){
    return a.num > b.num;
}
priority_queue<node,vector<node>, decltype(&cmp1)> pq(cmp1);

int main(){
    int n,m;
    cin>>n>>m;

    int graph[110][110];
    int dp[110][110];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            register node temp;
            cin>>temp.num;
            graph[i][j] = temp.num;
            temp.i = i;
            temp.j = j;
            dp[i][j] = 1;
            pq.push(temp);
        }
    }
    

    

    int maxn = 0;

    while(!pq.empty()){
        node now = pq.top();
        pq.pop();
        int i = now.i;
        int j = now.j;
        int weight = now.num;

        if(i > 1 and graph[i-1][j] < weight) dp[i][j] = max(dp[i][j],dp[i-1][j]+1 );
        if(j > 1 and graph[i][j-1] < weight) dp[i][j] = max(dp[i][j],dp[i][j-1]+1 );
        if(i < n and graph[i+1][j] < weight) dp[i][j] = max(dp[i][j],dp[i+1][j]+1 );
        if(j < m and graph[i][j+1] < weight) dp[i][j] = max(dp[i][j],dp[i][j+1]+1 );

        if(dp[i][j] > maxn) maxn = dp[i][j];

    }
    cout<<maxn;


}