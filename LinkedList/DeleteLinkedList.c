#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    struct Node *last,*temp;
    first=(struct Node *)malloc(sizeof(struct Node));
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
    temp=(struct Node*)malloc(sizeof(struct Node));
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
    printf("\n");
}

int delete(struct Node *p,int index){
    struct Node *q=NULL;
    int x=-1;
    if(index<1|| index>count(p)){
        return x;
    }
    if(index==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}
int main(){
    int A[]={10,20,30,40,50};
    create(A,5);
    display(first);
    printf("delete 4- %d\n",delete(first,4));
    display(first);
    return 0;
}