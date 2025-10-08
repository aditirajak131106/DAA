#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isSafe(int board[], int row, int col, int n){
	for(int i = 0; i<row; i++){
		if (board[i] == col || abs(board[i]-col) == abs(i- row)){
			return false;
		}
	}
	return true;
}
void solve(int board[], int row, int n, int *count){
	if (row == n){
		(*count)++;
		return;
	}
	for (int col = 0; col<n; col++){
		if (isSafe(board, row, col, n)){
			board[row] = col;
			solve(board, row+1, n, count);
		}
	}
}
int nQueen(int n){
	int *board = (int *)malloc(n * sizeof(int));
	int count = 0;
	solve(board, 0, n , &count);
	free(board);
	return count;
}
int main(){
	int n;
	scanf("%d", &n);
	int result = nQueen(n);
	printf("%d", result);
	return 0;
}
