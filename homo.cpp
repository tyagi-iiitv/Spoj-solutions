#include <iostream>
#define llt long long int
#include <map>
using namespace std;

map <llt, int> m;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int hetero=0, homo=0;
	while(n--){
		string input; 
		llt value;
		cin>>input>>value;
		if(input[0] == 'i'){
			m[value]++;
			if(m[value] == 2)
				homo++;
			else if(m[value] == 1)
				hetero++;
		}
		else{
			if(m[value] != 0){
				m[value]--;
				if(m[value] == 1)
					homo--;
				else if(m[value] == 0)
					hetero--;
			} 
		}
		if(homo > 0 && hetero > 1)
			cout<<"both"<<endl;	
		else if(homo > 0)
			cout<<"homo"<<endl;
		else if(hetero > 1)
			cout<<"hetero"<<endl;
		else
			cout<<"neither"<<endl;
	}
	return 0;
}