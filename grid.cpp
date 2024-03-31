#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(vector<vector<char> >& grid, vector<vector<bool> >& visited, unordered_set<char> st, 
int i, int j, int n, int m, vector<pair<int, int> >& ans) {
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (st.empty()) {
        return;
    }
    if (!visited[i][j]) {
        if (st.count(grid[i][j])) {
            st.erase(grid[i][j]);
            ans.push_back(make_pair(i, j));
            visited[i][j] = true;
            dfs(grid, visited, st, i + 1, j, n, m, ans);
            dfs(grid, visited, st, i - 1, j, n, m, ans);
            dfs(grid, visited, st, i, j + 1, n, m, ans);
            dfs(grid, visited, st, i, j - 1, n, m, ans);
        }
    }
}

vector<pair<int, int> > gridMatching1(vector<vector<char> >& grid, string word) {
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<bool> > visited(n, vector<bool>(m));
            unordered_set<char> st;
            for (char c : word) st.insert(c);
            dfs(grid, visited, st, i, j, n, m, ans);
            if (ans.size() == word.size()) {
                return ans;
            }
            ans.clear();
        }
    }
}


int main() {
    char a[] = {'c', 'c', 't', 'n', 'a', 'x'};
    char b[] = {'c', 'c', 'a', 't', 'n', 't'};
    char c[] = {'a', 'c', 'n', 'n', 't', 't'};
    char d[] = {'t', 'n', 'i', 'i', 'p', 'p'};
    char e[] = {'a', 'o', 'o', 'o', 'a', 'a'};
    char f[] = {'s', 'a', 'a', 'a', 'o', 'o'};
    char g[] = {'k', 'a', 'i', 'o', 'k', 'i'};

    vector<vector<char> > grid;
    grid.push_back(vector<char>(a, a + sizeof(a) / sizeof(a[0])));
    grid.push_back(vector<char>(b, b + sizeof(b) / sizeof(b[0])));
    grid.push_back(vector<char>(c, c + sizeof(c) / sizeof(c[0])));
    grid.push_back(vector<char>(d, d + sizeof(d) / sizeof(d[0])));
    grid.push_back(vector<char>(e, e + sizeof(e) / sizeof(e[0])));
    grid.push_back(vector<char>(f, f + sizeof(f) / sizeof(f[0])));
    grid.push_back(vector<char>(g, g + sizeof(g) / sizeof(g[0])));

    vector<pair<int, int> > ans = gridMatching1(grid, "catnip");
    //cout << ans.size();
    for (auto& it : ans) cout << it.first << ", " << it.second << endl;

    return 0;
}