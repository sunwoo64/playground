#include <iostream>
#include <vector>

#define MOD 1000000000
#define ZERO 1000000

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> ans(2000000);
    
    ans[ZERO] = 0;
    ans[ZERO+1] = 1;
    
    for (int i = ZERO+2; i <= ZERO+1000000; i++) {
        ans[i] = (ans[i-1] + ans[i-2]) % MOD;
    }
    
    for (int i = ZERO-1; i >= 0; i--) {
        ans[i] = (ans[i+2] - ans[i+1]) % MOD;
    }
    
    int n;
    std::cin >> n;
    
    if (ans[ZERO+n] > 0) {
        std::cout << 1 << "\n";
        std::cout << ans[ZERO+n];
    } else if (ans[ZERO+n] < 0) {
        std::cout << -1 << "\n";
        std::cout << -ans[ZERO+n];
    } else {
        std::cout << 0 << "\n" << 0;
    }
    
}
