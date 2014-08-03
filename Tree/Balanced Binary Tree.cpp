/****
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
****/

bool isBalancedHelp(TreeNode *root, int &height)
    {
        if (!root)
        {
            height = 0;
            return true;
        }
        
        int left_h, right_h;
        bool left_b, right_b;
        
        left_b = isBalancedHelp(root->left,left_h);
        right_b = isBalancedHelp(root->right,right_h);
        
        height = max(left_h,right_h)+1;
        
        return fabs(left_h-right_h)<=1 && left_b && right_b;
    }
    
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int height = 0;
        return isBalancedHelp(root,height);
    }