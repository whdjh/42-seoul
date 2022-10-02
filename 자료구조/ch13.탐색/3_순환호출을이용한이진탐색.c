int search_binary(int key, int low, int high)
{
	int middle;

	if(low <= high)
	{
		middle = (low + high) / 2;
		if(key == list[middle])							//탐색성공
			return middle;
		else if(key < list[middle])						//왼쪽 부분리스트 탐색
			return search_binary(key, low, middle - 1);
		else											//오른쪽 부분리스트 탐색
			return search_binary(key, middle + 1, high);
	}
	return -1;											//탐색실패
}