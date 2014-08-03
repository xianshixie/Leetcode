/****
Author: Xianshi Xie
Email: xianshi.matt.xie@gmail.com
  
Inorder traversal of a binary tree, iteratively.

****/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> store;
        stack<TreeNode *> mystack;
        TreeNode *curr=root;
        
        bool done=false;
        
        while (!done)
        {
            if (curr) //track down to the leftmost child of curr
            {
                mystack.push(curr);
                curr = curr->left;
            }
            else
            {
                if (mystack.empty())
                    break;
                curr = mystack.top();
                store.push_back(curr->val);
                mystack.pop();
                curr = curr->right; //remember to update curr;
            }
        }
        
        return store;
    }
};