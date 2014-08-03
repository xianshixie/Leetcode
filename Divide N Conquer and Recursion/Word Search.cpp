/****
Author: Xianshi Xie
Email: xianshi.matt.xie@gmail.com
  

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

****/


bool match(vector<vector<char> > &board, vector<vector<bool> > &used, int i, int j, string word)
    {
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        
        if (used[i][j]) return false;
        
        if (board[i][j]!=word[0]) return false;
        else if (word.size()==1) return true;
        
        used[i][j]=true;
        
        //check four directions to see if word.substr(1) exists.
        if (match(board,used,i-1,j,word.substr(1))) return true;
        if (match(board,used,i+1,j,word.substr(1))) return true;
        if (match(board,used,i,j-1,word.substr(1))) return true;
        if (match(board,used,i,j+1,word.substr(1))) return true;
        
        //not exist
        used[i][j]=false;
        
        return false;        
    }
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size()==0) return false;
        int m=board.size(), n=board[0].size();
        vector<vector<bool> > used(m,vector<bool>(n,false));        
        for (int i=0; i<m; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (match(board,used,i,j,word))
                    return true;
            }
        }        
        return false;
    }