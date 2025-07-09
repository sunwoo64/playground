#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string s;
    
    std::cin >> s;
    
    std::vector<std::vector<int>> pre_sum(s.length(), std::vector<int>(26, 0));
    
    for (int i = 0; i < s.length(); i++) {
        pre_sum[i][s[i]-'a']++;
        
        if (i != 0) {
            for (int j = 0; j < 26; j++) {
                pre_sum[i][j] += pre_sum[i-1][j];
            }
        }
    }
    
    int q;
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        char a;
        int b, c;
        
        std::cin >> a >> b >> c;
        
        if (b == 0) std::cout << pre_sum[c][a-'a'];
        else std::cout << pre_sum[c][a-'a'] - pre_sum[b-1][a-'a'];
        std::cout << "\n";
    }
    
}
