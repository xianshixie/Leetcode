/****
print a tree node in level order line by line.
****/

void levelOrderTraversal(TreeNode* root)
{
	queue<TreeNode*> que;
	que.push(root);
	int cur_cnt = 1;
	while (!que.empty()){
		TreeNode *frt=que.front();
		cout << frt->val << " ";
		que.pop();
		--cur_cnt;
		
		if (frt->left)
			que.push(frt->left);
		if (frt->right)
			que.push(frt->right);
			
		if (cur_cnt==0){
			cout << endl;
			cur_cnt = que.size();
		}
	}
}
