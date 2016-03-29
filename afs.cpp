#include <iostream>
#include <algorithm>
#define llt long long int
using namespace std;

void generate_counts(llt count[], int len){
	for(int i=2;i<=len;i++){
		int factor = 2;
		int temp = i;
		while(temp*factor <=len){
			count[temp*factor] += i;
			factor++; 
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	static llt count[1000001];
	// cout<<".."<<endl;
	fill_n(count, 1000001, 1);
	generate_counts(count, 1000000);
	static llt ans[1000001];
	ans[0]=0;
	ans[1]=0;
	for(int i=2;i<=1000000;i++){
		ans[i] = ans[i-1]+count[i];
	}
	while(t--){
		int n;
		cin>>n;
		cout<<ans[n]<<endl;
	}
	return 0;
}