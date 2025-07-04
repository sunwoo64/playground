#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t, w;
    std::cin >> t >> w;
    
    std::vector<std::vector<int>> dp(t+2, std::vector<int>(t+1, 0));
    std::vector<int> seq(t+1, 0);
    
    int ans = 0;
    
    for (int i = 1; i <= t; i++) {
        std::cin >> seq[i];
    }
    
    for (int i = 1; i <= w+1; i++) {
        for (int j = 1; j <= t; j++) {
            dp[i][j] = std::max(dp[i-1][j-1], dp[i][j-1]);
            if (seq[j] == ((i-1) % 2 + 1)) dp[i][j]++;
            ans = std::max(ans, dp[i][j]);
        }
    }
    
    std::cout << ans;
    
}
