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

int search(struct Node *p,int key){
    while(p!=NULL){
        if(p->data==key){
            return p->data;
        }
        p=p->next;
    }
    return NULL;
}

int searchR(struct Node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(p->data==key){
        return p->data;
    }
    return searchR(p->next,key);
}
//linear search
int searchOther(struct Node *p,int key){
    struct Node *q=NULL;
    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
        }
        q=p;
        p=p->next;
    }
    
}
int main(){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    
    int A[]={3,5,7,10,15};
    create(A,5);
    printf("search -%d %d",search(first,7),searchR(first,15));
    return 0;
}