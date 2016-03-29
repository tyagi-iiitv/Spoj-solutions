#include <iostream>
#define llt long long int
using namespace std;

void mult(llt a[][2], llt b[][2]){
	llt result[2][2];
	result[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0])%1000000007;
	result[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1])%1000000007;
	result[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0])%1000000007;
	result[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1])%1000000007;
	a[0][0] = result[0][0];
	a[0][1] = result[0][1];
	a[1][0] = result[1][0];
	a[1][1] = result[1][1];
}

llt power(llt a){
	llt matrix[2][2] = {{1,1},{1,0}};
	llt temp[2][2] = {{1,0},{0,1}};
	while(a){
		if(a&1){
			mult(temp, matrix);
		}
		mult(matrix, matrix);
		a>>=1;
	}
	return temp[1][0];
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		llt n,m;
		cin>>n>>m; //calculate A^(n+1) and then A[1][0] gives S(n-1). Similarly for m.
		llt ans = (power(m+2)-power(n+1))%1000000007;
		if(ans<0)
			ans += 1000000007;
		cout<<ans<<endl;
	}
	return 0;
}