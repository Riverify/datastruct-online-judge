#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int s[1010],a[1010];
    int n,sum1=0,sum2=0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
       cin >> s[i];
        a[i] = s[i];
    }
    for(int i = 0; i < n-1; i++)
    {
        sort(s+i,s+n);           
        sum1 = sum1 + s[i] + s[i+1];
        s[i+1] += s[i];
 
        sort(a,a+n-i);          
        sum2 = sum2 + a[n-1-i] + a[n-2-i];
        a[n-2-i] += a[n-1-i];
    }
   cout << sum2-n+1 << " " <<sum1-n+1 << '\n';
    return 0;
}
 