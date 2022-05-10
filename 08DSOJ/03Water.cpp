#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    int a[n],w[m];
    for(i=0;i<m;i++) w[i]=0;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int y=0;
    for(i=0;i<n-m;i++)
    {
        w[i%m]+=a[i];
        y+=w[i%m];
    }
 
    printf("%d\n",y);
    return 0;
}