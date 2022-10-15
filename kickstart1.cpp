#include <bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	int counter = 1;

	while (t--) {
		int m, n, p;
		cin >> m >> n >> p;

		vector<vector<int>>arr(m, vector<int>(n));
		// vector<int>john(n);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				// if (i == (p - 1)) {
				// 	john[j] = arr[i][j];
				// }
			}
		}

		int ans = 0;

		for (int i = 0; i < n; i++) {
			int tj;
			int maxi = INT_MIN;
			for (int j = 0; j < m; j++) {
				if (j == (p - 1)) {
					tj = arr[j][i];
					continue;
				}
				maxi = max(maxi, arr[j][i]);
			}
			// cout << tj << " " << maxi << endl;
			if (maxi > tj) {
				ans += (maxi - tj);
			}
		}

		cout << "Case #" << counter << ": " << ans << endl;
		counter++;
	}
	return 0;
}
