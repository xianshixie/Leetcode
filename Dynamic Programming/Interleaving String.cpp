/****
Author: Xianshi Xie
Email: xianshi.matt.xie@gmail.com

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.  ]
  
****/    


    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size(), n3=s3.size();
        if ((n1+n2-n3) != 0) return false;
        
        vector<vector<bool> > store(n1+1,vector<bool>(n2+1,false));
        store[0][0] = true;
        
        for (int i=1; i<store.size();++i)
        {
            if (s1[i-1]==s3[i-1])
                store[i][0] = true;
            else
                break;
        }
        
        for (int i=1; i<store[0].size();++i)
        {
            if (s2[i-1]==s3[i-1])
                store[0][i] = true;
            else
                break;
        }
        char c1,c2,c3;
        for (int i=1; i<store.size(); ++i)
        {
            for (int j=1; j<store[0].size(); ++j)
            {
                c1 = s1[i-1];
                c2 = s2[j-1];
                c3 = s3[i+j-1];
                
                store[i][j] = (store[i-1][j] && c1==c3) || (store[i][j-1] && c2==c3);
            }
        }
        
        return store[n1][n2];
    }