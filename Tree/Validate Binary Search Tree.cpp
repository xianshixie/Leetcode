/****
Author: Xianshi Xie
Email: xianshi.matt.xie@gmail.com
  
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

****/

    bool help(TreeNode *root, int min, int max)
    {
        if (!root) return true;
        return root->val > min
            && root->val < max
            && help(root->left,min,root->val)
            && help(root->right,root->val,max);            
    }
    bool isValidBST(TreeNode *root) {
        return help(root,INT_MIN,INT_MAX);
    }