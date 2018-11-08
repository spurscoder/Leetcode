#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

#define MAXN 100000

int main(){

	ofstream out ("text.txt");
	for (int i = 0; i < MAXN; ++i) {
		out << 1 << endl;
	}

	return 0;
}

// int main(){
// 	// Do something
// 	vector<int> numbers1(MAXN, 0);
// 	vector<int> numbers2(MAXN, 0);
// 	freopen("text.txt", "r", stdin);

// 	int start1 = clock();
// 	for (int i = 0; i < MAXN; ++i) {
// 		cin >> numbers1[i];
// 	}
// 	printf("without : %.3lf\n", double(clock() - start1)/CLOCKS_PER_SEC);

// 	ios::sync_with_stdio(false);
// 	cin.tie(0);

// 	int start2 = clock();
// 	for (int i = 0; i < MAXN; ++i) {
// 		cin >> numbers2[i];
// 	}
// 	printf("with : %.3lf\n", double(clock() - start2)/CLOCKS_PER_SEC);
// }
