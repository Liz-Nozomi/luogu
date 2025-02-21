#include <iostream>
using namespace std;
long long dp[101][101],n,m,a[101]; //定义数组
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<=m;i++){dp[i][0]=1;} //初始化，不管有多少种花，只要是0盆花，就只有1种可能性，啥都不放

    for(int i=1;i<=n;i++)//几种花
        for(int j=1;j<=m;j++)//几盆花
            for(int k=j;k>=j-a[i];k--)//这种花放多少盆？我们用变量k来循环
            {    
	            if(k>=0){
                    dp[i][j]+=dp[i-1][k]%1000007;
                    dp[i][j]%=1000007;
                }//每次mod以防万一
                else break; //如果超出限制就退出循环
    }
    cout<<dp[n][m]<<endl; //输出（因为每次都mod了所以最后不用mod）
}
