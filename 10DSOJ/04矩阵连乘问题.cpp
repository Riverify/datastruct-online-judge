#include<iostream>
using namespace std;
int s[10][10]={0};
void Traceback(int i,int j){
	if(i==j){
		cout<<'A'<<i;return;
	}
	if(i<s[i][j])cout<<'(';
	Traceback(i,s[i][j]);
	if(i<s[i][j])cout<<')';
	if(s[i][j]+1<j)cout<<'(';
	Traceback(s[i][j]+1,j);
	if(s[i][j]+1<j) cout<<')';
}
int main(){

	int n,i,j,r,k;
	cin>>n;
	int p[n+1];

    
	int m[n][n]={0};
	for(i=0;i<n+1;i++){
		cin>>p[i];
	}
	for(i=0;i<n;i++){
		m[i][i]=0;
	}
	for(r=2;r<=n;r++){
		for(i=0;i<=n-r;i++){
		    j=i+r-1;
			m[i][j]=m[i+1][j]+p[i]*p[i+1]*p[j+1];
			s[i][j]=i;
			for(k=i+1;k<j;k++){
				int t=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	}
	cout<<m[0][n-1]<<endl;

	// cout<<'(';
	// Traceback(0,n-1);
	// cout<<')';
	cout<<endl; 
	return 0;
} 
 
