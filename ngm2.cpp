#include <iostream>
using namespace std;
// slow gcd algo
long long gcd(long long a,long long b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
int main()
{
	long long n,k,i,tot,b,j,count,sum;
	long long ar[16];
	scanf("%lld%lld",&n,&k);
	for(i=0;i<k;i++)
	scanf("%lld",&ar[i]);
	sum=0;
	tot=1 << k;
	for(i=1;i<tot;i++)
	{
		b=1;count=0;
		for(j=0;j<k;j++)
		{
			if(i & (1 << j))
			{
			cout<<i<<" "<<j<<" "<<(1<<j)<<endl;
			count++;
			cout<<"count : "<<count<<endl;
			b=(b*ar[j])/gcd(b,ar[j]);
			cout<<"b: "<<b<<endl;
			}
		}
		if(count%2==0){
			sum=sum+(n/b);
			cout<<"sum : "<<sum<<endl;
		}
		else{
			sum=sum-(n/b);
			cout<<"sum: "<<sum<<endl;
		}
	}
	printf("%lld\n",sum+n);
	return 0;
}
