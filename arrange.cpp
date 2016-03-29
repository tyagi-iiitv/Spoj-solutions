#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int arr[100000];
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr, arr+n);
		int j=0;
		while(arr[j] == 1){
			cout<<"1 ";
			j++;
		}
		if(j == n-2 && arr[j] == 2 && arr[j+1] == 3){
			cout<<"2 3 ";
		}
		else{
			for(int i=n-1;i>=j;i--)
				cout<<arr[i]<<" ";
		} 
		cout<<endl;
	}
	return 0;
}