#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		map<long long, long long> mp[k];
		// to solve the problem, every k-th subarray must have the same permutation of elements
		// collect the numbers in every 0 to (k - 1)-th position and store their frequency
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			mp[i % k][num]++;
		}
		long long ans = 0;
		for (int i = 0; i < k; i++) {
			// in every 0 to (k - 1)-th position, we need to make sure that all elements are the same
			// to do that, we need to find the elements with the highest frequency and replace all the
			// other remaining elements with this number in order to get the minimum modifications
			// minimum modification for each 0 to (k - 1)-th position:
			// = total frequency - highest frequency of a number
			long long total = 0;
			long long mx = LLONG_MIN;
			for (auto[num, freq] : mp[i]) {
				total += freq;
				mx = max(mx, freq);
			}
			ans += (total - mx);
		}
		cout << ans << '\n';
	}
	return 0;
}
