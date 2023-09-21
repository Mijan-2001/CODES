#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
bool mark[N];
vector<int> primes;
vector<pair<int, int>> d;

int bin_expo(int a, int n) {
	if (n == 0) return 1;
	int ret = bin_expo(a, n/2);
	if (n & 1) return (ret * ret * a);
	return ret * ret;
}

void sieve() {
	primes.push_back(2);
	for (int i = 3; i*i <= N-10; i += 2) {
		if (mark[i]) continue;
		for (int j = i*i; j <= N-10; j += i) mark[j] = 1;
	}
	for (int i = 3; i <= N-10; i += 2) {
		if (!mark[i]) primes.push_back(i);
	}
}

void pf(int num) { // O(logN)
	d.clear();
	for (int i = 0; primes[i]*primes[i] <= num && i < (int)primes.size(); ++i) {
		if (num % primes[i] == 0) {
			int cnt = 0;
			while (num % primes[i] == 0) {
				cnt++;
				num /= primes[i];
			}	
			d.push_back({primes[i], cnt});
		}
	}
	if (num > 1) d.push_back({num, 1});
}

int verify(int num) {
	int ret = 0;
	for (int i = 1; i*i <= num; ++i) {
		if (num % i == 0) {
			ret += i;
			if (num/i != i) ret += (num/i);
		}
	} return ret;
}

int main() {
	sieve();
	int n; cin >> n;
	pf(n);
	int cod = 1;
	for (auto p: d) {
		cod *= (p.second + 1);
	} cout << cod << endl;
	int sod = 1;
	for (auto p: d) {
		sod *= (bin_expo(p.first, p.second + 1) - 1)/(p.first - 1);
	} cout << sod << endl;
	cout << verify(n) << endl;
}