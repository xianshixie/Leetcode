/**********************
Problem definition: 

Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
**********************/

//Algorithm: BFS + DFS

class Solution {
public:

    void dfs_help(vector<vector<string> > &res, vector<string> & sol, string start, string cur, unordered_map<string,vector<string> > &string_map, int path_len)
    {
        
        sol[path_len-1]=cur;
        
        if (cur==start)
        {
            res.push_back(sol);
            return;
        }
        
        
        for (int i=0; i<string_map[cur].size();++i)
        {
            dfs_help(res,sol,start,string_map[cur][i],string_map,path_len-1);
        }
        
        
        
    }
    
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        vector<vector<string> > res;
        if (start==end)
            return vector<vector<string> > (1,vector<string>(1,start));
            
        queue<string> myque;
        unordered_map<string,vector<string>> visited; //child->parents
        unordered_set<string> que_map;
        myque.push(start);
        visited[start]=vector<string>(0);
        
        int lev0=1, path_len=INT_MAX, cur_len=0;
        
        while (!myque.empty())
        {
            string myfront=myque.front();
            myque.pop();
            --lev0;
            
            
            
            for (int i=0; i<myfront.size(); ++i)
            {
                string temp=myfront;
                for (int j=0; j<26; ++j)
                {
                    temp[i] = j+'a';
                    if (temp==end){
                        path_len = cur_len+2;
                        visited[temp].push_back(myfront);
                    }
                    else if (dict.find(temp)!=dict.end())
                    {
                        if (visited.find(temp)==visited.end()){
                            visited[temp].push_back(myfront);
                            myque.push(temp);
                            que_map.insert(temp);
                        }
                        else if (que_map.find(temp)!=que_map.end()){
                            visited[temp].push_back(myfront);
                        }
                        
                    }
                }
            }
            
            
            
            if (lev0==0)
            {
                lev0=myque.size();
                ++cur_len;
                que_map.clear();
            }
            
            if (cur_len==path_len-1) break;
            
        }
        
        if (path_len==INT_MAX) return res;
        
        vector<string> sol(path_len);
        dfs_help(res,sol,start,end,visited,path_len);
            
        return res;
        
    }
};