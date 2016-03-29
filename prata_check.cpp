#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>


using namespace std;
typedef long long i64;
typedef vector<int> vi;






struct cook
{
	int time,rate,n;
	cook(int _rate){time = _rate;rate = _rate; n = 0;}
	bool operator<(const cook& other) const
	{
		if( time == other.time) return rate > other.rate;
		return time > other.time;
	}	
};


int readInt() {
    int n = 0;
    char c = getchar();
    while ( !( '0' <= c && c <= '9' ) ) {
        c = getchar_unlocked();
    }
    while ( '0' <= c && c <= '9' ) {
        n = n * 10 + c - '0';
        c = getchar();
    }
    return n;
}


int main()
{
	int test,p,l,temp;
	//best(1);
	scanf("%d",&test);
	while(test--){
		//scanf("%d %d",&p,&l);
		p = readInt();
		l = readInt();
		priority_queue<cook> q;
		for(int i=0;i<l;i++){
			//scanf("%d",&temp);
			temp = readInt();
			q.push(cook(temp));
		}
		for(int i=0;i<p;i++){
			cook best = q.top();
		//	printf("%d %d %d\n",best.time,best.rate,best.n);
			q.pop();
			best.n++;
			best.time += best.rate * (best.n +1);
			q.push(best);
		}
		int mtime = INT_MIN;
		while(!q.empty()){
			cook best = q.top();
			//printf("%d %d %d\n",best.time,best.rate,best.n);
			
			mtime = max(mtime,best.rate*best.n*(best.n+1)/2);;
			q.pop();
		}
		printf("%d\n",mtime);
	}
	return 0;
}
	