#include <bits/stdc++.h>

using namespace std;

// float helper(float x, float y) {
// 	float ans = sqrt((x * x) + (y * y));

// 	return ans;
// }

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	int counter = 1;

	while (t--) {
		double rs, rh;
		cin >> rs >> rh;

		int n; cin >> n;
		vector<vector<double>>red(n, vector<double>(2));

		for (int i = 0; i < n; i++) {
			cin >> red[i][0];
			cin >> red[i][1];
		}

		int m; cin >> m;
		vector<vector<double>>yel(m, vector<double>(2));

		for (int i = 0; i < m; i++) {
			cin >> yel[i][0];
			cin >> yel[i][1];
		}

		int rc = 0, yc = 0;
		vector<double>rd, yd;

		for (int i = 0; i < n; i++) {
			double xi = abs(red[i][0]);
			double yi = abs(red[i][1]);
			xi *= xi;
			yi *= yi;
			yi += xi;

			double dist = sqrt(yi);
			dist -= rs;
			if (dist <= rh) {
				rd.push_back(dist);
			}
		}

		for (int i = 0; i < m; i++) {
			double xi = abs(yel[i][0]);
			double yi = abs(yel[i][1]);
			xi *= xi;
			yi *= yi;
			yi += xi;

			double dist = sqrt(yi);
			dist -= rs;
			if (dist <= rh) {
				yd.push_back(dist);
			}
		}

		sort(rd.begin(), rd.end());
		sort(yd.begin(), yd.end());

		if (yd.size() > 0) {
			if (rd[0] < yd[0]) {
				int i = 0;
				while (i < rd.size() and rd[i] < yd[0]) {
					rc++;
					i++;
				}
			}
			else {
				int i = 0;
				while (i<yd.size() and rd[0]>yd[i]) {
					yc++;
					i++;
				}
			}
			cout << "Case #" << counter << ": " << rc << " " << yc << endl;
		}
		else {
			cout << "Case #" << counter << ": " << rd.size() << " " << "0" << endl;
		}



		counter++;
	}
	return 0;
}
