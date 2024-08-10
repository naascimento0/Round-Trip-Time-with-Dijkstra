#include "../../headers/data_structures/forward_list.h"
#include <stdio.h>
#include <stdlib.h>

// code created in the Data Structures Course with Professor Filipe Mutz

//O(1)
ForwardList* forward_list_construct(){
	ForwardList *forward = malloc(sizeof(ForwardList));
	forward->head = NULL;
	forward->size = 0;
	return forward;
}

//O(1)
int forward_list_size(ForwardList *l){
	return l->size; 
}

//O(1)
void forward_list_push_front(ForwardList *l, data_type data){
	 l->head = node_construct(data, l->head);
	 l->size++;
}

//O(n)
data_type forward_list_get(ForwardList *l, int i){
	if(i < 0 || i >= l->size)
		exit(printf("Error: index out of bounds!\n"));

	Node *aux = l->head;
	while(i--)
		aux = aux->next;
	return aux->value;
}

//O(n)
void forward_list_print(ForwardList *l, void (*print_fn)(data_type)){
	Node *current = l->head;
	printf("[");
	while(current != NULL){
		print_fn(current->value);
		current = current->next;
		if(current != NULL)
			printf(", ");
	}
	printf("]");
}

//O(n)
void forward_list_destroy(ForwardList *l, void(*destroy_fn)(data_type)){
	while(l->head != NULL){
		Node *aux = l->head;
		l->head = l->head->next;
		node_destroy(aux, destroy_fn);
		l->size--;
	}
	free(l);
}

























