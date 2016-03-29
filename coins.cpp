#include <iostream>
#include <map>
#define llt long long int
using namespace std;

map<int , llt> values;

llt result(int n){
	if(values[n] != 0){
		return values[n];
	}
	else{
		if(n < 12){
			values[n] = n;
			return n;
		}
		else{
			llt ans = result(n/2)+result(n/4)+result(n/3);
			if(ans > n){
				values[n] = ans;
				return ans;
			}
			else{
				values[n] = n;
				return n;
			}
		}
	} 
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		cout<<result(n)<<endl;
	}
	return 0;
}