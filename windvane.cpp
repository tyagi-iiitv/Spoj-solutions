#include <iostream>
#include <map>

using namespace std;

int main(){
	map<char, int> ref;
	ref['N'] = 0;
	ref['E'] = 1;
	ref['S'] = 2;
	ref['W'] = 3;
	map<int, char> mapper;
	mapper[0] = 'N';
	mapper[1] = 'E';
	mapper[2] = 'S';
	mapper[3] = 'W';

	int m,n;
	cin>>m>>n;
	int arr[m][n];
	for (int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			char temp;
			cin>>temp;
			arr[i][j] = ref[temp];
		}
	}
	int num;
	cin>>num;
	while(num--){
		char temp;
		cin>>temp;
		if(temp == 'C'){
			int p,q,r,s,t;
			cin>>p>>q>>r>>s>>t;
			if(t==1){
				for(int i=p-1;i<r;i++){
					for(int j=q-1;j<s;j++){
						arr[i][j]--;	
					}
				}
			}
			else{
				for(int i=p-1;i<r;i++){
					for(int j=q-1;j<s;j++){
						arr[i][j]++;	
					}
				}
			}
		}
		else{
			int i,j;
			cin>>i>>j;
			int ans = arr[i-1][j-1]%4;
			if (ans < 0){
				ans += 4;
			}
			cout<<mapper[ans]<<endl;
		}
	}
	return 0;
}