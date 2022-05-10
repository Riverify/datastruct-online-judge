#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 20;
struct Work{
    
 int index;
 int d;
 int p;
};
bool cmp(Work x,Work y){
    
 return x.p>y.p;
}
int JS(Work *work,int *x,int n){
    
 int k = 0;
 x[0]=0;
 for(int j = 1 ; j < n ;j++){
    
  int r = k;
  while(r>=0 && work[x[r]].d>work[j].d && work[x[r]].d>r+1)
   r--;
  if((r<0 || work[x[r]].d<=work[j].d) && work[j].d>r+1){
    
   for(int i = k ; i >= r+1;i--)
    x[i+1]=x[i];
   x[r+1]=j;
   k++;
  } 
 }
 return k;
}
int main(){
    
 int n,x[N]; 
 Work *work= new Work [N];
 Work *works= new Work [N];
 cin>>n;
 for(int i = 0 ; i < n ; i++){
    
  cin>>work[i].index>>work[i].p>>work[i].d; 
  works[i]=work[i];
 }
 sort(work,work+n,cmp);
 int k = JS(work,x,n);
 int num[N];
 for(int i = 0 ; i <= k ; i++){
    
  num[i]=work[x[i]].index;
 }
 sort(num,num+k+1);
 int sum=0;
 for(int i = 0 ; i <=k;i++){
 cout<<num[i]<<' ';
 sum+=works[num[i]-1].p;
}
printf("\n");
cout<<sum;
 
 return 0;
}