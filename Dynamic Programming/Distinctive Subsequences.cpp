/****
Author: Xianshi Xie
Email: xianshi.matt.xie@gmail.com

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
****/

int numDistinct(string S, string T) {
        int n=S.size(),m=T.size(),cnt=0;
        if (n==0) return 0;
        vector<vector<int> > store(n,vector<int>(m,0));
        
        for (int i=0; i<n; ++i)
            store[i][0]=S[i]==T[0]?++cnt:cnt;
        
        for (int i=1;i<n;++i)
        {
            for (int j=1; j<m; ++j)
            {
                if (S[i]==T[j])
                {
                    store[i][j] = store[i-1][j-1] + store[i-1][j];
                }
                else
                    store[i][j] = store[i-1][j];
            }
        }
        
        return store[n-1][m-1];
        
    }