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

void Insert(struct Node *p,int index,int x){
    struct Node *temp;
    int i;
    if(index<0 || index>count(p)){
        return;
    }
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    if(index==0){
        temp->next=first;
        first=temp;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}

void insertLast(int x){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    struct Node *last=first;
    if(first==NULL){
        first=last=temp;
    }
    else{
        last->next=temp;
        last=temp;
    }
}

int count(struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
void display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int  isSorted(struct Node *first){
    int x=-32768;
    struct Node *p=first;
    while(p!=NULL){
        if(p->data<x){
            return 1;
        }
        x=p->data;
        p=p->next;
    }
    return 0;
}
int main(){
    int A[]={3,5,7,4};
    display(first);
    if(isSorted(first)){
        printf("sorted\n");
    }
    else{
        printf("not sorted\n");
    }
    return 0;
}