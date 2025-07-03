#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> T(n+1);
    std::vector<int> P(n+1);
    std::vector<int> dp(n+2, 0);
    
    for (int i = 1; i <= n; i++) {
        int t, p;
        std::cin >> t >> p;
        
        T[i] = t;
        P[i] = p;
    }
    
    for (int i = 1; i <= n+1; i++) {
        int ni = i + T[i];
        dp[i] = std::max(dp[i-1], dp[i]);
        if (ni <= n+1) {
            dp[ni] = std::max(dp[i] + P[i], dp[ni]);
            ans = std::max(ans, dp[ni]);   
        }
    }
    
    std::cout << dp[n+1];
    
}
