#include <iostream>
#include <vector>
#include <queue>

struct DisjointSet {
  std::vector<int> parent, rank;
  
  DisjointSet(int n) : parent(n+1), rank(n+1, 1) {
      for (int i = 1; i < n+1; i++) {
          parent[i] = i;
      }
  }
  
  int find(int u) {
      if (u == parent[u]) return u;
      return parent[u] = find(parent[u]);
  }
  
  bool canMerge(int u, int v) {
      u = find(u); v = find(v);
      
      if (u == v) return false;
      
      if (rank[u] > rank[v]) std::swap(u, v);
      parent[u] = v;
      
      if (rank[u] == rank[v]) rank[v]++;
      
      return true;
  }
};

void init_size(std::vector<int>& size, std::vector<std::vector<int>>& adj_tree, int cur) {
    if (adj_tree[cur].size()) {
        // 리프 노드가 아니라면
        
        for (int i = 0; i < adj_tree[cur].size(); i++) {
            int next = adj_tree[cur][i];
            init_size(size, adj_tree, next);
        }
        
        for (int i = 0; i < adj_tree[cur].size(); i++) {
            int next = adj_tree[cur][i];
            size[cur] += size[next];
        }
        
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, r, q;
    std::cin >> n >> r >> q;
    
    std::vector<std::vector<int>> adj(n+1, std::vector<int>());
    DisjointSet set(n+1);
    std::vector<std::vector<int>> adj_tree(n+1, std::vector<int>());
    std::queue<int> queue;
    
    std::vector<int> size(n+1, 1);
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        std::cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue.push(r);
    
    // 트리 구성
    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            
            if (set.canMerge(cur, next)) {
                queue.push(next);
                adj_tree[cur].push_back(next);
            }
        }
    }
    
    init_size(size, adj_tree, r);
    
    for (int i = 0; i < q; i++) {
        int u;
        std::cin >> u;
        
        std::cout << size[u] << "\n";
    }
    
}