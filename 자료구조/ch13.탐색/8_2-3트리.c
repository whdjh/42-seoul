tree23node *tree23_search(tree23node *root, int key)
{
	if(root == NULL)
		return False;
	else if(key == root -> data)
		return True;
	else if(root -> type == TWO_NODE)	//2-노드(차수가 2인 노드)
	{
		if(key < root -> key)
			return tree23_search(root -> left, key);
		else
			return tree23_search(root -> right, key);
	}
	else								//3-노드(차수가 3인 노드)
	{
		if(key < root -> key1)
			return tree23_search(root -> left, key);
		else if(key > root -> key2)
			return tree23_search(root -> right, key);
		else
			return tree23_search(root -> middle, key);
	}
}