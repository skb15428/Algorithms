#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(sqrt(n))
bool isPrime(int n)     // <= Optimised method
{
    // Corner cases 
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

bool isprime(int n)         // Time Complexity O(sqrt(n))
{
	if (n == 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i * i <= n; i+=2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cout << "Enter a number\n";
		cin >> n;
		isprime(n) ? cout << "prime\n" : cout << "not prime\n";
	}
}
