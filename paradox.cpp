#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int values;
	cin>>values;
	while(values!=0){
		int inp_num[values+1];
		bool inp_value[values+1];
		for(int i=1;i<=values;i++){
			cin>>inp_num[i];
			string temp;
			cin>>temp;
			if(temp[0] == 'f')
				inp_value[i] = false;
			else
				inp_value[i] = true;
		}
		bool ans = true;
		bool visited[values+1];
		fill_n(visited, values+1, false);
		for(int i=1;i<=values;i++){
			if(visited[i])
				continue;
			// cout<<i<<endl;
			int par_search[values+1];
			fill_n(par_search, values+1, -1); //-1 for uninitialised, 0 for false and 1 for true
			int cur_line = i;
			par_search[cur_line] = 1;
			int next_line = inp_num[i];
			while(par_search[next_line] == -1){
				visited[cur_line] = true;
				if(par_search[cur_line] == 1){
					par_search[next_line] = (int)inp_value[cur_line];
				}
				else{
					par_search[next_line] = (int)(!inp_value[cur_line]);
				}
				cur_line = next_line;
				next_line = inp_num[cur_line];
			}
			visited[cur_line] = true;
			if(par_search[cur_line]){
				if(par_search[next_line] != inp_value[cur_line]){
					ans = false;
					break;
				}
			}
			else{
				if(par_search[next_line] == inp_value[cur_line]){
					ans = false;
					break;
				}
			}
		}
		if(ans)
			cout<<"NOT PARADOX"<<endl;
		else
			cout<<"PARADOX"<<endl;
		cin>>values;
	}
	return 0;
}