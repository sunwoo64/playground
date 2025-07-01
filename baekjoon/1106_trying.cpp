#include <iostream>
#include <vector>

#define INF 987654321

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int c, n;
    std::cin >> c >> n;
    
    std::vector<std::pair<int, int>> store(n);
    std::vector<int> ans(c+101, INF);
    
    int sol = INF;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        
        store[i] = {a, b};
        
        ans[b] = std::min(ans[b], a);
    }
    
    for (int i = 2; i <= c+100; i++) {
        
        for (int j = 0; j < n; j++) {
            int bi = i - store[j].second;
            
            if (bi > 0) {
                ans[i] = std::min(ans[i], store[j].first + ans[bi]);
            }
            
        }
        
        if (i >= c) {
            sol = std::min(sol, ans[i]);
        }
        
    }

    std::cout << sol;
    
}