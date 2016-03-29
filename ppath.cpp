#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void generate_primes(bool isPrime[], int len){
    isPrime[1]=false;
    isPrime[0]=false;
    for(int i=2;i<=sqrt(len);i++){
        if(isPrime[i]==true){
            for(int j=i*i;j<=len;j=j+i){
                isPrime[j]=false;
            }
        }
    }
}

int generate_num(int num, int i, int j){
    char num_str[4];
    int counter = 3;
    while(num != 0){
        num_str[counter] = num%10;
        num /= 10;
        counter--;
    }
    num_str[i] = j;
    int ans = 0;
    for(int i=0;i<4;i++){
        ans = ans*10 + num_str[i];
    }
    return ans;
}

int main(){
    queue<int> q;
    ios::sync_with_stdio(false);
    bool isPrime[10001];
    fill_n(isPrime, 10001, true);
    generate_primes(isPrime, 10000);
    // vector<int> primes;
    // for(int i=1001;i<9974;i++){
    //     if(isPrime[i]){
    //         primes.push_back(i);
    //         // cout<<i<<" ";
    //     }
    // }
    // cout<<endl;
    int n;
    cin>>n;
    while(n--){
        int dist[10000];
        fill_n(dist, 10000, -1);
        int min, max;
        cin>>min>>max;
        q.push(min);
        dist[min] = 0;
        while(!q.empty()){
            int cur_num = q.front();
            for(int i=3;i>=0;i--){
                for(int j=0;j<=9;j++){
                    int temp = generate_num(cur_num, i, j);
                    if(isPrime[temp] && dist[temp] == -1 && temp > 1000){
                        q.push(temp);
                        dist[temp] = dist[cur_num] + 1;
                        // cout<<"dist["<<temp<<"] = "<<dist[temp]<<endl;
                        // cout<<"pushing: "<<temp<<endl;
                    }
                }
            }
            // cout<<"popping: "<<q.front()<<endl;
            q.pop();
            if(dist[max] != -1){
                while(!q.empty())
                    q.pop();
                break;
            }
        }
        if(dist[max] == -1){
            cout<<"Impossible"<<endl;
        }
        else
            cout<<dist[max]<<endl;
    }
    return 0;
}