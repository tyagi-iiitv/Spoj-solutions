#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n, limit;
		cin>>n;
		if(n==0){
			cin>>limit;
			cout<<"Case "<<i<<": 0"<<endl;
		}
		else{
			int seconds[n];
			for(int j=0;j<n;j++){
				string temp;
				cin>>temp;
				seconds[j] = 0;
				int hms = 1;
				int cur_time = 0;
				for(int k=0;k<temp.length();k++){
					// cout<<"=> "<<temp[k]-'0'<<endl;
					if(temp[k] != ':'){
						// cout<<"Entering if"<<endl;
						cur_time = (cur_time*10 + (temp[k]-'0'));
					}
					else{
						if(hms == 1){
							// cout<<"Entering else 1"<<endl;
							seconds[j] += cur_time*3600;
						}
						else if(hms == 2){
							// cout<<"Entering else 2"<<endl;
							seconds[j] += cur_time*60;
						}
						// cout<<"Entering else 4"<<endl;
						cur_time = 0;
						hms++;
					}
				}
				seconds[j] += cur_time;
				// cout<<seconds[j]<<endl;
			}
			cin>>limit;
			sort(seconds, seconds+n);
			queue<int> gfs;
			int j=0;
			int cur_gf;
			int final_gfs = 0;
			while(j<n){
				if(gfs.size() == 0){
					cur_gf = seconds[j];
					// cout<<"cur_gf "<<cur_gf<<endl;
					j++;
				}
				else{
					cur_gf = gfs.front();
					// cout<<"cur_gf "<<cur_gf<<endl;
					gfs.pop();
				}
				while(seconds[j] - cur_gf < limit && j < n){
					gfs.push(seconds[j]);
					// cout<<"pushing "<<seconds[j]<<endl;
					final_gfs = max(final_gfs, (int)gfs.size());
					j++;
				}
			}
			cout<<"Case "<<i<<": "<<final_gfs+1<<endl;	
		}
	}
	return 0;
}