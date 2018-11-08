/*
Description: Given a collection of numbers that might contain duplicates, return
all possible unique permutations.

For examples. [1,1,2] have the following unique permutations:
[
[1,1,2],
[1,2,1],
[2,1,1,]
]
*/

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    if (nums.empty()) return {{}};
    set<vector<int>> result;
    int size = nums.size();
    sort(nums.begin(), nums.end());
    result.insert(nums);
    int k = 0;
    while (1) {
      k = -1;
      for (int i = size - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
          k = i;
          break;
        }
      }
      if (k == -1) return vector<vector<int>>(result.begin(), result.end());
      int l = 0;
      for (int i = size - 1; i >= 0; --i) {
        if (nums[i] > nums[k]) {
          l = i;
          break;
        }
      }
      swap(nums[l], nums[k]);
      reverse(nums.begin()+k+1, nums.end());
      result.insert(nums);
    }
  }
};


// recursive
/*
every elements stand at the first position
go down
*/

class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};

// non-recursive

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &S) {
		// res.clear();
		sort(S.begin(), S.end());
		res.push_back(S);
		int j;
		int i = S.size()-1;
		while (1){
			for (i=S.size()-1; i>0; i--){
				if (S[i-1]< S[i]){
					break;
				}
			}
			if(i == 0){
				break;
			}

			for (j=S.size()-1; j>i-1; j--){
				if (S[j]>S[i-1]){
					break;
				}
			}
			swap(S[i-1], S[j]);
			reverse(S, i, S.size()-1);
			res.push_back(S);
		}
		return res;
    }
	void reverse(vector<int> &S, int s, int e){
		while (s<e){
			swap(S[s++], S[e--]);
		}
	}

	vector<vector<int> > res;
};
