#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> ans(n+1, 0);
    ans[0] = 1;
    ans[1] = 3;
    
    for (int i = 2; i <= n; i++) {
        ans[i] = (2 * ans[i-1] + ans[i-2]) % 9901;
    }
    
    std::cout << ans[n];
}
