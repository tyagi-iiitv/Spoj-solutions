#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){
		int bugs, interactions;
		cin>>bugs>>interactions;
		vector<int> v[bugs+1];
		while(interactions--){
			int a, b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}				
		bool ans = true;
		bool visited[bugs+1];
		bool color[bugs+1];
		fill_n(visited, bugs+1, false);
		for(int i=1;i<=bugs && ans;i++){
			if(!visited[i]){
				queue<int> q;
				int cur_pos = i;
				color[cur_pos] = true;
				q.push(cur_pos);
				while(!q.empty() && ans){
					cur_pos = q.front();
					visited[cur_pos] = true;
					q.pop();
					for(int j=0;j<v[cur_pos].size();j++){
						if(visited[v[cur_pos][j]]){ 
							if(color[v[cur_pos][j]] == color[cur_pos]){
								ans = false;
								break;
							}
						}
						else{
							q.push(v[cur_pos][j]);
							color[v[cur_pos][j]] = !color[cur_pos];
						}
					}
				}
			}
		}
		if(!ans){
			cout<<"Scenario #"<<l<<":"<<endl;
			cout<<"Suspicious bugs found!"<<endl;
		}
		else{
			cout<<"Scenario #"<<l<<":"<<endl;
			cout<<"No suspicious bugs found!"<<endl;	
		}
	}
	return 0;
}