/*
Find the kth largest element in an unsorted array. Note that it is the kth largest
element in the sorted order, not the kth distinct element.
For example.
Given [3,2,1,5,6,4] and k = 2 , return 5;

Note:
  You may assume k is always valid, 1 <= k <= array's length.
*/

//----------------------first solution
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[k-1];
  }
};


//--------------------------second Solution
//--------------------------quick sort;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    int left = 0, right = nums.size()-1;
    while (true) {
      int pos = partition(nums, left, right);
      if (pos == k - 1) return nums[pos];
      if (pos > k - 1) right = pos - 1;
      else left = pos + 1;
    }
  }

  int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int l = left + 1, r = right;
    while (l <= r) {
      if (nums[l] < pivot && nums[r] > pivot)
        swap(nums[l], nums[r]);
      if (nums[l] >= pivot) l++;
      if (nums[r] <= pivot) r--;
    }
    swap(nums[left], nums[r]);
    return r;
  }
};

//-------------------------------third Solution
//-------------------------------heap sort
class Solution {
public:
    inline int left(int idx) {
        return (idx << 1) + 1;
    }
    inline int right(int idx) {
        return (idx << 1) + 2;
    }
    void max_heapify(vector<int>& nums, int idx) {
        int largest = idx;
        int l = left(idx), r = right(idx);
        if (l < heap_size && nums[l] > nums[largest]) largest = l;
        if (r < heap_size && nums[r] > nums[largest]) largest = r;
        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            max_heapify(nums, largest);
        }
    }
    void build_max_heap(vector<int>& nums) {
        heap_size = nums.size();
        for (int i = (heap_size >> 1) - 1; i >= 0; i--)
            max_heapify(nums, i);
    }
    int findKthLargest(vector<int>& nums, int k) {
        build_max_heap(nums);
        for (int i = 0; i < k; i++) {
            swap(nums[0], nums[heap_size - 1]);
            heap_size--;
            max_heapify(nums, 0);
        }
        return nums[heap_size];
    }
private:
    int heap_size;
};

//---------------------------------fouth Solution

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i:k-1)
      pq.pop();
    return pq.top();
  }
};

//---------------------------------fifth Solution

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    multiset<int> mset;
    int nums.size();
    for (int i = 0; i < n; i++) {
      mset.insert(nums[i]);
      if (mset.size() > k)
        mset.erase(mset.begin());
    }
    return *mset.begin();
  }
};
