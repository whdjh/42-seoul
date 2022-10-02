void hash_dh_add(element item, element ht[])
{
	int i, hash_value, inc;
	hash_value = i = hash_function(item, key);
	inc = hash_function2(item.key);
	while(!empty(ht[i]))
	{
		if(equal(item, ht[i]))
		{
			fprintf(stderr, "중복\n");
			exit(1);
		}
		i = (i + inc) % TABLE_SIZE;	//이중해싱법
		if(i == hash_value)
		{
			fprintf(stderr, "가득참\n");
			exit(1);
		}
	}
	ht[i] = item;
}