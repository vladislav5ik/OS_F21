#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

void print_list(Node* head){
    Node* current_node = head->next;
    printf("%d ", head->data);
    while (current_node != NULL){
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}


void insert_node(Node* head, int data){
	Node* current_node = head;
    while (current_node->next != NULL){
        current_node = current_node->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    current_node->next = new_node;
}

void delete_node(Node* head, int data){
    if (head->data == data){
        *head = *head->next;
        return;
    }
    Node* prev_node = head;
    Node* current_node = head->next;
    while (current_node != NULL){
        if(current_node->data == data){
            prev_node->next = current_node->next;
            return;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
}

int main(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    print_list(head);

    insert_node(head, 2);
    insert_node(head, 3);
    insert_node(head, 4);
    insert_node(head, 5);
    print_list(head);

    delete_node(head, 1);
    delete_node(head, 2);
    delete_node(head, 5);
    print_list(head);
    return 0;
}
