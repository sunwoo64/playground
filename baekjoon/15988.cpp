#include <iostream>
#include <vector>

#define MOD 1000000009

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    std::vector<int> ans(1000001, 0);
    
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    
    for (int i = 3; i <= 1000000; i++) {
        ans[i] = (((ans[i-1] + ans[i-2]) % MOD + ans[i-3]) % MOD) % MOD;
    }
    
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        
        std::cout << ans[n] << "\n";
    }
    
}
