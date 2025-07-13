#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    
    std::vector<std::vector<long long>> ans(10001, std::vector<long long>(3, 0));
    ans[0][0] = 1;
    
    ans[1][0] = 1;
    
    ans[2][0] = 2;
    ans[2][1] = 1;
    
    ans[3][0] = 3;
    ans[3][1] = 1;
    ans[3][2] = 1;
    
    for (int i = 4; i <= 10000; i++) {
        ans[i][2] = ans[i-3][2];
        ans[i][1] = ans[i-2][1] + ans[i][2];
        ans[i][0] = ans[i-1][0] + ans[i][1];
    }
    
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        
        std::cout << ans[n][0] << "\n";
    }
}
