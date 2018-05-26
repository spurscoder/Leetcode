#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {
    vector<int> test{1,1,1,2,2,2,3,3,3,6,8};

    cout << lower_bound(test.begin(), test.end(), 2) - test.begin() <<endl;
    cout << *upper_bound(test.begin(), test.end(), 2) << endl;

    cout << *lower_bound(test.begin(), test.end(), 3) << endl;
    cout << *upper_bound(test.begin(), test.end(), 3) << endl;

    cout << *lower_bound(test.begin(), test.end(), 5) << endl;
    cout << *upper_bound(test.begin(), test.end(), 5) << endl;

    assert(lower_bound(test.begin(), test.end(), 9) == test.end());
    assert(upper_bound(test.begin(), test.end(), 9) == test.end());

    cout << *lower_bound(test.begin(), test.end(), 0) << endl;
    cout << *upper_bound(test.begin(), test.end(), 0) << endl;

    return 1;
}
