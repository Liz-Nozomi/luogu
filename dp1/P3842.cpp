#include <bits/stdc++.h>
using namespace std;

struct line{
    int left;
    int right;
    int length;
    line(int _left,int _right){
        left = _left;
        right = _right;
        length = abs(_left - _right);
    }
    line(){}
};



int main(){
    int n;
    cin>>n;
    int dp[20010][2];//dp[i][0] 代表结尾在某行左边，dp[i][1] 代表结尾在某行右边；
    vector<line> vl(n+1);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        vl[i]=line(a,b);
    }
    dp[1][0] = vl[1].left -1 + 2* vl[1].length;
    dp[1][1] = vl[1].left -1 + vl[1].length;

    for(int i=2;i<=n;i++){
        dp[i][0] = vl[i].length + min(dp[i-1][0] + abs(vl[i-1].left - vl[i].right) + 1, dp[i-1][1] + abs(vl[i-1].right - vl[i].right) + 1);
        dp[i][1] = vl[i].length + min(dp[i-1][0] + abs(vl[i-1].left - vl[i].left) + 1, dp[i-1][1] + abs(vl[i-1].right - vl[i].left) + 1);

    }
    cout<<min(dp[n][0]+n-vl[n].left,dp[n][1]+n-vl[n].right) ;
}