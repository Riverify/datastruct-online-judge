#include <iostream>
#include <limits.h>
using namespace std;
 
struct Enode{
    int adjvex;
    int w;
    Enode *next;
};
 
int FMultiGraph(int n,Enode **a){
    int c;
    int j;
    Enode *r;
    int *cost=new int[n];
    cost[n-1]=0;
    for(j=n-2;j>=0;j--){
        int min=INT_MAX;
        for(r=a[j];r;r=r->next){
            int v=r->adjvex;
            if(r->w+cost[v]<min)
                min=r->w+cost[v];
        }
        cost[j]=min;
    }
    c=cost[0];
    return c;
}
 
int main(){
    int n,m,i,u,v,ww;
    cin>>n>>m;
    Enode **a,*t;
    a=new Enode*[n];
    for(i=0;i<n;i++)
        a[i]=NULL;
    for(i=0;i<m;i++){
        cin>>u>>v>>ww;
        t=new Enode;
        t->adjvex=v;
        t->w=ww;
        t->next=a[u];
        a[u]=t;
    }
    cout<<FMultiGraph(n,a);
    return 0;
}