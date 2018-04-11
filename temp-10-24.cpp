#include <iostream>		// std::out
#include <algorithm>	// std::binary_search, std::sort
#include <vector>		// std::vector

class Solution {
public:


private:


};

void myfunction(int i) { std::cout << ' ' << i; }

struct myclass {
	void operator() (int i) { std::cout << ' ' << i; }
} myobject;

int main() {
	std::vector<int> myvector;
	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);

	std::cout << "myvector contains:";
	std::for_each(myvector.begin(), myvector.end(), myfunction);
	std::cout << '\n';

	// or:
	std::cout << "myvector contains:";
	std::for_each(myvector.begin(), myvector.end(), myobject);
	std::cout << '\n'; 

	return 0;
}
//
//int main() {
//	int myints[] = { 1,2,3,4,5,6,7,6};
//	std::vector<int> v(myints, myints + 8);
//
//	std::sort(v.begin(), v.end());
//
//	std::vector<int>::iterator low, up;
//	low = std::lower_bound(v.begin(), v.end(), 12);
//	up = std::upper_bound(v.begin(), v.end(), 0);
//
//	//std::cout << *low << '\n';
//	//std::cout << *up << '\n';
//
//	std::cout << "lower_bound at position " << (low - v.begin()) << '\n';
//	std::cout << "upper_bound at position " << (up - v.begin()) << '\n';
//}


/*
 this is for std::find;

int main() {
	// using std::find with array and pointer:
	int myints[] = { 10,20,30,40 };
	int * p;

	p = std::find(myints, myints + 4, 30);
	if (p != myints + 4)
		std::cout << "Element found in myints: " << *p << '\n';
	else
		std::cout << "Element not found in myints\n";

	// using std::find with vector and iterator:
	std::vector<int> myvector(myints, myints + 4);
	std::vector<int>::iterator it;

	it = std::find(myvector.begin(), myvector.end(), 30);
	if (it != myvector.end())
		std::cout << "Element found in myvector: " << *it << '\n';
	else
		std::cout << "Element not found in myvector\n";

	return 0;
}
*/

// ===================================================
// this is for binary_search, which must be in_order
// ===================================================
/*
int main() {
	Solution A = Solution();


	//int myints[] = { 1,2,3,4,5,4,3,2,1 };
	//std::vector<int> v(myints, myints + 9);

	//// using default comparison:
	//std::sort(v.begin(), v.end());
	//for (auto it : v) std::cout << it << std::endl;

	//std::cout << "looking for a 3 ...";
	//if (std::binary_search(v.begin(), v.end(), 3))
	//	std::cout << "found!\n";
	//else
	//	std::cout << "not found!\n";

	//// using myfunction as comp:
	//std::sort(v.begin(), v.end(), myfunction);
	//for (auto it : v) std::cout << it << std::endl;

	//std::cout << "looking for a 6 ...";
	//if (std::binary_search(v.begin(), v.end(), 3, myfunction))
	//	std::cout << "found!\n";
	//else
	//	std::cout << "not found!\n";

	//vector<int> v(5);
	//bool found;

	//for (int i = 0; i < 5; ++i)
	//	v[i] = i;

	//found = binary_search(v.begin(), v.end(), 3);
	//cout << found << " ";

	//// Try searching for a value that's not present;
	//found = binary_search(v.begin(), v.end(), 9);
	//cout << found << endl;

	//int a[10] = { 10, 2, 17, 5, 16, 8, 13, 11, 20, 7 };
	//std::vector<int> v(a, a + 10);
	//std::ostream_iterator<int> output(cout, " ");

	//cout << "Vector v contains: ";
	//std::copy(v.begin(), v.end(), output); // display output vector

	//cout <<"1: " << *std::lower_bound(v.begin(), v.end(), 13) << endl;
	//// locate first occurrence of 16 in v
	//// std::vector<int>::iterator location;
	//// use binary_search to locate 13 in v
	//std::sort(v.begin(), v.end());
	//cout << "2: " << *std::lower_bound(v.begin(), v.end(), 13) << endl;
	//if (std::binary_search(v.begin(), v.end(), v[2]))
	//	cout << "\n\n13 was found in v";
	//else
	//	cout << "\n\n13 was not found in v";

	//cout << endl;
	



	return 0;
}
*/