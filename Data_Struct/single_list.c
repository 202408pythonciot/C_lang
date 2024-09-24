// 片方向リスト
#include <stdio.h>
#include <stdlib.h>

typedef struct my_list_node {
	int number;
	struct my_list_node *next;
}my_list_node;

// リストにノードを追加
my_list_node *list_node_append(my_list_node *pref) {
	my_list_node *p;
	p = malloc(sizeof(*p));
	if (p == NULL) {
		return NULL;
	}
	p->next = NULL;
	if (pref != NULL) {
		pref->next = p;
	}
	return p;
}

// リストの中身表示
my_list_node* show_list(my_list_node* root) {
	my_list_node *p;
	int i = 0;

	p = root;
	while (p->next != NULL) {
		printf("list[%d] = %d\n", i, p->number);
		p = p->next;
		i += 1;
	}
}

int main(void) {
	my_list_node *head, *last;
	int data;

	data = 1;
	head = NULL;
	last = NULL;
	while (data) {
		printf("データを入力（0で終了）\n");
		scanf("%d", &data);
		my_list_node *p;
		p = list_node_append(last);
		p->number = data;
		last = p;
		if (head == NULL) {
			head = p;
		}
	}
	show_list(head);
	return 0;
}
