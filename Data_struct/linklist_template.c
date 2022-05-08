#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node ;

//新增節點
void Push_front(Node **begin,int value){
    Node *top=(Node*)malloc(sizeof(Node));
    top->data=value;
    top->next=*begin;
    *begin=top;
    return;
}

void Push_back(Node **begin,int value){
    Node *newNode = (Node*)malloc(sizeof(Node));   
    if (*begin == NULL) {                      
        *begin = newNode;
        newNode->data=value; 
        return;
    }
    Node *current = *begin;
    while (current->next != NULL) {           
        current = current->next;
    }
    current->next = newNode;
    newNode->data=value;
    return;               
}

void Pop(Node **top){
    Node *save=*top;
    (*top)=(*top)->next;
    free(save);
    return;
}

//印出整個link list
void printlist(Node *begin){
    if(begin==NULL) return;
    while (begin)
    {
        printf("   adress = %p , data =%2d          ,next = %p\n",begin,begin->data,begin->next);
        begin=begin->next;
    }
}
// 搜尋linklist裡要找的數字的adress，並return(若linklist內有多個相同的數字，回傳遞一個)
Node *search(Node *begin,int number){
    while(begin)
    {
        if(begin->data==number){
            return begin;
        }
        if(begin->next==NULL) break;
        begin=begin->next;
    }
    return NULL;
}

Node *SwapNode(Node *begin,int v1,int v2){
    Node *forward=NULL,*back=NULL,*type,*save;
    Push(&begin,48763);
    save=begin;
    while (begin)
    {
        if (begin->data==v1 || begin->data==v2)
        {
            if(forward==NULL) forward=begin;
            else if(forward!=NULL && back==NULL){
                back=begin;
                break;
            }
        }
        begin=begin->next;
    }
    begin=save;
    if(forward->next==back){
        while (begin)
        {   
            if(begin->next->data==forward->data){
                Node *temp=back->next;
                begin->next=back;
                back->next=forward;
                forward->next=temp;
                break;
            }
            begin=begin->next;
        }
    }
    if (forward->next!=back)
    {   
        Node *temp1=back->next,*temp2=forward->next;
        while (begin)
        {   
            if(begin->next->data==forward->data){
                begin->next=back;
                back->next=temp2;
            }
            else if(begin->next->data==back->data){
                begin->next=forward;
                forward->next=temp1;
                break;
            }
            begin=begin->next;
        }
    }
    return save->next;
}

Node *swapPairs(Node* head) 
{
    if(NULL==head || NULL==head->next)
    {
        return head;
    }
    Node* p1=head;
    Node* p2=head->next;
    p1->next=p2->next;
    p2->next=p1;
    Node* res=p2;
    Node* last=p1;
    while(p1->next && p1->next->next)
    {
        p1=p1->next;
        p2=p1->next;
        p1->next=p2->next;
        p2->next=p1;
        last->next=p2;
        last=p1;
    }
    return res;
}

Node *nodeReverse(Node *begin){
    if (begin==NULL || begin->next==NULL) {
        return begin;
    }
    Node *previous = 0,*current = begin, *preceding = begin->next;
    while (preceding != 0) {
        current->next = previous;      
        previous = current;            
        current = preceding;           
        preceding = preceding->next;   
    }                                  
    current->next = previous;          
    begin = current;
    return begin;                  
}
//尚有缺陷
void qpop(Node *begin){
    while (begin->next->next!= NULL)
        begin=begin->next;
    free(begin->next);
    begin->next=NULL;
    return;
}
//傳入link list首的adress
void Clear(Node **begin){
    while (*begin != NULL) {            
        Pop(begin);
    }
    return;
}