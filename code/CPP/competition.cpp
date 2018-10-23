#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <unordered_set>
#include <utility>
using namespace std;

int commpetition(vector<string> &team, vector<vector<string>> &special) {
	int len = team.size();
	if (len == 0) return 0;
	map<int, string> int_2_team;
	map<string, int> team_2_int;
	vector<vector<pair<int, int>>> determined_group(len-1, vector<pair<int,int>>());
	unordered_set<pair<int, int>> determined_set;
	for (int i = 0; i < team.size(); ++i) {
		int_2_team[i] = team[i];
		team_2_int[team[i]] = i;
	}

	// switching
	for (int i = 0; i < special.size(); ++i) {
		vector<int> temp;
		if (!special[i].empty()) {
			for (auto s:special[i])
				temp.push_back(team_2_int[s]);
		}
		determined_group.push_back(temp);
	}

	// recording special
	for (int i = 0; i < len; ++i) 
		for (int j = i+1; j < len; ++j)
			determined_set.insert(make_pair(i, j));

	for (auto it=determined_set.begin(), it != determined_set.end(); ++it)
		cout << it.first() << " " << it.second() << endl;
	return 1;
}

int main(){
	vector<string> team{"q", "w", "e", "r", "s", "a"};
	vector<vector<string>> special{{make_pair("r","e")}, {}, {make_pair("r","s")}, {}, {}};
	commpetition(team, special);
	return 0;
}