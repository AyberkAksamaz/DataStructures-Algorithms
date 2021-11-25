#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s {
	LINKED_LIST_NODE next;
	void *data;
}LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s {
	LINKED_LIST_NODE head;
}LINKED_LIST_t[1];

LINKED_LIST linked_list_init();
LINKED_LIST_NODE linked_list_node_init(LINKED_LIST_NODE node, void *data);
void linked_list_free(LINKED_LIST list);
void linked_list_prepend(LINKED_LIST list, void *data);
void linked_list_append(LINKED_LIST list, void *data);
void linked_list_insert(LINKED_LIST list, void *data, int idx);
void *linked_list_remove(LINKED_LIST list, int idx);
void linked_list_set(LINKED_LIST list,void *data, int idx);
void *linked_list_get(LINKED_LIST list, int idx);
void linked_list_removeall(LINKED_LIST list);
void linked_list_concatenate(LINKED_LIST list, LINKED_LIST list2);
int linked_list_size(LINKED_LIST list);
void linked_list_fprint(LINKED_LIST list, void (*print_type)(void*));
void integer_printer(void *data);
void char_printer(void *data);


#endif /* LINKED_LIST_H_ */
