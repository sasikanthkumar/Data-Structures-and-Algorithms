/* transform algebraic expression with brackets to RPN form
    we use a stack and an array we traverse through the given expression if character we put it into answer array else if operator we put it into stack if open bracket we wait till closed bracket and when we come through closed bracket we pop oprator from stack
 Input:
 3
 (a+(b*c))
 ((a+b)*(z+x))
 ((a+t)*((b+(a+c))^(c+d)))
 
 Output:
 abc*+
 ab+zx+*
 at+bac++cd+^*
 
 */



#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    char data;
    struct ListNode *next;
};

void push(struct ListNode **, char );
char pop(struct ListNode **);


int main(){
    struct ListNode *head = NULL;
    char exp[400];
    char ans[400];
    int n;
    scanf("%d",&n);
    int h=0;
    for (h=0; h<n; h++) {
        scanf("%s",exp);
        int i=0;
        int k=0;
        char temp;
        while (exp[i] != '\0') {
            temp = exp[i];
            //printf("%c\n",temp);
            if (temp==')') {
                ans[k] = pop(&head);
                //printf("ans[k]  = %c\n",ans[k]);
                k++;
            }else if(temp == '+'){
                push(&head,temp);
                //printf("operator = %c\n",temp);
            }else if(temp =='-'){
                push(&head,temp);
                //printf("operator = %c\n",temp);
            }else if(temp =='*'){
                push(&head,temp);
                //printf("operator = %c\n",temp);
            }else if(temp =='/'){
                push(&head,temp);
                //printf("operator = %c\n",temp);
            }else if(temp =='^'){
                push(&head,temp);
                //printf("operator = %c\n",temp);
            }else if(temp != '('){
                ans[k] = temp;
                //printf("letter  = %c\n",temp);
                k++;
            }
            i++;
        }
        while ((head) != NULL) {
            ans[k] = pop(&head);
            k++;
        }
        
        ans[k] = '\0';
        //printf("\n");
        
        int p=0;
        printf("%s\n",ans);
        
    }
    
    
    return 0;
}

void push(struct ListNode **head,char data){
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

char pop(struct ListNode **head){
    if ((*head)==NULL) {
        printf("Empty list\n");
        return 'a';
    }
    char ch = (*head)->data;
    (*head) = (*head)->next;
    return ch;
}
