#include <iostream>
#include <queue>
using namespace std;

class Cook{
public:
	int rank,cur_parata,time;
	Cook(int rank){
		cur_parata = 1;
		time = rank;
		this->rank = rank;
	}
	bool operator<(const Cook& right)const{
		return time > right.time; 
	}
};

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int p,l;
		cin>>p;
		cin>>l;
		priority_queue<Cook> q;
		while(l--){
			int cur_rank;
			cin>>cur_rank;
			q.push(Cook(cur_rank));
		}
		int ans = 0;
		while(p){
			Cook cur_shef = q.top();
			// cout<<"Cur Shef: "<<cur_shef.rank<<endl;
			q.pop();
			cur_shef.cur_parata++;
			ans = cur_shef.time;
			cur_shef.time += (cur_shef.cur_parata*cur_shef.rank);
			p--;
			q.push(cur_shef); 
		}
		cout<<ans<<endl;
	}
	return 0;
}
