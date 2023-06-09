#include <stdio.h>
#include <stdlib.h>

typedef struct node_queue{
    int val;
    struct node_queue* next;
} node_queue;

typedef struct queue{
    size_t size;
    node_queue* head;
    node_queue* last;
} queue;

queue* create_queue(){
    queue* new = (queue*)malloc(sizeof(queue));
    new -> last = new->head = NULL;
    new -> size = 0;
    return new;
}

node_queue* __create_node_queue(){
    node_queue* new = (node_queue*)malloc(sizeof(node_queue));
    new -> next = NULL;
    new -> val = 0;
    return new;
}

void append(queue** q, int value){
    node_queue* new = __create_node_queue();
    new -> val = value;
    if((*q)->head == NULL){
        (*q) ->head = (*q) ->last = new;
    } else{
        (*q) ->last ->next = new;
        (*q) ->last = (*q) ->last ->next;
    }
    (*q) ->size++;
}

int pop(queue** q){
    if((*q)-> size == 1) (*q) -> last = NULL;
    node_queue* aux = (*q)->head;
    (*q)->head = aux -> next;
    (*q)->size--;
    aux ->next = NULL;
    int ret = aux -> val; 
    free(aux);
    return ret;
}

size_t search(queue* q, int key){
    size_t counter = 1;
    if(q->head == NULL) return 0;
    else if(q->head -> next == NULL){
        if(q->head -> val == key) return counter;
        else return 0;  
    }
    node_queue* aux = q->head;
    while(aux->next != NULL){
        if(aux -> val == key) return counter;
        counter++;
        aux = aux->next;
    }
    return 0;
}

size_t size(queue* q){
    return q->size;
}

void print_queue(queue* q){
    node_queue* aux = q->head;
    while(aux != NULL){
        printf("%d ", aux->val);
        aux = aux->next;
    }
}

void print_first(queue* q){
    printf("%d\n",q->head->val);
}

void free_all(queue** q){

    while((*q)->head != (*q)->last && (*q)->last != NULL){
        node_queue* aux =  (*q)->head ->next;
        free((*q)->head);
        (*q)->head = aux;
    }
    if((*q)->head != NULL) free((*q)->head);
    free(*q);
}

int main(){
    queue* q = create_queue();
    append(&q, 10);
    append(&q, 20);
    append(&q, 30);
    // print_first(q);
    // size_t v = search(q,20);
    // printf("%d ",v);
    print_queue(q);
}