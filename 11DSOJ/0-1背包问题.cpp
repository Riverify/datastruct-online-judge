#include<iostream>
#include<algorithm> 
using namespace std;
int main(){
	int n,M;
	cin>>n>>M;
	int i,j;
	int f[50][50];
	int wi[n+1],pi[n+1];
	for(i=1;i<=n;i++){
		cin>>wi[i];
	}
	for(i=1;i<=n;i++){
		cin>>pi[i];
	}
	for(i=0;i<=n;i++){
		f[0][i]=0;
	}
	for(i=0;i<=M;i++){
		f[i][0]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=M;j++){
			if(j>=wi[i]){
				f[i][j]=max(f[i-1][j-wi[i]]+pi[i],f[i-1][j]);
			}else{
				f[i][j]=f[i-1][j];
			}
		}
	}
//	for(i=0;i<=n;i++){
//		for(j=0;j<=M;j++){
//			cout<<f[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	cout<<f[n][M]<<endl;
	return 0;
} 
