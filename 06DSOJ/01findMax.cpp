#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
 
//查找最大和次大元素
void solve(int a[],int low,int high,int &max1,int &max2) {
    if (low==high) {                     //区间中只有一个元素
        max1 = a[low];
        max2 = INT_MIN;              //表示无穷小
    }
    else if (low==high-1) {        //区间中只有两个元素
        max1 = max(a[low], a[high]);
        max2=min(a[low], a[high]);
    }
    else {                                   //区间有两个以上元素
        int mid = (low + high) / 2;
        int lmax1, lmax2;                          //左区间中求lmax1和lmax2
        solve(a, low, mid, lmax1, lmax2);
 
        int rmax1, rmax2;                          //右区间中求rmax1和rmax2
        solve(a, mid + 1,high, rmax1, rmax2);
 
        if (lmax1> rmax1) {
            max1 = lmax1;
            max2 = max(lmax2, rmax1);              //lmax2、rmax1中求次大元素
        }
        else {
            max1 = rmax1;
            max2 = max(lmax1, rmax2);                 //lmax1、rmax2中求次大元素
        }
 
    }
 
}
 
 
int main() {
    int n = 0;
    cout << "请输入一个数组的元素个数" << endl;
    cin >> n;
    int *a = new int[n];
    cout << "请依次输入数组元素：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max1, max2;
    solve(a,0,n-1, max1, max2);
    cout << "最大值为：" << max1 << " " << "次大值为:" << max2 << endl;
 
    system("pause");
}