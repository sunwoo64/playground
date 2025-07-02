#include <iostream>
#include <vector>

bool setFal(std::vector<std::vector<int>>& isFal, std::vector<int>& seq, int s, int e) {
    
    if (isFal[s][e] != -1) return isFal[s][e];
    
    if (seq[s] != seq[e]) {
        isFal[s][e] = 0;
        return false;
    }
    
    if (s+1 > e-1) return isFal[s][e] = (seq[s] == seq[e]);
    
    if (s == e) {
        return isFal[s][e] = 1;
    } else {
        bool state = setFal(isFal, seq, s+1, e-1);
        
        if (s+1 <= e-1 && state) {
            isFal[s][e] = 1;
            return true;
        }
        
        return state;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> isFal(n+1, std::vector<int>(n+1, -1)); 
    std::vector<int> seq(n+1);
    
    for (int i = 1; i < n+1; i++) {
        std::cin >> seq[i];
    }
    
    int m;
    std::cin >> m;
    
    for (int i = 0; i < m; i++) {
        int s, e;
        std::cin >> s >> e;
        
        std::cout << setFal(isFal, seq, s, e) << "\n";
    }
    
}
