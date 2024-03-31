#include <iostream>
#include <vector>

int longestIncreasingPathInMatrix(const std::vector<std::vector<int> >& mat) {
    int n = mat.size(), m = mat[0].size(), ans = 1;
    std::vector<std::vector<std::pair<int, int> > > dp(n, std::vector<std::pair<int, int> >(m, std::make_pair(1, 1)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = std::make_pair(1, 1);
            }
            else if (i == 0) {
                dp[i][j].first = mat[i][j] > mat[i][j - 1] ? dp[i][j - 1].first + 1 : dp[i][j].first;
                dp[i][j].second = mat[i][j] < mat[i][j - 1] ? dp[i][j - 1].second + 1 : dp[i][j].second;
            }
            else if (j == 0) {
                dp[i][j].first = mat[i][j] < mat[i - 1][j] ? dp[i - 1][j].first + 1 : dp[i][j].first;
                dp[i][j].second = mat[i][j] > mat[i - 1][j] ? dp[i - 1][j].second + 1 : dp[i][j].second;
            }
            else {
                int upInc = mat[i][j] > mat[i - 1][j] ? dp[i - 1][j].first + 1 : dp[i][j].first;
                int leftInc = mat[i][j] > mat[i][j - 1] ? dp[i][j - 1].first + 1 : dp[i][j].first;
                dp[i][j].first = std::max(upInc, leftInc);
                int upDesc = mat[i][j] < mat[i - 1][j] ? dp[i - 1][j].second + 1 : dp[i][j].second;
                int leftDesc = mat[i][j] < mat[i][j - 1] ? dp[i][j - 1].second + 1 : dp[i][j].second;
                dp[i][j].second = std::max(upDesc, leftDesc);
                if (mat[i][j] > mat[i - 1][j] && mat[i][j] < mat[i][j - 1]) {
                    ans = std::max(ans, dp[i - 1][j].first + dp[i][j - 1].second + 1);
                }
                if (mat[i][j] < mat[i - 1][j] && mat[i][j] > mat[i][j - 1]) {
                    ans = std::max(ans, dp[i - 1][j].second + dp[i][j - 1].first + 1);
                } 
            }
            ans = std::max(ans, std::max(dp[i][j].first, dp[i][j].second));
        }
    }
    return ans;
}

int main() {
    return 0;
}