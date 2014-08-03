/****
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
****/

int max_path_help(TreeNode *root, int &mymax)
    {
        if (!root) return 0; //don¡¯t change mymax value
        int left_sum = max_path_help(root->left,mymax);
        int right_sum = max_path_help(root->right,mymax);
        
        int root_max = root->val;
        if (left_sum>0) root_max+=left_sum;
        if (right_sum>0) root_max+=right_sum;
        
        if (root_max>mymax) mymax = root_max;        
        return max(root->val, max(left_sum,right_sum)+root->val);        
    }
    int maxPathSum(TreeNode *root) {
        int max = 0, mymax = INT_MIN;
        max = max_path_help(root,mymax);
        return std::max(max,mymax);
    }