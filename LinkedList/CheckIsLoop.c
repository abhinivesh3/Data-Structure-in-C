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
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int isLoop(struct Node *f){
    struct Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    return p==q?1:0;
}

int main(){
    
    int A[]={3,5,7,10,15};
    create(A,5);

    struct Node *t1,*t2;

    t1=first->next->next;
    t2=first->next->next->next->next->next;
    t2->next=t1;
    printf("%d\n",isLoop(first));
    return 0;
}