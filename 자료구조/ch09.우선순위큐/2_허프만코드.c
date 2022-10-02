#include <stdio.h>
#include <stdlib.h>
#define MAX_ELELMENT 200

typedef struct treenode {
	int weight;
	char ch;
	struct treenode *left;
	struct treenode *right;
} treenode;

typedef struct {
	treenode *ptree;
	char ch;
	int key;
} element;

typedef struct {
	element heap[MAX_ELELMENT];
	int heap_size;
} heaptype;

heaptype *create()
{
	return (heaptype *)malloc(sizeof(heaptype));
}

void init(heaptype *h)
{
	h -> heap_size = 0;
}

//현재요소의 개수가 heap_size인 히프에 item삽입!
void insert_min_heap(heaptype *h, element item)
{
	int i;
	i = ++(h -> heap_size);

	while((i != 1) && (item.key > h -> heap[i / 2].key))	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	{
		h -> heap[i] = h -> heap[i / 2];
		i /= 2;
	}
	h -> heap[i] = item;									//새로운 노드 삽입
}

element delete_min_heap(heaptype *h)
{
	int parent, child;
	element item, tmp;

	item = h -> heap[1];
	tmp = h -> heap[(h -> heap_size)--];
	parent = 1;
	child = 2;
	while(child <= h -> heap_size)				//현재 노드의 자식 중 더 큰 자식노드를 찾는다.
	{
		if((child < h -> heap_size) && (h -> heap[child].key) > h -> heap[child + 1].key)
			child++;
		if(tmp.key < h -> heap[child].key)
			break;
		h -> heap[parent] = h -> heap[child];	//한단계 아래로 이동.
		parent = child;
		child *= 2;
	}
	h -> heap[parent] = tmp;
	return item;
}

//이진트리생성함수
treenode *make_tree(treenode *left, treenode *right)
{
	treenode *node = (treenode *)malloc(sizeof(treenode));
	node -> left = left;
	node -> right = right;
	return node;
}

//이진트리제거함수
void destroy_tree(treenode *root)
{
	if(root == NULL)
		return;
	destroy_tree(root -> left);
	destroy_tree(root -> right);
	free(root);
}

int is_leaf(treenode *root)
{
	return (!(root -> left) && !(root -> right));
}

void print_array(int codes[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}

void print_codes(treenode *root, int codes[], int top)
{
	if(root -> left) 	//1을 저장하고 순환호출한다.
	{
		codes[top] = 1;
		print_codes(root -> left, codes, top + 1);
	}
	if(root -> right)	//0을 저장하고 순환호출한다.
	{
		codes[top] = 0;
		print_codes(root -> right, codes, top + 1);
	}
	if(is_leaf(root))	//단일노드이면 코드를 출력한다.
	{
		printf("%c: ", root -> ch);
		print_array(codes, top);
	}
}

void init_huffman_tree(int freq[], char ch_list[], int n)
{
	treenode *node, *x;
	heaptype *heap;
	element e, e1, e2;
	int codes[100];
	int top = 0;

	heap = create();
	init(heap);
	for(int i = 0; i < n; i++)
	{
		node = make_tree(NULL, NULL);
		e.ch = node -> ch = ch_list[i];
		e.key = node -> weight = freq[i];
		e.ptree = node;
		insert_min_heap(heap, e);
	}
	for(int i = 1; i < n; i++)
	{
		e1 = delete_min_heap(heap);				//최솟값가지는 노드 삭제
		e2 = delete_min_heap(heap);				//최솟값가지는 노드 삭제
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x -> weight = e1.key + e2.key;	//두개의 노드를 합친다.
		e.ptree = x;
		printf("%d + %d -> %d\n", e1.key, e2.key, e.key);
		insert_min_heap(heap, e);
	}
	e = delete_min_heap(heap);					//최종 트리
	print_codes(e.ptree, codes, top);
	destroy_tree(e.ptree);
	free(heap);
}

int main()
{
	char ch_list[] = { 's', 'i', 'n', 't', 'e' };
	int freq[] = { 4, 6, 8, 12, 15};
	init_huffman_tree(freq, ch_list, 5);
	return 0;
}