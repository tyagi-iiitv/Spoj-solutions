#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<int> v;
map<int, v> m;
map<int, bool> visited;
map<int, int> dist;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	n--;
	while(n--){
		int first;
		int second;
		cin>>first>>second;
		m[first].push_back(second);
		m[second].push_back(first);
		visited[first] = false;
		visited[second] = false;
		// dist[first] = -1;
		// dist[second] = -1;
	}
	map<int, v>::iterator itr;
	map<int, bool>::iterator vis_itr;
	stack<int> s;
	int ans = 0;
	for(itr = m.begin();itr != m.end();itr++){
		for(vis_itr = visited.begin();vis_itr!=visited.end();vis_itr++)
			vis_itr->second = false;
		if(!visited[itr->first]){
			int cur_node = itr->first;
			dist[cur_node] = 0;
			s.push(cur_node);
			visited[cur_node] = true;
			while(!s.empty()){
				cur_node = s.top();
				// cout<<cur_node<<endl;
				s.pop();
				for(int i=0;i<m[cur_node].size();i++){
					int temp = m[cur_node][i];
					if(!visited[temp]){
						dist[temp] = dist[cur_node]+1;
						visited[temp] = true;
						// cout<<"cur_dist: "<<dist[temp]<<" at node: "<<temp<<endl;
						s.push(temp);
						// cout<<"pushing: "<<temp<<endl;
						ans = max(ans, dist[temp]);
					}
				}
			}
		}
	}
	cout<<ans<<endl;	
	return 0;
}