#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
} *Head;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }

}

void Display(struct Node *h){
    do{
        printf("%d ",h->data);
        h=h->next;
    }while (h!=Head);
    printf("\n");
}

void Display1(struct Node *h){
    int flag=0;
    while(h!=Head || flag==0){
        flag=1;
        printf("%d ",h->data);
        Display1(h->next);
    }
    printf("\n");
}

int main(){
    int A[]={2,3,4,5,6};
    create(A,5);
    Display1(Head);
    Display(Head);
}