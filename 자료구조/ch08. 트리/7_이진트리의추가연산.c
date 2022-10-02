//노드개수구하기
int get_node_count(treenode *node)
{
	int count = 0;

	if(node != NULL)
		count = 1 + get_node_count(node -> left) + get_node_count(node -> right);
	return count;
}

//단말노드개수구하기
int get_leaf_count(treenode *node)
{
	int count = 0;
	
	if(node != NULL)
	{
		if(node -> left == NULL && node -> right == NULL)
			return 1;
		else
			count = get_leaf_count(node -> left) + get_leaf_count(node -> right);
	}
	return count;
}

//높이구하기
int get_height(treenode *node)
{
	int height;

	if(node != NULL)
		height = 1 + max(get_height(node -> left), get_height(node -> right));
	return height;
}