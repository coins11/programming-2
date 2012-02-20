#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *insert_data(int x, struct node *p);
int search_tree(int x, struct node *p);
void print_tree(struct node *p);
int sumOfTree(struct node *p);

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, x;
	struct node *root;

	if (argc != 2) {
		printf("missing file argument\n");
		return 1;
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("can't open %s\n", argv[1]);
		return 1;
	}

	root = NULL;

	for (i = 0; i < 20; i++) {
		fscanf(fp, "%d", &x);
		root = insert_data(x, root);
	}

	print_tree(root);

	printf("%d\n", sumOfTree(root));
	//while (1) {
	//	scanf("%d", &x);
	//	if (x <= 0)
	//		break;
	//	if (search_tree(x, root) == 1)
	//		printf("%d: Found\n", x);
	//	else
	//		printf("%d: Not found\n", x);
	//}

	fclose(fp);

	return 0;
}

int search_tree(int x, struct node *p) {
	struct node *current;
	int boolean = 0;

	current = p;
	while (current != NULL) {
		if (current->data == x) {
			boolean = 1;
			break;
		}
		else if (current->data < x) {
			current = current->right;
		}
		else {
			current = current->left;
		}
	}

	return boolean;
}

int sumOfTree(struct node *p) {
	if (p == NULL) {
		return 0;
	}
	int sum = p->data;
	sum += sumOfTree(p->right);
	sum += sumOfTree(p->left);

	return sum;
}

struct node *insert_data(int x, struct node *p)
{
	if (p == NULL) {
		p = (struct node *) malloc(sizeof(struct node));
		if (p == NULL) {
			printf("Out of memory\n");
			exit(1);
		}
		p->data = x;
		p->left = NULL;
		p->right = NULL;

		return p;
	}

	if (x == p->data)
		return p;

	if (x < p->data)
		p->left = insert_data(x, p->left);
	else
		p->right = insert_data(x, p->right);

	return p;
}

void print_tree(struct node *p)
{
	if (p == NULL)
		return;

	print_tree(p->left);
	printf("%d\n", p->data);
	print_tree(p->right);
}

