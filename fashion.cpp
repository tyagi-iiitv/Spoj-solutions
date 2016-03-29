#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int men[1000];
	int women[1000];
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>men[i];
		}
		for(int i=0;i<n;i++){
			cin>>women[i];
		}
		sort(men, men+n);
		sort(women, women+n);
		int sum = 0;
		for(int i=0;i<n;i++){
			sum += (men[i] * women[i]);
		}
		cout<<sum<<endl;
	}
	return 0;
}