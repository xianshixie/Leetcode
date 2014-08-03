/****
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
****/

    int getRoot(vector<int> &inorder, int root, int st, int end)
    {
        for (int i=st; i<=end; ++i)
        {
            if (inorder[i]==root) return i;
        }
    }
    
    TreeNode *buildHelp(vector<int> &inorder, vector<int> &postorder, int pst, int pend, int ist, int iend)
    {
        if (pst>pend)
            return NULL;
        
        TreeNode *root=new TreeNode(postorder[pend]);
        int rin=getRoot(inorder,postorder[pend],ist,iend);
        int Lsize=rin-ist, Rsize=iend-rin;
        if (Lsize>0)
            root->left = buildHelp(inorder,postorder,pst,pst+Lsize-1,ist,rin-1);
        if (Rsize>0)
            root->right = buildHelp(inorder,postorder,pst+Lsize,pend-1,rin+1,iend);
            
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        //if (inorder.empty()) return NULL;
        return buildHelp(inorder,postorder,0,postorder.size()-1,0,inorder.size()-1);
    }