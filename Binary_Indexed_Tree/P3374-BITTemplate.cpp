#include <bits/stdc++.h>
using namespace std;

struct BIT{
    vector<int> tree;
    int n;
    
    void init(int size){
        n=size;
        tree.resize(n+1,0);
    }

    void add(int i,int addn){
        while(i <= n){
            tree[i] += addn;
            i += i & -i;
        }
    }

    int query(int i){
        int sum = 0;
        while(i>0){
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }
};

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;

    BIT t;
    t.init(n);

    vector<int> nums(n+1);
    for(int i=1;i<=n;i++){
        cin>>nums[i];
        t.add(i,nums[i]);
    }




    for(int j=0;j<m;j++){
        int op;
        cin>>op;
        if(op == 1){
            int x,k;
            cin>>x>>k;
            t.add(x,k);


        }
        if(op == 2){
            int x,y;
            cin>>x>>y;
            cout<< t.query(y) - t.query(x-1)<<endl;
        }
    }

}