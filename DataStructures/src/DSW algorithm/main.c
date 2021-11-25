#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_s *NODE;
typedef struct NODE_s {
	NODE left;
	NODE right;
	unsigned long key;
	void *data;
}NODE_t[1];

typedef struct {
	NODE root;
}TREE_t[1], *TREE;

TREE tree_init() {
	TREE t = (TREE)malloc(sizeof(TREE_t));
	if(t == NULL) {
		printf("Error .... \n");
	}else {
		t->root = NULL;
	}

	return t;
}

void tree_kill(TREE t) {
	if(t == NULL) {
		printf("Error... \n");
	}
	free(t);
}

NODE tree_node_init(unsigned long key, void *data) {
	NODE n = (NODE)malloc(sizeof(NODE_t));
	n->left = NULL;
	n->right = NULL;
	n->key = key;
	n->data = data;
	return n;
}

NODE tree_insert_recursive(NODE node, unsigned long key, void *data) {
	if(node != NULL) {
		if(key < node->key) {
			node->left = tree_insert_recursive(node->left, key, data);
		}else if(key > node->key) {
			node->right = tree_insert_recursive(node->right, key, data);
		}else {
			printf("Error: duplicate node \n");
		}
	}else {
		node = tree_node_init(key, data);
	}
	return node;
}

void tree_insert(TREE tree, unsigned long key, void *data) {
	if(tree->root == NULL) {
		tree->root = tree_node_init(key, data);
	}else {
		tree->root = tree_insert_recursive(tree->root, key, data);
	}
}

void tree_print(NODE node, int k) {
	int i;
	if(node != NULL) {
		tree_print(node->right, k+3);
		for(i = 0; i < k; i++) {
			printf(" ");
		}
		printf("%lu\n", node->key);
		fflush(stdout);
		tree_print(node->left, k+3);
	}
}

void rotate_left(TREE tree, NODE parent, NODE child, NODE gp) {

	parent->right = child->left;
	child->left = parent;
	if(parent == tree->root) {
		tree->root = child;
	}else {
		gp->right = child;
	}
}

void make_Left_rotations(TREE tree, int i) {
	NODE gp, parent, child;
	gp = NULL;
	parent = tree->root;
	child = tree->root->right;
	while(i > 0) {
		rotate_left(tree, parent, child, gp);
		gp = child;
		parent = gp->right;
		child = parent->right;
		i--;
	}
}

int logar(int n) {  //log2
	if(n > 1) {
		return 1 + logar(n/2);
	}else {
		return 0;
	}
}

int pow2(int n) {
	int m = 1;
	for(int i=0; i<n; i++) {
		m = m*2;
	}
	return m;
}

int find_m(int n) {
	int m = logar(n+1);
	m = pow2(m);
	m--;
	return m;
}

void make_balance_tree(TREE tree, int n) {
	int m;
	m = find_m(n);

	make_Left_rotations(tree, n-m);
	while(m > 1) {
		m = m/2;
		make_Left_rotations(tree, m);
	}

}

void rotate_right(TREE tree, NODE parent, NODE child, NODE gp) { //???????

	parent->left = child->right;
	child->right = parent;
	if(parent == tree->root) {
		tree->root = child;
	}else {
		gp->right = child;
	}

}

void backbone(TREE tree) {
	NODE parent, child, gp;
	gp = tree->root;   // gp = (NODE)tree;
	parent = tree->root;

	while(parent != NULL) {
		child = parent->left;
		if(child != NULL) {
			rotate_right(tree, parent, child, gp);
			parent = child;
		}else {
			gp = parent;
			parent = parent->right;
		}
	}
}

int size_of_tree(NODE node)
{
  if (node==NULL)
    return 0;
  else
    return(size_of_tree(node->left) + 1 + size_of_tree(node->right));
}

void dsw_algortihm(TREE tree) {

	backbone(tree);

	int n = size_of_tree(tree->root);
	make_balance_tree(tree, n);
}

int main() {
	TREE tree = tree_init();

	tree_insert(tree, 35, NULL);
	tree_insert(tree, 20, NULL);
	tree_insert(tree, 75, NULL);
	tree_insert(tree, 10, NULL);
	tree_insert(tree, 25, NULL);
	tree_insert(tree, 50, NULL);
	tree_insert(tree, 90, NULL);
	tree_insert(tree, 65, NULL);
	tree_insert(tree, 85, NULL);





	tree_print(tree->root, 0);

	dsw_algortihm(tree);
	printf("\n\n\n\n\n");
	tree_print(tree->root, 0);

}
