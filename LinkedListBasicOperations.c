/* basic operations in singly linked list
1. Traversing the linked list
2. Inserting into linked list
3. Deleting an item from linked list
1.a Inserting new node before the head
1.b Inserting new node after the tail
3.a Deleting tail node
3.b Deleting head node
*/

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode *next;
};

void insertBeforeHead(struct ListNode **, int );
void insertAfterTail(struct ListNode **, int );
void deleteTailNode(struct ListNode **);
void deleteHeadNode(struct ListNode **);
void printLinkedList(struct ListNode **);
void deleteLinkedList(struct ListNode **);

int main(){
    struct ListNode *head = NULL;
    int n;
    printf("1.insert before head\n");
    printf("2.insert after tail\n");
    printf("3.delete tail node\n");
    printf("4.delete head node\n");
    printf("5.show linked list\n");
    printf("6.Exit\n");
    int data;
    while (1) {
        printf("Enter an option:");
        scanf("%d",&n);
        while((n<=0)||(n>=7)){
            printf("Not a valid option\n");
            printf("Enter a valid option:");    
            scanf("%d",&n);
        }
        switch (n) {
            case 1:
                //insert before head
                printf("Enter a number to insert:");
                scanf("%d",&data);
                insertBeforeHead(&head,data);
                break;
            case 2:
                //insert after tail
                printf("Enter a nmber to insert:");
                scanf("%d",&data);
                insertAfterTail(&head,data);
                break;
            case 3:
                //delete tail node
                deleteTailNode(&head);
                break;
            case 4:
                //delete head node
                deleteHeadNode(&head);
                break;
            case 5:
                //show linked list
                printLinkedList(&head);
                break;
            default:
                //drop linked list and exit
                deleteLinkedList(&head);
                //exit
                printf("Exit\n");
                return 0;
                break;
        }
    }
    return 0;
}
void deleteLinkedList(struct ListNode **head){
    printf("Deleting linkedlist\n");
    struct ListNode *temp = (*head);
    struct ListNode *temp2 = NULL;
    while (temp != NULL) {
        temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
    (*head) = NULL;
    return;
}
void deleteHeadNode(struct ListNode **head){
    if ((*head)==NULL) {
        printf("Empty list\n");
        return;
    }
    struct ListNode *temp = (*head);
    (*head) = (*head)->next;
    printf("Deleting %d\n",temp->data);
    free(temp);
    return;
}
void deleteTailNode(struct ListNode **head){
    if ((*head)==NULL) {
        printf("Empty list\n");
        return;
    }
    struct ListNode *befTail = NULL;
    struct ListNode *tail = (*head);
    while (tail->next != NULL) {
        befTail = tail;
        tail = tail->next;
    }
    if (befTail != NULL) {
        befTail->next = NULL;
    }
    printf("Deleting %d\n",tail->data);
    free(tail);
    return;
}
void printLinkedList(struct ListNode **head){
    if ((*head)==NULL) {
        printf("Empty list\n");
        return;
    }
    struct ListNode *temp = (*head);
    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void insertBeforeHead(struct ListNode **head,int data){
    if ((*head)==NULL) {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->data = data;
        newNode->next = NULL;
        (*head) = newNode;
        return;
    }
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
    return;
}
void insertAfterTail(struct ListNode **head,int data){
    if ((*head)==NULL) {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->data=data;
        newNode->next=NULL;
        (*head)=newNode;
        return;
    }
    struct ListNode *newNode =(struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    struct ListNode *temp = (*head);
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}


