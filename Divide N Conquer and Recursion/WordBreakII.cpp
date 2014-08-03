/***********************
Problem definition:

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

**************************/

/************
Algorithm: Dynamic programming + DFS
*************/

class Solution {
public:
    void dfs_help(vector<string> &res, string &sol, string &s, unordered_set<string> &dict, vector<bool> &exists, int pos)
    {
        if (pos==s.size())
        {
            res.push_back(sol);
            return;
        }           
        
        
        for (int i=pos; i<s.size(); ++i)
        {
            string subs=s.substr(pos,i-pos+1);
            if (dict.find(subs)==dict.end())
                continue;
            else if (i<s.size()-1 && !exists[i+1])
                continue;
            else
            {
                if (pos>0)
                    sol+=(' ');
                sol+=(subs);
                dfs_help(res,sol,s,dict,exists,i+1);
                sol.erase(sol.size()-subs.size());
                if (pos>0)
                    sol.erase(sol.size()-1,1);
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n=s.size();
        vector<bool> exists(n,false);
        if (dict.find(s.substr(n-1,1))!=dict.end()) exists[n-1]=true;
        for (int i=n-2; i>=0; --i)
        {
            if (dict.find(s.substr(i,n-i))!=dict.end())
            {
                exists[i]=true;
                continue;
            }
            for (int j=i; j<n-1; ++j)
            {
                if (exists[j+1] && dict.find(s.substr(i,j-i+1))!=dict.end())
                {
                    exists[i]=true;
                    break;
                }
            }
        }
        
        vector<string> res;
        string sol;
        
        dfs_help(res,sol,s,dict,exists,0);
        
        return res;
        
    }
};