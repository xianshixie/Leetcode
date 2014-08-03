/****
Author: Xianshi Xie
Email: xianshi.matt.xie@gmail.com

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
  
****/    


    void build_map(string &s, vector<vector<bool> > &pmap)
    {
        int n=s.size();
        for (int r=n-2; r>=0; --r)
        {
            for (int c=r+1; c<n; ++c)
            {
                pmap[r][c] = pmap[r+1][c-1] && s[r]==s[c];
            }
        }
    }
        
    vector<vector<string>> partition(string s) {
        vector<vector<bool> > palindrome_map(s.size(),vector<bool>(s.size(),true));
        build_map(s,palindrome_map);
        
        vector<vector<vector<string> > > store(s.size());
        store[0].push_back(vector<string>(1,s.substr(0,1)));
        
        for (int i=1; i<s.size(); ++i)
        {
            if (palindrome_map[0][i])
                store[i].push_back(vector<string>(1,s.substr(0,i+1)));
            
            for (int j=1; j<=i; ++j)
            {
                if (palindrome_map[j][i])
                {
                    vector<vector<string> > temp(store[j-1]);
                    for (int k=0; k<temp.size(); ++k)
                        temp[k].push_back(s.substr(j,i-j+1));                        
                    store[i].insert(store[i].end(),temp.begin(),temp.end());
                }
            }            
        }        
        return store[s.size()-1];       
        
    }