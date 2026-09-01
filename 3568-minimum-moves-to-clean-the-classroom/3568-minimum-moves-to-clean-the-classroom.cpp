class Solution {
public:
    int minMoves(vector<string>& grid, int energy) {
        int m = grid.size();
        int n = grid[0].size();

        int sr, sc;
        int litterCount = 0;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        // Find S and assign IDs to all L cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (grid[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        int target = (1 << litterCount) - 1;

        // state = {row, col, remaining energy, collected mask}
        using State = array<int, 4>;

        queue<State> q;

        vector<vector<vector<vector<bool>>>> vis(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << litterCount, false)
                )
            )
        );

        q.push({sr, sc, energy, 0});
        vis[sr][sc][energy][0] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == target)
                    return moves;

                // If energy is 0, we can only move if we are on R.
                if (e == 0 && grid[r][c] != 'R')
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (grid[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;

                    if (ne < 0)
                        continue;

                    // Reset energy on entering R
                    if (grid[nr][nc] == 'R')
                        ne = energy;

                    int nmask = mask;

                    // Collect litter
                    if (grid[nr][nc] == 'L') {
                        nmask |= (1 << litterId[nr][nc]);
                    }

                    if (!vis[nr][nc][ne][nmask]) {
                        vis[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};