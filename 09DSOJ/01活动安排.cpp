#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct action{
    int s ; //活动开始时间
    int f ; //活动结束时间
};
action a[1001];
bool cmp(const action &a,const action &b){

    if(a.f<=b.f)return true;
    else return false;
}
int  Selector(int n,action a[]){
    int sum=1;
    int preEnd = 1;
    for ( int i =2;i<=n;i++){
        if(a[i].s>=a[preEnd].f){
            sum++;
            preEnd = i;
        }
    }
    return sum;
}
int main(){
    int T,n;
    //cin >> T ;
    T = 1;
    for(int i=1;i<=T;i++){
        cin >> n;
        for(int j=1;j<=n;j++){
            cin >> a[j].s >> a[j].f;
        }
        sort(a,a+n+1,cmp);
        int sum = Selector(n,a);
        //cout << "Case " << i << ": "<< sum <<endl;
        cout << sum << endl;
    }
}