#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <fstream>

using namespace std;

std::wstring StringToWString(const std::string& str)
{
    setlocale(LC_ALL, "chs");
    const char* point_to_source = str.c_str();
    size_t new_size = str.size() + 1;
    wchar_t *point_to_destination = new wchar_t[new_size];
    wmemset(point_to_destination, 0, new_size);
    mbstowcs(point_to_destination, point_to_source, new_size);
    std::wstring result = point_to_destination;
    delete[]point_to_destination;
    setlocale(LC_ALL, "C");
    return result;
}

void count(int n, vector<int>& temp) {
	if (n == 0) {
		for (int i = 0; i < temp.size(); ++i)
			cout << temp[i] << " ";
		cout << endl;
	} else {
		for (int i = 0; i < n; ++i) {
			swap(temp[i], temp[n-1]);
			count(n-1, temp);
			swap(temp[i], temp[n-1]);
		}
	}
}
void AllRange( vector<int>& temp,int start,int length)
{
	if(start == length-1)
	{
		for (int i = 0; i < temp.size(); ++i)
			cout << temp[i] << " ";
		cout << endl;
	}
	else
	{
		for(int i=start;i<=length-1;i++)	
		{	//从下标为start的数开始，分别与它后面的数字交换
			swap(temp[start],temp[i]); 
			AllRange(temp,start+1,length);
			swap(temp[start],temp[i]); 
		}
	}
}
int main(){

	vector<int> temp;
	for (int i = 0; i < 3; ++i)
		temp.push_back(i);
	count(3, temp);
	// AllRange(temp, 0, 3);


 //    // setlocale(LC_ALL, "chs");
	// locale::global(locale("zh_CN.UTF-8"));

	// wifstream in("data.txt");
	// // in.imbue(locale("zh_CN.UTF-8"));
	// // cout.imbue(locale("zh_CN.UTF-8"));
	// // cout << "test" << endl;
	// // wcout.imbue(locale("zh_CN.UTF-8"));
	// wstring temp;
	// while (in >> temp) {
		
	// 	wcout << temp << endl;
	// }
	// wstring t  = StringToWString(wcout.getloc().name());
 //    wcout << L"Current locale: " << t << L'\n';
 //    // cout << "Current locale: " << in.getloc().name() << '\n';




	// locale loc("zh_CN.UTF-8");
 //    locale::global(loc);

 //    wifstream in("data.txt");
	// in.imbue(locale("zh_CN.UTF-8"));
 //    // wcout.imbue(locale(""));
    
	// int num_pre, num_str;
	// wstring temp;
	// unordered_set<wstring> str_set;
	// vector<int> res;

	// in >> num_pre >> num_str;
	// for (int i = 0; i < num_pre; ++i) {
	// 	in >> temp;
	// 	str_set.insert(temp);
	// }

	// for (int i = 0; i < num_str; ++i) {
	// 	in >> temp;
	// 	int exist = -1;
	// 	wstring pre = L"";
	// 	wcout << res.size() << endl;
	// 	for (int j = 0; j < temp.size(); ++j) {
	// 		pre += temp[j];
	// 		wcout << pre << endl;

	// 		if (str_set.find(pre) != str_set.end()) {
	// 			exist = 1;
	// 			break;
	// 		}
	// 	}
	// 	res.push_back(exist);
	// }

	// for(int i = 0; i < res.size(); ++i) {
	// 	wcout << res[i] << endl;
	// }
	// wcout << res.size() << endl;

	// return 0;
}


























































// #include <iostream>
// #include <vector>
// #include <wstring>

// using namespace std;

// int score(string& words, string& documents) {
// 	char start = words[0];
// 	int res = 0;
// 	for (int k = 0; k < documents.size(); ++k) {
// 		if (documents[k] != start) continue;
// 		int index = 0;
// 		vector<int> sco;
// 		for (int i = k; i < documents.size(); ++i) {
// 			if (index < words.size() && documents[i] == words[index]) {
// 				++index;
// 				sco.push_back(i);
// 			}
// 			if (index == words.size()) {
// 				// searching
// 				int temp = 0;
// 				for (int t = 1; t < sco.size(); ++t ) {
// 					temp += sco[t] - sco[t-1] - 1;
// 				}
// 				res = max(res, 100 - temp);

// 				index = 0;
// 				sco.clear();
// 			}
// 		}
// 	}

// 	return res;
// }

// int main() {

// 	string words, documents;

// 	wcin >> words >> documents;
// 	cout << score(words, documents) << endl;

// 	// string words = "m";
// 	// string words1 = "mbh";
// 	// string words2 = "hbg";
// 	// string words3 = "hc";
//  // 	string documents = "amhbgyhdc";

// 	// cout << score(words, documents) << endl;
// 	// cout << score(words1, documents);
// 	// cout << score(words2, documents);
// 	// cout << score(words3, documents);

// }