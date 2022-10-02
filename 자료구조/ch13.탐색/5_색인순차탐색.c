int search_index(int key, int n)											//n은 전체 데이터 수
{
	int i, low, high;

	if(key < lost[0] || key > list[n - 1])									//키 값이 리스트 범위 내의 값이 아니면 탐색 종료
		return -1;
	for(i = 0; i < INDEX_SIZE; i++)											//INDEX_SIZE는 인덱스 테이블 크기, 인덱스 테이블을 조사하여 해당키의 구간 설정
	{
		if(index_lost[i].key <= key && index_list[i + 1].key > key)
			break;
		if(i == INDEX_SIZE)													//인덱스 테이블이 끝이면
		{
			low = index_list[i - 1].index;
			high = n;
		}
		else
		{
			low = index_list[i].index;
			high = index_list[i + 1].index;
		}
		return seq_search(key, low, high);									//예상되는 범위를 순차 탐색
	}
}