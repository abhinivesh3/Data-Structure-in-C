#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*first=NULL;
void create(int A[],int n){
    int i=0;
    struct Node *last,*temp;
    first=(struct Node*)malloc(sizeof(struct Node));
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
int max(struct Node *p){
    int max=0;
    if(p==0){
        return INT_MIN ;
    }
    while(p!=0){
        if(p->data>max){
            max=p->data;
        }
        else{
            p=p->next;
        }
    }
    return max;
}
int maxR(struct Node *p){
    int x=0;
    if(p==0){
        return INT_MIN ;
    }
    x=max(p->next);
    return x>p->data?x:p->data;
}

int main(){
    int A[]={1,3,5,6,7};
    create(A,5);
    printf("Max Element - %d",max(first));
    printf("Max Element - %d",maxR(first));
    return 0;

}