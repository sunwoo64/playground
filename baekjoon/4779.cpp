#include <iostream>
#include <vector>

void setAns(std::vector<char>& ans, int start, int end) {
    if (start == end) {
        ans[start] = '-';
    } else {
        int p1 = start + (end - start + 1) / 3 - 1;
        int p2 = start + 2 * ((end - start + 1) / 3);
        setAns(ans, start, p1);
        setAns(ans, p2, end);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    
    while (std::cin >> n) {
        int num = 1;
        
        for (int i = 0; i < n; i++) {
            num *= 3;
        }
        
        std::vector<char> ans(num+1, ' ');
        
        setAns(ans, 1, num);
        
        for (int i = 1; i <= num; i++) {
            std::cout << ans[i];
        }
        std::cout << "\n";
    }
    
}
