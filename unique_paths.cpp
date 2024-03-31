#include <iostream>
#include <vector>

int uniquePath(const std::vector<std::vector<int> >& grid) {
    std::vector<std::vector<int> > dp(grid.size(), std::vector<int>(grid[0].size()));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0) {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else if (i == 0) dp[i][j] = dp[i][j - 1] > 0 ? 1 : 0;
                else if (j == 0) dp[i][j] = dp[i - 1][j] > 0 ? 1 : 0;
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }       
            }
        }
    }
    return dp[grid.size() - 1][grid[0].size() - 1];
}

int main() {
    std::vector<std::vector<int> > grid = { 
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    std::cout << uniquePath(grid) << std::endl;
    return 0;
}
