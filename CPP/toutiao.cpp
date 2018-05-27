// #include <bits/stdc++.h>

// using namespace std;

// // #define INT_MAX 10000000
// // #define INT_MIN -1

// class Question2 {
// public:
// 	int solution(vector<int>& data, int n, int m) {
// 		vector<int> index(m+1, 0);
// 		int k = 1, j = 1;
// 		bool flag = false;
// 		index[m] = n;
// 		int ans = INT_MAX;

// 		while (1) {
// 			if (k == 0)
// 				break;
// 			if (j <= n) {
// 				if (k < m) {
// 					index[k] = j;
// 					++k;
// 					++j;
// 				}
// 				else {
// 					int cur_max = INT_MIN;
// 					for (int i = 0; i < m; ++i) {
// 						int cur_sum = 0;
// 						for (int j = index[i]; j < index[i + 1]; ++j) {
// 							cur_sum += data[j];
// 						}
// 						//cout << cur_sum << " ";
// 						cur_max = max(cur_max, cur_sum);
// 						if (cur_max > ans)
// 							break;
// 					}
// 					//cout << endl;
// 					ans = min(ans, cur_max);

// 					if (index[k] < n) {
// 						index[k] += 1;
// 						j += 1;
// 					}
// 					else {
// 						--k;
// 						j = index[k] + 1;
// 					}
// 				}
// 			}
// 			else {
// 				--k;
// 				j = index[k] + 1;
// 			}
// 		}
// 		return ans;
// 	}
// };

// vector<int> read_data(int n, int m) {
// 	vector<int> result(n, 0);
// 	for (int i = 0; i < n; ++i)
// 		cin >> result[i];
// 	return result;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long lmax = 1000000;

int n, m;

int solve(vector<int> &d){
    vector<vector<long> > f(n + 1, vector<long>(m + 1, 0));
    f[0][1]=0;
    for(int i = 1; i <= n; i++)
        f[i][1] = f[i-1][1] + d[i];

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m && j <= i; j++){
            long temp = lmax;
            for(int k = 1; k < i; k++){
                long max1 = max(f[i][1]-f[k][1],f[k][j-1]);
                if(max1 < temp) temp = max1;
            }
            f[i][j] = temp;
        }
    }
    return f[n][m];
}

int main()
{
	int n = 5, m = 3;
	freopen("data.txt", "r", stdin);

	int start1 = clock();
	cin >> n >> m;
	vector<int> d(n + 1, 0);
	for(int i = 1; i <= n; ++i) cin >> d[i];
	cout << solve(d) << endl;
	printf("without : %.3lf\n", double(clock() - start1)/CLOCKS_PER_SEC);

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("data.txt", "r", stdin);

	int start2 = clock();
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> d[i];
	cout << solve(d) << endl;
	printf(" with : %.3lf\n", double(clock() - start2)/CLOCKS_PER_SEC);

	return 0;
}