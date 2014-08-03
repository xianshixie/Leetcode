/****
Author: Xianshi Xie
Email: xianshi.matt.xie@gmail.com

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

****/

    int minDistance(string word1, string word2) {
        int n1=word1.size()+1, n2=word2.size()+1;
        
        vector<vector<int> > res(n1,vector<int>(n2,0));
        
        for (int r=0; r<n1; ++r)
            res[r][0]=r;
            
        for (int c=0; c<n2; ++c)
            res[0][c]=c;
            
        for (int r=1; r<n1; ++r)
        {
            for (int c=1; c<n2; ++c)
            {
                if (word1[r-1]==word2[c-1])
                    res[r][c]=res[r-1][c-1];
                else
                    res[r][c]=min(res[r-1][c-1],min(res[r][c-1],res[r-1][c])) +1;
            }
        }
        
        return res[n1-1][n2-1];
        
    }