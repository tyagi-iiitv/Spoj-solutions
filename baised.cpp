#include <iostream>	
#include <algorithm>
#include <queue>
#define llt long long int
using namespace std;

struct str{
	string name;
	int rank;
	int gap;
};

int main(){
	ios::sync_with_stdio(false);
	llt t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		queue<struct str> q;
		int c = n;
		while(c--){
			struct str temp;
			cin>>temp.name;
			cin>>temp.rank;
			temp.gap = 0;
			q.push(temp);
		}
		// string final[n+1];
		bool set[n+1];
		fill_n(set, n+1, false);
		llt ans = 0;
		while(!q.empty()){
			struct str cur_elem = q.front();
			q.pop();
			if(cur_elem.rank + cur_elem.gap <= n && !set[cur_elem.rank + cur_elem.gap]){
				set[cur_elem.rank + cur_elem.gap] = true;
				ans += cur_elem.gap;
				// final[cur_elem.rank + cur_elem.gap] = cur_elem.name;
			}
			else if(cur_elem.rank - cur_elem.gap > 0 && !set[cur_elem.rank - cur_elem.gap]){
				set[cur_elem.rank - cur_elem.gap] = true;
				ans += cur_elem.gap;
				// final[cur_elem.rank - cur_elem.gap] = cur_elem.name;
			}
			else{
				cur_elem.gap++;
				q.push(cur_elem);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}