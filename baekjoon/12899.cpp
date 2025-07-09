#include <iostream>
#include <vector>

void update(std::vector<int>& tree, int node, int start, int end, int index) {
    if (index < start || end < index) return;
    if (start == end) tree[node]++;
    else {
        int mid = (start + end) / 2;
        update(tree, 2*node, start, mid, index);
        update(tree, 2*node+1, mid+1, end, index);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void query(std::vector<int>& tree, int node, int start, int end, int value) {
    if (start == end) {
        std::cout << start << "\n";
        tree[node]--;
    } else {
        
        int mid = (start + end) / 2;
        
        if (tree[node*2] < value) {
            query(tree, node*2+1, mid+1, end, value-tree[node*2]);
        } else {
            query(tree, node*2, start, mid, value);
        }
        
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    std::vector<int> tree(4194304, 0);
    
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        
        if (a == 1) {
            update(tree, 1, 1, 2000000, b);
        } else if (a == 2) {
            query(tree, 1, 1, 2000000, b);
        }
    }
    
}
