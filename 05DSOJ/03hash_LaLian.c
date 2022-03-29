#include<stdio.h>
#include<malloc.h>

typedef struct node{
 int val;
 struct node *next;
}*nd;

typedef struct{
 struct node *next; 
}hn,*hs;

int n,m,p;

nd newnode(int val){
 nd node=(nd)malloc(sizeof(struct node));
 node->val=val;
 node->next=NULL;
 return node;
}

void Insert(hs ht,int adr,int x){
 nd p=newnode(x);
 p->next=ht[adr].next;
 ht[adr].next=p;
}

hs create(int n,int m,int p){
 hs ht=(hs)malloc(sizeof(hn)*m);
 for(int i=0;i<m;i++)
  ht[i].next=NULL;
 for(int i=0;i<n;i++){
  int x,adr;
  scanf("%d",&x);
  adr=x%p;
  Insert(ht,adr,x);
 }
 return ht;
}

void find(hs ht,int val,int p){
 int adr=val%p,count=0;
 nd q=ht[adr].next;
 while(q){
  count++;
  if(q->val==val)
   break;
  q=q->next;
 }
 if(q)
  printf("Success %d\n",count);
 else
  printf("Failure %d\n",count);
}

int main(){
 hs ht;
 int val;
 scanf("%d%d%d",&n,&m,&p);
 ht=create(n,m,p);
 scanf("%d",&val);
 find(ht,val,p);
 return 0;
}