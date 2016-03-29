#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int arr[101][101];
stack<char> s;
string a,b;


int main(){
	ios::sync_with_stdio(false);
	while(cin>>a>>b){
		int size1 = a.length();
		int size2 = b.length();
		for(int i=0;i<=size1;i++){
			arr[i][0]= 0;
		}
		for(int j=0;j<=size2;j++){
			arr[0][j] = 0;
		}
		for(int i=1;i<=size1;i++){
			for(int j=1;j<=size2;j++){
				if(a[i-1] == b[j-1])
					arr[i][j] = arr[i-1][j-1] + 1;
				else
					arr[i][j] = max(arr[i-1][j], arr[i][j-1]);	
			}
		}
		// for(int i=0;i<=size1;i++){
		// 	for(int j=0;j<=size2;j++){
		// 		cout<<arr[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		int i = size1;
		int j = size2;
		while(i != 0 && j != 0){
			if(arr[i][j-1] == arr[i][j])
				j--;
			else if(arr[i-1][j] == arr[i][j])
				i--;
			else{
				s.push(b[j-1]);
				i--;
				j--;
			}

		}
		int cur_a = 0;
		int cur_b = 0;
		while(!s.empty()){
			char cur_char = s.top();
			s.pop();
			while(a[cur_a] != cur_char){
				cout<<a[cur_a];
				cur_a++;
			}
			while(b[cur_b] != cur_char){
				cout<<b[cur_b];
				cur_b++;
			}
			cout<<cur_char;
			cur_a++;
			cur_b++;
		}
		while(cur_a < size1){
			cout<<a[cur_a];
			cur_a++;
		}
		while(cur_b < size2){
			cout<<b[cur_b];
			cur_b++;
		}
		cout<<endl;
	}

}