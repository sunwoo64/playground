#include <iostream>
#include <vector>
#include <queue>

const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 1));
    
    std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
    
    int ans = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pq.push({-graph[i][j], {i, j}});
        }
    }
    
    while (!pq.empty()) {
        int ci = pq.top().second.first;
        int cj = pq.top().second.second;
        pq.pop();
                
        for (int k = 0; k < 4; k++) {
            int ni = ci + di[k];
            int nj = cj + dj[k];
                    
            if (0 <= ni && ni < n && 0 <= nj && nj < n && graph[ci][cj] < graph[ni][nj] && dp[ni][nj] <= dp[ci][cj]) {
                dp[ni][nj] = dp[ci][cj] + 1;
                pq.push({-graph[ni][nj], {ni, nj}});
                ans = std::max(ans, dp[ni][nj]);
            }
        }
    }
    
    std::cout << ans;
}
