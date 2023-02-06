#include <iostream>
#include <math.h>
#include <map>

using namespace std;
map <long long, int> mp;
long long F(long long num) {
	if (mp[num] != 0) return mp[num];
	if (num == 0) return 0;
	if (num == 1) return 1;
	if (num % 2 == 0)
	{
		long long f1 = F(num / 2 - 1);
		long long f2 = F(num / 2);
		mp[num] = (f2 * (2 * f1 + f2)) % 1000000007;
	}
	else {
		long long f1 = F(num / 2 + 1);
		long long f2 = F(num / 2);
		mp[num] =  (f1 * f1 + f2 * f2) % 1000000007;
	}
	return mp[num];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	cout << F(n);
	return 0;
}