#include <iostream>
#include <vector>

bool setFal(std::vector<std::vector<int>>& isFal, std::vector<int>& seq, int s, int e) {
    if (s == e) {
        isFal[s][e] = 1;
        return true;
    } else {
        
        if (isFal[s][e] != -1) return isFal[s][e];
        
        else if (s+1 <= e-1 && setFal(isFal, seq, s+1, e-1)) {
            isFal[s][e] = true;
        }
        
        return seq[s] == seq[e];
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
