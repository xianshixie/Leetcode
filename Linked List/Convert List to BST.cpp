/****
Author: Xianshi Xie
Email: xianshi.matt.xie@gmail.com

Convert a sorted linked list to a balanced binary search tree
****/

    TreeNode *build(ListNode *&h, int st, int end)
    {
        if (st>end) return NULL;
        int mid=(st+end)/2;
        TreeNode *lt = build(h,st,mid-1);
        TreeNode *root=new TreeNode(h->val);
        root->left = lt;
        h = h->next;
        if (h)
            root->right = build(h,mid+1,end);
        
        return root;
        
    }
    TreeNode *sortedListToBST(ListNode *head) {
        
        if (!head) return NULL;
        ListNode *cur=head;
        int n=0;
        while (cur)
        {
            ++n;
            cur=cur->next;
        }
        
        return build(head,1,n);
        
    }

