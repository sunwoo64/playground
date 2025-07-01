#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int c, n;
    std::cin >> c >> n;
    
    std::vector<std::pair<int, int>> store(n);
    
    // { 비용, 몇 명 }
    std::priority_queue<std::pair<int, int>> q;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        
        store[i] = {a, b};
        q.push({-a, b});
    }
    
    while (!q.empty()) {
        int curCost = -q.top().first;
        int curNum = q.top().second;
        q.pop();
        
        if (curNum >= c) {
            std::cout << curCost;
            break;
        }
        
        for (int i = 0; i < n; i++) {
            int nextCost = curCost + store[i].first;
            int nextNum = curNum + store[i].second;
            
            q.push({-nextCost, nextNum});
        }
    }
}