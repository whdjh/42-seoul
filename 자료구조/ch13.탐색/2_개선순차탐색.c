int seq_search2(int key, int low, int high)
{
	int i;
	list[high + 1] = key;
	for(i = low; list[i] != key; i++)	//키값 찾음녀 종료
		;
	if(i == (high + 1))
		return -1;						//탐색실패
	else
		return i;						//탐색성공
}