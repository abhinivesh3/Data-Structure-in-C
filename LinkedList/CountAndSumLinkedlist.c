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
void countAndSum(struct Node *p){
    int c=0,sum=0;
    while(p!=0){
        sum+=p->data;
        c++;
        p=p->next;
    }
    printf("Count - %d\n Sum - %d ",c,sum);
}
int countR(struct Node *p){
    if(p==0){
        return 0;
    }
    else{
        return countR(p->next)+1;
    }
}
int sumR(struct Node *p){
    if(p==0){
        return 0;
    }
    else{
        return sumR(p->next)+p->data;
    }
}
int main(){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    
    int A[]={3,5,7,10,15};
    create(A,5);
    countAndSum(first);
    printf("\ncount - %d",countR(first));
    printf("\nsum - %d",sumR(first));
    return 0;
}