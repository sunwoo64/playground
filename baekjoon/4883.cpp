#include <iostream>
#include <vector>

#define INF 987654321

const int di[] = {-1, -1, -1, 0};
const int dj[] = {-1, 0, 1, -1};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int test = 0;
    
    while (true) {
        test++;
        int n;
        std::cin >> n;
        
        if (n == 0) break;
        
        std::vector<std::vector<int>> graph(n, std::vector<int>(3));
        std::vector<std::vector<int>> dp(n, std::vector<int>(3, INF));
        
        for (int i = 0; i < n; i++) {
            std::cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
        }
        
        dp[0][1] = graph[0][1];
        dp[0][2] = dp[0][1] + graph[0][2];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                
                for (int k = 0; k < 4; k++) {
                    int bi = i + di[k];
                    int bj = j + dj[k];
                    
                    if (0 <= bi && bi < n && 0 <= bj && bj < 3) {
                        dp[i][j] = std::min(dp[i][j], dp[bi][bj] + graph[i][j]);
                    }
                }
                
            }
        }
        
        std::cout << test << ". " << dp[n-1][1] << "\n";
        
    }
}
