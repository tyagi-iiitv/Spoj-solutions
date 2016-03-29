#include <iostream>
#define llt long long int
#define MOD 1000000007
#define MOD2 1000000006
#define MOD3 500000003
using namespace std;

llt power_calculator(llt a, llt b, llt m){ //returns a^b mod m. Also useful for calculating a^b
	llt x=1, y=a;
	while(b>0){
		if(b&1){
			x = (x*y)%m;//Remove %m if calculating a^b		
		}
		y = (y*y)%m;
		b>>=1;
	}
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	llt fact[200001];
	fact[0] = 1;
	for(int i=1;i<=200000;i++){
		fact[i] = (fact[i-1]*i)%MOD3;
	}
	while(t--){
		llt a,b,n;
		cin>>a>>b>>n;
		if(n==0){
			cout<<a<<endl;
			continue;
		}
		llt step_1 = power_calculator(fact[n-1],MOD3-2, MOD3);
		llt step_2 = power_calculator(fact[n], MOD3-2, MOD3);
		llt step_3 = (((fact[2*n-1]*step_1)%MOD3)*(step_2))%MOD3;
		step_3 = (step_3*2)%MOD2;
		llt ans = power_calculator(step_3, b, MOD2);
		llt result = power_calculator(a, ans, MOD);
		cout<<result<<endl;
	}
	return 0;
}
