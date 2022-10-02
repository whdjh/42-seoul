int seq_search(int key, int low, int high)
{
	for(int i = low; i <= high; i++)
	{
		if(list[i] == key)
			return i;		//탐색성공! (n + 1) / 2 번 비교
		return -1;			//탐색실패! n번 비교
	}
}