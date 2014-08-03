/*****
Binary Tree Preorder Traversal, iteratively.
****/

vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result;
        std::stack<TreeNode*> mystack;
        TreeNode *temp_ptr;
        
        if (root != NULL)
            mystack.push(root);
        
        while (!mystack.empty())
        {
            result.push_back(mystack.top()->val);
            temp_ptr = mystack.top();
            mystack.pop();
            if (temp_ptr->right != NULL) mystack.push(temp_ptr->right);
            if (temp_ptr->left != NULL) mystack.push(temp_ptr->left);
        }
        
        return result;
}