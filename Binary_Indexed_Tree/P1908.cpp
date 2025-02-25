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

int countIn(vector<int> &nums){
    int n = nums.size();
    if( n == 0){
        return 0;
    }
    vector<int> sorted(nums.begin(),nums.end());
    sort(sorted.begin(),sorted.end());
    unordered_map<int,int> indexmap;
    for(int i=0;i<n;i++){
        indexmap[sorted[i]] = i+1;
    }

    BIT bit;
    bit.init(n);

    int inversions = 0;
    for (int i = n - 1; i >= 0; --i) {
        int idx = indexmap[nums[i]]; // 获取当前值的离散化索引
        inversions += bit.query(idx - 1); // 查询比当前值小的数的数量
        bit.add(idx, 1); // 更新树状数组
    }

    return inversions;
}


int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;

    
    vector<int> nums(n+1);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<countIn(nums);
}