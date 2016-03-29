#include <iostream>
#include <string.h>
using namespace std;

int gcd(long a, long b){
	return b==0?a:gcd(b,a%b);
}
long get_num(string value){
	char* ans;
	int count;
	for (int i=0;i<value.size();i++){
		if(value[i]=='.'){
			count = i;
			break;
		}
	}
	strncpy(ans, value.c_str(), count);
	cout<<string(ans)<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	string value;
	while(t--){
		cin>>value;
		long numerator = get_num(value);
		// long denominator = get_den(value);
		// int divide_by = gcd(numerator, denominator);
		// cout<<denominator/divide_by<<endl;
	}
	return 0;
}