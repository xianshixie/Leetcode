/****
Flatten a tree to a circular double-linked list in inorder
****/

void flatten_help(TreeNode *root, TreeNode *&prev, TreeNode *&h){
	
	if (!root) return;
	
	TreeNode *rleft=root->left;
	TreeNode *rright=root->right;
	
	flatten_help(rleft,prev,h);
	
	if (!prev){
		prev=root;
		h=root;
	}else
	{
		prev->right=root;
		root->left=prev;
		prev=root;
	}
	
	flatten_help(rright,prev,h);
	
}

TreeNode *flatten(TreeNode *root)
{
	TreeNode *prev=NULL, *h=NULL;
	flatten_help(root,prev,h);
	h->left=prev;
	prev->right=h;
	return h;
}