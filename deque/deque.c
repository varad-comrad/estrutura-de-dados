#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
} node;

typedef struct deque{
    size_t size;
    node* head;
    node* tail;
} deque;


deque* create_deque(){
    deque* dq = (deque*)malloc(sizeof(deque));
    dq->size = 0;
    dq->head = dq->tail = NULL;
}

node* __create_node(int value){
    node* new = (node*)malloc(sizeof(node));
    new -> val = value;
    new -> next = new->prev = NULL;
    return new;
}

void append_right(deque** dq, int key){
    (*dq)->size++;
    node* new = __create_node(key);
    if((*dq)->size == 1){
        (*dq)->head = (*dq)->tail = new;
        return;
    }
    (*dq)->tail ->next = new;
    new -> prev = (*dq)->tail;
    (*dq)->tail = new;  
}

void append_left(deque** dq, int key){
    (*dq)->size++;
    node* new = __create_node(key);
    if((*dq)->size == 1){
        (*dq)->head = (*dq)->tail = new;
        return;
    }
    (*dq)->head ->prev = new;
    new -> next = (*dq)->head;
    (*dq)->head = new;  
}



int pop_right(deque** dq){
    if((*dq)->size == 0) return -1;
    else if((*dq)->size == 1){
        (*dq)->size--;
        int value = (*dq)->tail->val;
        free((*dq)->tail);
        return value;
    }
    (*dq)->size--;
    node* aux = (*dq)-> tail -> prev;
    int value = (*dq)-> tail -> val;
    free((*dq)-> tail);
    aux -> next = NULL;
    (*dq)-> tail = aux;
    return value;
}

int pop_left(deque** dq){
    if((*dq)->size == 0) return -1;
    else if((*dq)->size == 1){
        (*dq)->size--;
        int value = (*dq)->head->val;
        free((*dq)->head);
        return value;
    }
    (*dq)->size--;
    node* aux = (*dq) -> head -> next;
    int value = (*dq) -> head -> val;
    free((*dq)-> head);
    (*dq)-> head = aux;
    aux -> prev = NULL;
    return value;
}

// TODO: Fix remove
int remove_element(deque** dq, int key){
    size_t counter = 0;
    node* aux = (*dq)->head;
    if((*dq)->size == 0) return -1;
    else if((*dq)->size == 1){
        if((*dq)->head->val != key) return -1;
        return counter;
    } else if((*dq)->size == 2){

    }
    while(aux -> next ->next !=NULL){
        counter++;
        if(aux->next->val == key) break;
        aux = aux->next;
    }
    if(aux->next == (*dq)->tail && (*dq)->tail->val != key) return -1;
    free(aux -> next);
    aux -> next = NULL;
    return counter;
}


size_t search(deque* dq, int key){
    size_t counter = 0;
    node* aux = dq->head;
    while(aux != NULL){
        if(aux->val == key) break;
        counter++;
        aux = aux->next;
    }
    if(aux == NULL) return -1;
    return counter;
}

void print_deque(deque* dq){
    node* aux = dq->head;
    while(aux){
        printf("%d ",aux->val);
        aux = aux->next;
    }
    printf("\n");
}

// TODO: Implement insert_element
int insert_element(deque** dq, int key, size_t pos){
    
}

size_t len(deque* dq){
    return dq->size;
}

void free_all(deque **dq){
    while((*dq) -> head != NULL){
        pop_left(dq);
    }
    free(*dq);
}

int main(){
    deque* dq = create_deque();
    append_right(&dq,10);
    append_right(&dq,20);
    append_right(&dq,30);
    append_left(&dq, 40);
    // pop_left(&dq);
    remove_element(&dq,20);
    // pop_right(&dq);
    // printf("%d", search(dq, 20));
    // printf("%d", dq->head->val);
    print_deque(dq);
    // free_all(&dq);
    
    return 0;
}