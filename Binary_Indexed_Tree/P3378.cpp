#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;

    priority_queue<int, vector<int>,greater<int> > pq;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op == 1){
            int temp;
            cin>>temp;
            pq.push(temp);
        }

        else if(op == 2){
            cout<<pq.top()<<endl;
        }

        else if(op == 3){
            pq.pop();
        }
    }
}