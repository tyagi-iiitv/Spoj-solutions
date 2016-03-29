#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int cases;
	cin>>cases;
	int n,k,b,t; //n = number of chicks, k = min no. of chicks required, b = position of barn, t = time left to fill in chicks
	for (int i=1;i<=cases;i++){
		cin>>n>>k>>b>>t;
		int x[n], v[n];
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
		for(int j=0;j<n;j++){
			cin>>v[j];
		}
		bool pass[n];
		for(int j=0;j<n;j++){
			pass[j] = (v[j]*t >= b-x[j]?true:false);
		}
		int count0 = 0, count1 = 0;
		int j = n-1;
		int swap = 0;
		while(j>=0 && k>0){
			if(pass[j] == true && count0 == 0){
				k--;
			}
			else if(pass[j] == false){
				count0++;
			}
			else{
				swap += count0;
				k--;
			}
			j--;
		}
		if(k==0)
			cout<<"Case #"<<i<<": "<<swap<<endl;
		else
			cout<<"Case #"<<i<<": IMPOSSIBLE"<<endl;
	}
	return 0;
}