#include <iostream>
#include <cstdio>
#include <string.h>
#include <climits>
#include <cmath>
#define L 1
#define R 0
using namespace std;
char forest[201][201];
int dp[201][201][2];
int dpmax(int m,int n,int i,int j,int dir){
	if(i>=m||j>=n||i<0||j<0||forest[i][j]=='#')
		return 0;
	if(dp[i][j][dir]!=-1)
		return dp[i][j][dir];
	int maxtt=0;
	if(forest[i][j]=='T')
		maxtt=1;
	int maxt=INT_MIN;
	if(dir==R){
		maxt=max(maxt,maxtt+dpmax(m,n,i,j+1,R));
		maxt=max(maxt,maxtt+dpmax(m,n,i+1,j,L));
	}
	if(dir==L){
		maxt=max(maxt,maxtt+dpmax(m,n,i,j-1,L));
		maxt=max(maxt,maxtt+dpmax(m,n,i+1,j,R));
	}
	dp[i][j][dir]=maxt;
	return maxt;
}
int main() {
	// your code goes here
	int t,m,n,i,j,maxt;
	scanf("%d",&t);
	while(t--){
		maxt=0;
		memset(dp,-1,sizeof(dp));
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)
			scanf("%s",forest[i]);
			
		maxt=max(dpmax(m,n,0,0,R),maxt);
		printf("%d\n",maxt);
	}
	return 0;
}
