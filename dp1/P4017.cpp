#include <bits/stdc++.h>
using namespace std;
//记忆化DFS

vector<int> memory(5010,-1);
struct Edge{
    int from;
    int to;
    Edge(int _from,int _to){
        from = _from;
        to = _to;
    }
};

int DFS(int start,vector< vector<Edge> > &graph){
    
    if(memory[start] != -1){
        return memory[start];
    }
    int maxl = 0;
    for(auto it:graph[start]){
        auto a = DFS(it.to,graph);
        maxl = max(maxl,a+1);
    }
    return maxl;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector< vector<Edge> > graph(n+1); 
    for(int i=1;i<=m;i++){
        int from,to;
        cin>>from>>to;
        graph[from].push_back(Edge(from,to));
        

    }
    int maxm = 0;
    for(int i=1;i<=n;i++){
        maxm = max(DFS(i,graph),maxm);
    }
    cout<<maxm;
    
}