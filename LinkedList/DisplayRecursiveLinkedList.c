#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*first=NULL;

void create(int A[],int n){
    int i;
    struct Node *temp,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}
void display(struct Node *p){
   if(p!=NULL){
        printf("%d ",p->data);
        display(p->next);
   }
}
//reverse
void displayR(struct Node *p){
   if(p!=NULL){
        display(p->next);
        printf("%d ",p->data);
   }
}
int main(){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    
    int A[]={3,5,7,10,15};
    create(A,5);
    display(first);
    displayR(first);
    return 0;
}