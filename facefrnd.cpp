#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, bool> fof;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		fof[temp] = false;
		int n_fof;
		cin>>n_fof;
		while(n_fof--){
			cin>>temp;
			if(fof.count(temp) == 0){
				fof[temp] = true;
			}
		}
	}
	map<int, bool>::iterator pos;
	int ans = 0;
	for(pos = fof.begin();pos != fof.end();pos++){
		if(pos->second == true)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}