#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Good{
    int id;
    double w;
    double v;
};
 
bool cmp(Good a, Good b){
    if (a.v/a.w > b.v/b.w) {
        return true;
    }
    return false;
}
 
bool cmp1(Good a, Good b){
    if (a.id <b.id) {
        return true;
    }
    return false;
}
int main()
{
    double values = 0;
	double totalW;
	int n,i;
	double x[1000];
	cin>>totalW;
    cin>>n;
	struct Good goods[n];
	for(i=0;i<n;i++){
		cin>>goods[i].id>>goods[i].v>>goods[i].w;
        goods[i].id++;
		x[i]=0;
	}
    //以物品的价值/重量比值降序排序
    sort(goods,goods+n,cmp);
    double leftW = totalW;
    int totalV = 0;
    
    //遍历排好序的物品数组
    for (i=0; i<n; i++) {
        if (leftW >= goods[i].w) {
            leftW -= goods[i].w;
            x[goods[i].id-1]=1;  //按照原来的顺序录入 
            totalV += goods[i].v;
            
        }else {
            totalV += leftW/goods[i].w * goods[i].v;
            x[goods[i].id-1]=leftW/goods[i].w;
            leftW = 0;
            
            break;
        }
    }
   for(i=0;i<n;i++){
        values += x[i+1] * goods[i].v;
        printf("%.2lf ",x[i]);
	}
    printf("\n");
    printf("%.2lf\n", values);
    return 0;
}

