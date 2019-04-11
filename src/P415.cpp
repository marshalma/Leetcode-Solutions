#include <iostream>
#include <queue>
using namespace std;

class Solution {
	int m, n;
public:
	void climbing(vector<vector<int>>& matrix, vector<vector<bool>>& dp, vector<vector<bool>>& visited, pair<int, int> cur_coor) {
		queue<pair<int, int>> q;
		q.push(cur_coor);
		while (q.size()) {
			int this_size = q.size();
			for (int i = 0; i < this_size; i++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				if (x+1 < m && !visited[x+1][y] && matrix[x+1][y] >= matrix[x][y]) {
					dp[x+1][y] = visited[x+1][y] = true;
					q.push(make_pair(x+1, y));
				}
				if (x-1 >= 0 && !visited[x-1][y] && matrix[x-1][y] >= matrix[x][y]) {
					dp[x-1][y] = visited[x-1][y] = true;
					q.push(make_pair(x-1, y));
				}
				if (y+1 < n && !visited[x][y+1] && matrix[x][y+1] >= matrix[x][y]) {
					dp[x][y+1] = visited[x][y+1] = true;
					q.push(make_pair(x, y+1));
				}
				if (y-1 >= 0 && !visited[x][y-1] && matrix[x][y-1] >= matrix[x][y]) {
					dp[x][y-1] = visited[x][y-1] = true;
					q.push(make_pair(x, y-1));
				}
			}
		}
		
	}

	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int, int>> res;
		m = matrix.size();
		n = m?matrix[0].size():0;
		vector<vector<bool>> dp1(m, vector<bool>(n, false));
		vector<vector<bool>> dp2(m, vector<bool>(n, false));
		vector<vector<bool>> visited1(m, vector<bool>(n, false));
		vector<vector<bool>> visited2(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			visited1[i][0] = visited2[i][n-1] = dp1[i][0] = dp2[i][n-1] = true;
		}
		for (int i = 0; i < n; i++) {
			visited1[0][i] = visited2[m-1][i] = dp1[0][i] = dp2[m-1][i] = true;
		}
		
		for (int k = m-1; k > 0; k--) {
			climbing(matrix, dp1, visited1, make_pair(k, 0));
			climbing(matrix, dp2, visited2, make_pair(k, n-1));
		}
		for (int k = n-1; k> 0; k--) {
			climbing(matrix, dp1, visited1, make_pair(0, k));
			climbing(matrix, dp2, visited2, make_pair(m-1, k));
		}
		
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (dp1[i][j] && dp2[i][j]) res.push_back(make_pair(i, j));
			}
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<vector<int>> matrix{{3,3,3,3,3,3},{3,0,3,3,0,3},{3,3,3,3,3,3}};	
	s.pacificAtlantic(matrix);
	return 0;
}