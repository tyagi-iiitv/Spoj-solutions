#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


typedef vector <int> v;
map<int,v> m;
int main(){
	ios::sync_with_stdio(false);
	stack<int> s;
	int t;
	cin>>t;
	while(t--){
		m.clear();
		int n;
		cin>>n;
		bool counted[n];
		fill_n(counted, n, false);
		int des;
		cin>>des;
		while(des--){
			int first, second;
			cin>>first>>second;
			m[first].push_back(second);
			m[second].push_back(first);
		}
		int itr = 0;
		int cur_person;
		int ans = 0;
		while(itr < n){
			if(!counted[itr]){
				ans++;
				s.push(itr);
				counted[itr] = true;
				while(!s.empty()){
					cur_person = s.top();
					s.pop();
					for(int i=0;i<m[cur_person].size();i++){
						int elem = m[cur_person][i];
						if(!counted[elem]){
							s.push(elem);
							counted[elem] = true;
						}
					}
				}
			}
			itr++;
		}
		cout<<ans<<endl;
	}
	return 0;
}