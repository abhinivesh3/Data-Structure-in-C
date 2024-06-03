#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
}*first =NULL;

void create(int A[],int n){
    struct Node *last,*temp;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void SortedInsert(struct Node *p,int x){
    struct Node *t,*q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=t;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}
void display(struct Node *p){
   if(p!=NULL){
        printf("%d ",p->data);
        display(p->next);
   }
}
int main(){
    int A[]={10,20,30,40,50};
    create(A,5);
    SortedInsert(first,35);
    display(first);
}