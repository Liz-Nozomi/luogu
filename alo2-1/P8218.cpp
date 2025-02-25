#include <bits/stdc++.h>
using namespace std;
struct SegT{
    vector<int> tree;//存储树
    int n;//树大小

    void init(int size){
        n = size;
        tree.resize(4*n,0);
    }
    //原始数组的序号从start开始,node是1
    void build(const vector<int> &arr, int node,int start,int end){
        if(start == end){ //叶子节点
            tree[node] = arr[start];
        }
        else{
            int mid = (start + end)/2;
            build(arr,2*node,start,mid);//左子树
            build(arr,2*node+1,mid+1,end);//右子树
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }


    int query(int node,int start,int end,int L,int R){
        if(R < start or end < L){
            return 0;//无交集
        }
        if(L <= start and end <= R){
            return tree[node];
        }

        int mid = (start + end)/2;
        int left_sum = query(2*node,start,mid,L,R);
        int right_sum = query(2*node+1,mid+1,end,L,R);
        return left_sum + right_sum;
    }

    void update(int node,int start,int end,int idx,int value){
        if(start == end){
            tree[node] = value;

        }
        else{
            int mid = (start + end)/2;
            if(idx <= mid){
                update(2*node,start,mid,idx,value);
            }
            else{
                update(2*node+1,mid+1,end,idx,value);
            }
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
};


int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    SegT t;
    t.init(n);
    t.build(a,1,1,n);


    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        cout<<t.query(1,1,n,l,r)<<endl;
    }
}