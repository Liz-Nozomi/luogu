#include <bits/stdc++.h>
using namespace std;

vector<int> memory; // 动态调整大小
struct Edge {
    int to;
    Edge(int _to) : to(_to) {}
};

long long DFS(int start, vector<vector<Edge> >& graph) {
    if (memory[start] != -1) {
        return memory[start];
    }
    long long maxLength = 1; // 默认路径长度为1（包括当前节点）
    for (auto& edge : graph[start]) {
        long long pathLength = DFS(edge.to, graph);
        maxLength = max(maxLength, pathLength + 1);
    }
    return memory[start] = maxLength; // 记忆化存储结果
}

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化记忆化数组和图
    memory.resize(n + 1, -1);
    vector<vector<Edge> > graph(n + 1);

    // 构建图
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].emplace_back(to);
    }

    // 计算最长路径
    long long maxPathLength = 0;
    for (int i = 1; i <= n; i++) {
        if (!graph[i].empty()) {  // 跳过孤立节点
            maxPathLength = max(maxPathLength, DFS(i, graph));
        }
    }

    cout << maxPathLength % 80112002 << endl;
    return 0;
}