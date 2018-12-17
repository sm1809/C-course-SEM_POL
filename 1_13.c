#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define max(a, b) ( (a) > (b) ? (a) : (b) )

// Определяем структуру для вершины будущего дерева
typedef struct NODE {
	int val;
	struct NODE * left;
	struct NODE * right;
} node_t;

// Создаем новую вершину для значения val
node_t * add_node(const int val) {
	node_t * node = (node_t*)malloc(sizeof(node_t));
	if (!node)
		return NULL;

	node->val = val;
	node->left = NULL;
	node->right = NULL;

	return node;
}

// Вставляем значение в дерево с корнем tree рекурсивно
node_t * tree_insert(node_t * tree, const int val) {
	if (!tree)
		return add_node(val);
	else if (tree->val == val) {
		return tree;
	}
	else if (tree->val > val)
		tree->left = tree_insert(tree->left, val);
	else
		tree->right = tree_insert(tree->right, val);

	return tree;
}

// Считываем последовательность значений, заканчивающихся символом '!', из которой строим дерево поиска
node_t * tree_from_input() {
	node_t * tree = NULL;
	int val;

	while (fscanf(stdin, "%d", &val) == 1)
	{
		if (val == '!')
			break;
		else
			tree = tree_insert(tree, val);
	}
	return tree;
}

// Не забываем освободить память
void free_tree(node_t * tree) {
	if (tree) {
		free_tree(tree->left);
		free_tree(tree->right);
		free(tree);
	}
}

// Рекурсивно проверяем, является ли дерево АВЛ-деревом, обращая в ноль соответствующий флаг в случае неудачи
int if_avl(node_t* p, int* flag)
{
	if (!p)
		return 0;
	int L = if_avl(p->left, flag);
	int R = if_avl(p->right, flag);
	if (abs(L - R) > 1)
		*flag = 0;
	return max(L, R) + 1;
}

// Выводим результат проверки свойства дерева
void check_tree(int h, node_t* p)
{
	int flag = 1;
	if_avl(p, &flag);
	if (flag)
		printf("YES");
	else
		printf("NO");
}

int main(void) {
	node_t * tree = tree_from_input();
	check_tree(1, tree);
	free_tree(tree);
	return 0;
}
