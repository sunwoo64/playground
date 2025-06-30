#include <iostream>
#include <vector>

#define MAX 1000000

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    std::vector<int> seq(n);
    std::vector<bool> isIn(MAX+1, false);
    std::vector<int> ans(MAX+1, 0);
    
    for (int i = 0; i < n; i++) {
        std::cin >> seq[i];
        isIn[seq[i]] = true;
    }
    
    for (int i = 0; i < n; i++) {
        int cur = seq[i];
        
        // 에라토스테네스의 체 응용
        for (int i = 2; cur * i <= MAX; i++) {
            int next = cur * i;
            if (isIn[next]) {
                ans[next]--;
                ans[cur]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << ans[seq[i]] << " ";
    }
    
}