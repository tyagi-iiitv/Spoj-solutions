#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string temp;
	while(n != -1){
		int arr[n];
		int sum = 0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			sum += arr[i];
		}
		getline(cin,temp);
		getline(cin,temp);
		if(sum % n != 0){
			cout<<"-1"<<endl;
		}
		else{
			int final_value = sum/n;
			int accumulation = 0;
			int ans = 0;
			for(int i=0;i<n;i++){
				accumulation += arr[i] - final_value;
				ans = max(ans, abs(accumulation));
			}
			cout<<ans<<endl;
		}

		//--------------------code above it---------------------------------------
		cin>>n;
	}
}