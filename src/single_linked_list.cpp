#include <stdio.h>
//#include iostream

int arr_idx = 0;

struct NODE {
	int v;
	NODE * prev;	// 싱글 리스트를 위해 추가
} a[10000];


NODE * myalloc(void)
{
	return &a[arr_idx++];
}

void init_array()
{
	arr_idx = 0;	//	배열 초기화	
}

NODE * add_node(NODE * list, int value)
{
	NODE * node;

	node = myalloc();
	node->v = value;
	node->prev = list;

	return node;
}

NODE * del_node(NODE * list, int value)	// 삭제한 로드는 재사용하지 않음.
{
	NODE * node = list;

	if (list->v == value)
	{
		node = list->prev;
		return node;
	}

	for (NODE * pp = list; pp != NULL; pp = pp->prev )
	{
		if (pp->prev->v == value)
		{
			pp->prev = pp->prev->prev;			
			return node;
		}
	}
	return node;
}

void print_node(NODE * list)
{
	printf("List = { ");
	for (NODE * pp = list; pp != NULL; pp = pp->prev)
	{	
		printf("(%d)",pp->v);		
		if (pp->prev != NULL)
			printf("->");
	}
	printf(" }\n");
}

int main(void)
{
	NODE * pList = NULL;	// 싱글 링크드 리스트의 시작
	NODE * p_4th;			// 4번째 리스트의 포인트 값을 저장
	NODE * p_8th;			// 8번째 리스트의 포인트 값을 저장

			
	init_array();			// 배열 초기화
	
	// 첫번째 노드(NODE1) 추가
	pList = add_node(pList, 1);
	
	// 두번째 노드(NODE2) 추가
	pList = add_node(pList, 2);

	// 3 ~ 10 번째 노드 추가
	for (int value = 3; value <= 10; value++)
	{
		pList = add_node(pList, value);
		if (value == 4)	// 4번째 리스트의 포인트 저장
			p_4th = pList;
		if (value == 8)	// 8번째 리스트의 포인트 저장
			p_8th = pList;
	}

	// 추가된 노드 확인
	print_node(pList);
	printf(" - 4번째 리스트의 값 = %d \n",p_4th->v);
    printf(" - 8번째 리스트의 값 = %d \n\n",p_8th->v);


	// 10번째 노드(NODE8) 삭제
	pList = del_node(pList, 10);

	// 4번째 노드(NODE4) 삭제
	pList = del_node(pList, 4);

	// 8번째 노드(NODE8) 삭제
	pList = del_node(pList, 8);

	// 1번째 노드(NODE1) 삭제
	pList = del_node(pList, 1);

	// 최종 노드 확인
	print_node(pList);
	printf(" - 4번째 리스트의 값 = %d \n",p_4th->v);
    printf(" - 8번째 리스트의 값 = %d \n\n",p_8th->v);

	return 0;
}