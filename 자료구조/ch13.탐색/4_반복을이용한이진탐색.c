int search_binary2(int key, int low, int high)
{
	int middle;

	while(low <= high)		//아직 숫자들이 남아있다면..?
	{
		middle = (high + low) / 2;
		if(key == list[middle])
			return middle;
		else if(key > list[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;
}