// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

class Solution {
public:
    void updateCell(vector<vector<int>>& board, int row, int col) {
	int numOfLiveCells = board[row][col];

	if (row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] > 0)
		numOfLiveCells++;
	if (row - 1 >= 0 && board[row - 1][col] > 0)
		numOfLiveCells++;
	if (row - 1 >= 0 && col + 1 < board[row].size() && board[row - 1][col + 1] > 0)
		numOfLiveCells++;
	if (col + 1 < board[row].size() && board[row][col + 1] > 0)
		numOfLiveCells++;
	if (row + 1 < board.size() && col + 1 < board[row].size() && board[row + 1][col + 1] > 0)
		numOfLiveCells++;
	if (row + 1 < board.size() && board[row + 1][col] > 0)
		numOfLiveCells++;
	if (row + 1 < board.size() && col - 1 >= 0 && board[row + 1][col - 1] > 0)
		numOfLiveCells++;
	if (col - 1 >= 0 && board[row][col - 1] > 0)
		numOfLiveCells++;

	board[row][col] = board[row][col] == 1 ? numOfLiveCells : -numOfLiveCells;
}

void gameOfLife(vector<vector<int>>& board) {
	for (int i = 0; i<board.size(); i++) {
		for (int j = 0; j<board[i].size(); j++)
			updateCell(board, i, j);
	}

	for (int i = 0; i<board.size(); i++) {
		for (int j = 0; j<board[i].size(); j++) {
			if (board[i][j] > 0) {
				if (board[i][j] - 1 < 2 || board[i][j] - 1 > 3)
					board[i][j] = 0;
				else
					board[i][j] = 1;
			}
			else {
				if (board[i][j] == -3)
					board[i][j] = 1;
				else
					board[i][j] = 0;
			}
		}
	}
}
};
