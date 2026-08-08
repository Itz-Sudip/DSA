class Solution {
public:
    bool possible(vector<vector<char>>& board, char c,int row,int col){
        for(int k=0;k<9;k++){
            if(board[row][k]==c) return false;
        }
        for(int k=0;k<9;k++){
            if(board[k][col]==c) return false;
        }

        int sr=3*(row/3);
        int sc=3*(col/3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[sr+ i][sc + j] == c) return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(possible(board,c,i,j)){
                            board[i][j]=c;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }  
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};