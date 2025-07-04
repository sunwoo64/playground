#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    std::vector<int> seq(n);
    std::vector<int> len(n, 1);
    
    int max = 1;
    
    for (int i = 0; i < n; i++) {
        std::cin >> seq[i];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[i] > seq[j]) {
                len[i] = std::max(len[i], len[j] + 1);
            }
        }
        max = std::max(max, len[i]);
    }
    
    std::cout << max << "\n";
    
    int before = 1001;
    
    std::vector<int> ans;
    
    for (int i = n-1; i >= 0; i--) {
        if (max == len[i] && before > seq[i]) {
            max--;
            before = seq[i];
            ans.push_back(seq[i]);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    for (auto i : ans) {
        std::cout << i << " ";
    }
    
}
