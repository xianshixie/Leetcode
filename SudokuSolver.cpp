/********************
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
********************/

//Algorithm: Backtracking

class Solution {
public:
    bool isValid(vector<vector<char> > &board, int row, int col)
    {
        //if (board[row][col]=='.') return true;
        //check row
        for (int i=0;i<board.size();++i)
        {
            if (col!=i && board[row][i]==board[row][col])
                return false;
        }
        
        //check column
        for (int i=0;i<board.size();++i)
        {
            if (row!=i && board[i][col]==board[row][col])
                return false;
        }
        //check box
        int rb = row/3 *3;
        int re = row/3 *3 +2;
        int cb = col/3 *3;
        int ce = col/3 *3 +2;
        
        for (int r=rb;r<=re;++r)
        {
            for (int c=cb;c<ce;++c)
            {
                if (row!=r && col!=c && board[r][c]==board[row][col])
                    return false;
            }
        }
        
        return true;
    }
    
    bool help(vector<vector<char> > &board, int row, int col)
    {
        if (row==board.size())
            return true;
            
            
        if (board[row][col]=='.')
        {
            for (int k=1; k<=9; ++k)
            {
                board[row][col] = k+'0';
                if (isValid(board,row,col))
                {
                    if (help(board,row+(col+1)/9,(col+1)%9))
                            return true;
                }
                board[row][col] = '.';
                
            }
            
            return false;
        }
        else
        {
            if (isValid(board,row,col))
            {
                if (help(board,row+(col+1)/9,(col+1)%9))
                    return true;
            }
            else
                return false;
        }
            
        
    }
    void solveSudoku(vector<vector<char> > &board) {
        help(board,0,0);
    }
};