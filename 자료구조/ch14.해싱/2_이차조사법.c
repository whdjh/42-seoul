void hash_qp_add(element item, element ht[])
{
	int i, hash_value, inc = 0;
	hash_value = i = hash_function(item.key);

	while(!empty(ht[i]))
	{
		if(equal(item, ht[i]))
		{
			fprintf(stderr, "중복\n");
			exit(1);
		}
		i = (hash_value + inc * inc) % TABLE_SIZE;		//아차 조사법
		inc = inc + 1;									//아차 조사법
		if(i == hash_value)
		{
			fprintf(stderr, "가득참\n");
			exit(1);
		}
	}
	ht[i] = item;
}