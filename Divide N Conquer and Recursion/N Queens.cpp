/****
Author: Xianshi Xie
Email: xianshi.matt.xie@gmail.com
  

The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

****/



    bool underAttact(vector<int> &queens, int i, int j)
    {
        for (int col=0;col<j;++col)
        {
            if (queens[col] == queens[j] || abs(queens[col]-queens[j])==(j-col)) return true;
        }        
        return false;
    }
    
    void placeQueens(vector<vector<string> > &result, vector<int> &queens, int curCol, int n)
    {
        if (curCol>=n)
        {
            vector<string> sol(n,string(n,'.'));
            for (int i=0;i<n;++i)
                sol[queens[i]][i] = 'Q';
            result.push_back(sol);
            return;
        }
        
        for (int i=0; i<n; ++i)
        {
            queens[curCol] = i;
            if (!underAttact(queens, i, curCol)){
                placeQueens(result,queens,curCol+1,n);
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        
        vector<vector<string> > result;        
        vector<int> queens(n,-1);        
        placeQueens(result,queens,0,n);        
        return result;               
    }