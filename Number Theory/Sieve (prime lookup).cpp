#include<bits/stdc++.h>
#define max 1000001
using namespace std;

vector<bool>isprime(max, true);	
					// true=prime and false=not prime
void sieve()				// Time complexity = O(nlog(log(n))) and space complexity = O(n) 
{
	isprime[0] = isprime[1] = false;
	for (int i = 2; i * i <= max; i++)
	{
		if (isprime[i] == true)
		{
			for (int j = i * i; j <= max; j += i)
				isprime[j] = false;
		}
	}
}
bool prime(int n)
{
	if (n < 2)
		return false;
	else
		return isprime[n];
}

int main()
{
	sieve();
	int n;
	cout << "Enter a number\n";
	cin >> n;
	prime(n) ? cout << "prime" : cout << "not prime";
}
