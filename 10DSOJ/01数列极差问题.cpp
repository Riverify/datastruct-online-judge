#include<iostream>
#include<algorithm>
using namespace std;
//定义两个数组用于求最大和最小值得时候使用
 int s[50001];
 int j[50001];
 int cmp(int a,int b){
 return a>b;
 }
int main(){
	int n;
	while(cin>>n&&n){
	for(int i=0;i<n;i++){
	cin>>s[i];
	j[i]=s[i];
	}
	//先升序排列
	sort(s,s+n);
	for(int i=1;i<n;i++){
	s[i]=s[i]*s[i-1]+1;//从小到大排完序之后，先从前边最小的两个数相乘然后存放到数组里
	sort(s+i,s+n);/*算法的核心部分，由于每次从最小的两个数相乘后的数值
				  放到原来的数组中有可能会破坏数组从小到大的顺序，所以再用一个sort排序，使新的数组变得有序,
				  依次循环下去，就会得到最大值。*/
 
	}
	int max=s[n-1];
	//降序排列并求最小值
	sort(j,j+n,cmp);
	for(int i=1;i<n;i++){
	j[i]=j[i-1]*j[i]+1;/*而求最小值的时候就不用sort每次都排序啦，因为前边两个最大的数乘起来
					   的数不可能会比后边小的数还要小，所以求最小值得时候会比上边要简单一些*/
	}
	int min=j[n-1];
cout<<max-min<<endl;
	}
return 0;
}