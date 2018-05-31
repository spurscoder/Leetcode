#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

// 常用排序算法
class SortProblem {
public:
	// 快速排序
	void quickSort(vector<int>& nums, int l, int r) {
		if (l >= r) return;
		int i = l, j = r, temp = nums[l];
		while (i < j) {
			while (i < j && nums[j] >= temp) --j;
			swap(nums[i], nums[j]);
			while (i < j && nums[i] <= temp) ++i;
			swap(nums[i], nums[j]);
		}
		nums[i] = temp;
		quickSort(nums, l, i-1);
		quickSort(nums, i+1, r);
	}

	// 冒泡排序
	void bubbleSort(vector<int>& nums, int l, int r) { // l,r 分别对应于数组的首尾元素
		if (l >= r) return;
		bool flag = true;
		for (int i = r; i > l; --i) {
			if (!flag) return;   // 标志位，用于提前结束循环。
			flag = false;
			for (int j = l; j < i; ++j) {
				if (nums[j] > nums[j + 1]) swap(nums[j], nums[j + 1]), flag = true;
			}
		}
	}

	// 插入排序
	void insertSort(vector<int>& nums, int l, int r) { // l,r 分别对应于数组的首尾元素
		if (l >= r) return;
		for (int i = l + 1; i <= r; ++i) {
			int temp = nums[i], j = i - 1;
			for (; j >= l; --j) {
				if (nums[j] <= temp)
					break;
				nums[j + 1] = nums[j];
			}
			nums[j+1] = temp;
		}
	}

	// 堆排序
	void heapSort(vector<int>& nums) {
		int size = nums.size();
		BuildHeap(nums, size);
		for (int i = size-1; i >= 0; --i) {
			swap(nums[i], nums[0]);
			HeapAdjust(nums, 0, i - 1);
		}
	}

	// 归并排序
	void mergeSort(vector<int>& nums, int l, int r) {
		if (l >= r) return;
		int mid = (l + r) / 2;
		mergeSort(nums, l, mid);
		mergeSort(nums, mid + 1, r);
		merge(nums, l, mid, r);
	}

	// 选择排序
	void selectSort(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i) {
			int min = nums[i], min_index = i;
			for (int j = i; j < nums.size(); ++j)
				if (min > nums[j]) min = nums[j], min_index = j;
			if (min_index != i)
				swap(nums[i], nums[min_index]);
		}
	}

	// 基数排序			*** 目前本程序只适用于正数排序	*** 针对复数的情况：可以将复数和正数分开分别排序，其中复数去掉负号后可以使用基数排序排序
	void radixSort(vector<int>& nums) {
		vector<vector<int>> temp(10, vector<int>(nums.size() + 1, 0));
		for (int x = 1; x <= 4; ++x) {
			// 把数组nums的第x位元素装到对应桶中
			for (int i = 0; i < nums.size(); ++i) {
				temp[getNum(nums[i], x)][0]++;
				temp[getNum(nums[i], x)][temp[getNum(nums[i], x)][0]] = nums[i];
			}
			// 把桶里元素倒出来
			for (int i = 0, j = 0; j < 10; ++j) {
				for (int k = 1; temp[j][0] > 0 && k <= temp[j][0]; ++k)
					nums[i++] = temp[j][k];
				temp[j][0] = 0;
			}
		}
	}

	// 希尔排序
	void shellSort(vector<int>& nums) {
		int dk = nums.size() / 2;
		while (dk >= 1) {
			ShellInsertSort(nums, dk);
			dk /= 2;
		}
	}
private:
	// For 堆排序
	void BuildHeap(vector<int>& nums, int size) {
		for (int i = size / 2 - 1; i >= 0; --i)
			HeapAdjust(nums, i, size);
	}
	void HeapAdjust(vector<int>& nums, int i, int size) {
		int lchild = 2 * i + 1;
		int rchild = 2 * i + 2;
		int max = i;
		if (i <= size/2 - 1) {
			if (lchild <= size && nums[lchild] > nums[max])
				max = lchild;
			if (rchild <= size && nums[rchild] > nums[max])
				max = rchild;
			if (i != max) {
				swap(nums[i], nums[max]);
				HeapAdjust(nums, max, size);
			}
		}
	}

	// For 归并排序
	void merge(vector<int>& nums, int l, int m, int r) {
		vector<int> temp(r - l + 1, 0);
		int f_l = l, f_r = r;
		int i = 0, j = m + 1;
		while (l <= m && j <= r) {
			if (nums[l] < nums[j]) temp[i++] = nums[l++];
			else temp[i++] = nums[j++];
		}
		while (l <= m)
			temp[i++] = nums[l++];
		while (j <= r)
			temp[i++] = nums[j++];

		for (int i = f_l; i <= f_r; ++i)
			nums[i] = temp[i - f_l];
	}

	// For 基数排序
	int getNum(int x, int d) {
		int a[] = { 1,1,10,100,1000 };
		return (x / a[d]) % 10;
	}
	// For 希尔排序
	void ShellInsertSort(vector<int>& nums, int dk) {
		for (int i = dk; i < nums.size(); ++i) {
			if (nums[i] < nums[i - dk]) {
				int j = i - dk;
				int x = nums[i];
				nums[i] = nums[i - dk];
				while (j >= 0 && x < nums[j]) {
					nums[j + dk] = nums[j];
					j -= dk;
				}
				nums[j + dk] = x;
			}
		}
	}

};

// 五大算法
class FiveBasicProblem {
public:
	/* 分治法问题
	*  1. 递归与hanoi塔
	*  2. 二分法求方程近似解
	*  3. 用c++实现归并排序
	*  4. 求最大值和最小值的分治算法
	*/

	// 1. 递归与hanoi塔问题
	void hanoiMove(char a, char b, char c, int n) {
		if (n == 0) return;
		hanoiMove(a, c, b, n - 1);
		cout << "Move disk " << n << " from " << a << " to " << c << endl;
		hanoiMove(b, a, c, n - 1);
	}

	// 2. 二分法求方程近似解


	// 3. 用C++实现归并排序


	// 4. 求最大值和最小值的分治算法

	
	// 杨辉三角形


	// Fibonacci 数列
	int fibonacci(int n) {
		vector<int> fibo(n + 1, 0);
		fibo[0] = 0, fibo[1] = 1;
		for (int i = 2; i <= n; ++i)
			fibo[i] = fibo[i - 1] + fibo[i - 2];
		return fibo[n];
	}
private:

};
int main() {
// FiveBasicProblem
	FiveBasicProblem A = FiveBasicProblem();
	// A.hanoiMove('a', 'b', 'c', 1);
	cout << A.fibonacci(2) << endl;
	cout << A.fibonacci(3) << endl;


// SortProblem test
	//SortProblem Sol = SortProblem();

	//vector<int> nums{ 5,3,4,2,1,4,5,6,67,8,9 };
	//Sol.radixSort(nums);
	//for (auto num : nums)
	//	cout << num << " ";
	//cout << endl;

	return 0;
}