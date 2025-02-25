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
    int n,m;
    cin>>n>>m;
    BIT t;
    t.init(n);

    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        t.add(i,temp);
    }

    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op == 1){
            
        }
    }
}