#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::string> graph(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> graph[i];
    }
    
    std::pair<int, int> ans = {0, 0};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (graph[i][j] == '.' && graph[i][j+1] == '.') {
                ans.first++;
                while (j < n-1 && graph[i][j+1] == '.') j++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (graph[j][i] == '.' && graph[j+1][i] == '.') {
                ans.second++;
                while (j < n-1 && graph[j+1][i] == '.') j++;
            }
        }
    }
    
    std::cout << ans.first << " " << ans.second;
    
}
