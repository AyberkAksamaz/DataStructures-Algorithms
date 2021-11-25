#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_s *NODE;
typedef struct NODE_s {
	NODE left;
	NODE right;
	unsigned long key;
	void *data;
	int height;
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
	n->height = 0;
	return n;
}

int maxHeight(int leftHeight, int rightHeight) {
	if(leftHeight > rightHeight) {
		return leftHeight;
	}else {
		return rightHeight;
	}
}

int height(NODE node) {
	if(node == NULL) {
		return 0;
	}else {
		return node->height;
	}
}
int balance(NODE node) {
		return height(node->left) - height(node->right);
}

//left rotate
NODE rotate_left(NODE node) {

	NODE n1,n2;

	n1 = node->right;
	n2 = n1->left;

	n1->left = node;
	node->right = n2;

	node->height = maxHeight(height(node->left), height(node->right)) + 1;
	n1->height = maxHeight(height(n1->left), height(n1->right)) + 1;

	return n1;
}
//right rotate
NODE rotate_right(NODE node) {

	NODE n1, n2;

	n1 = node->left;
	n2 = n1->right;

	n1->right = node;
	node->left = n2;

	node->height = maxHeight(height(node->left), height(node->right)) + 1;
	n1->height = maxHeight(height(n1->left), height(n1->right)) + 1;

	return n1;
}

NODE tree_insert_recursive(NODE node, unsigned long key, void *data) {
	if(node != NULL) {
		if(key < node->key) {
			node->left = tree_insert_recursive(node->left, key, data);
		}else if(key > node->key) {
			node->right = tree_insert_recursive(node->right, key, data);
		}else {
			return node;
		}
	}else {
		node = tree_node_init(key, data);
	}

	node->height = 1 + maxHeight(height(node->left), height(node->right));


	//case Control

	// right left
	if((balance(node) < -1) && (key < node->right->key)) {
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	// right right
	if((balance(node) < -1) && (key > node->right->key)) {
		return rotate_left(node);
	}
	// left left
	if((balance(node) > 1) && (key < node->left->key)) {
		return rotate_right(node);
	}
	// left right
	if((balance(node) > 1) && (key > node->left->key)) {
		node->left = rotate_left(node->left);
		return rotate_right(node);
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

int main() {
	TREE tree = tree_init();
	NODE node;



	node = tree_insert_recursive(tree->root, 23, NULL);
	node = tree_insert_recursive(node, 45, NULL);






	tree_print(node, 0);
	printf("\n\n");


}
