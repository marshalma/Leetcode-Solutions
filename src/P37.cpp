#include <iostream>
#include "Header.hpp"

using namespace std;

class Solution {
	private:
		vector<vector<bool>> hash1;
		vector<vector<bool>> hash2;
		vector<vector<bool>> hash3;

	public:
		void solveSudoku(vector<string>& board) {
			hash1 = vector<vector<bool>>(10, vector<bool>(10, false));
			hash2 = vector<vector<bool>>(10, vector<bool>(10, false));
			hash3 = vector<vector<bool>>(10, vector<bool>(10, false));
			
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (board[i][j] == '.') continue;
					insertIntoHash(i, j, board[i][j] - '0');
				}
			}
			
			canSolveSudoku(board, 0);
		}
		
		void insertIntoHash(int i, int j, int num) {
			hash1[i][num] = true;
			hash2[j][num] = true;
			hash3[(i/3) * 3 + j/3][num] = true;
		}
		
		void removeFromHash(int i, int j, int num) {
			hash1[i][num] = false;
			hash2[j][num] = false;
			hash3[(i/3) * 3 + j/3][num] = false;
		}
		
		bool canSolveSudoku(vector<string>& board, int count) {
			while (count < 9 * 9) {
				int i = count / 9, j = count % 9;
				count++;
				if (board[i][j] != '.') continue;
				for (int num = 1; num <= 9; num++) {
					if (hash1[i][num] || hash2[j][num] || hash3[3*(i/3)+j/3][num]) continue;
					board[i][j] = '0' + num;
					insertIntoHash(i, j, num);
					if (canSolveSudoku(board, count)) return true;
					removeFromHash(i, j, num);
				}
				board[i][j] = '.';
				return false;
			}
			return true;
		}
	};
	

int main(int argc, char *argv[]) {
	vector<string> test = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
	Solution s;
	s.solveSudoku(test);
	for (auto str: test) cout << str << endl;
}