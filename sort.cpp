#include<bits/stdc++.h>
#define int long long int

using namespace std;

// O(n^2)
void selectionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min_idx = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		swap(a[i], a[min_idx]);
	}
}

// Best complexity - O(n)
// Worst Complexity - O(n^2)
void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int cur_value = a[i];

		// j will stop when no shift is required
		while (j >= 0 && a[j] > cur_value) {
			a[j + 1] = a[j];
			j--;
		}
		// j+1 insert the cur_value
		a[j + 1] = cur_value;
	}
}

void printArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	} cout << '\n';
}

// Best complexity - O(n)
// Worst Complexity - O(n^2)
void BubbleSort(int a[], int n) {
	int swapCount = 1;
	while (swapCount) {
		swapCount = 0;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapCount++;
			}
		}
		// printArr(a, n);
	}
}

// O(max(nums)+n)
// wont work for negative values
void countSort(int a[], int n) {
	int mx = *max_element(a, a + n);

	int cnt[mx + 1];
	memset(cnt, 0, sizeof(cnt));

	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}

	int k = 0;
	for (int i = 0; i <= mx; i++) {
		while (cnt[i]--) {
			a[k] = i;
			k++;
		}
	}
}

// O(d)
int finMaxPlace(int mx) {
	int res = 0;
	while (mx) {
		res++;
		mx /= 10;
	}
	return res;
}

// O(n)
void radixCountSort(int a[], int n, int place) {
	vector<int> bucket[10];
	// O(n)
	for (int i = 0; i < n; i++) {
		int placeValue = (int)(a[i] / pow(10, place)) % 10;
		bucket[placeValue].push_back(a[i]);
	}

	// O(10)
	int k = 0;
	for (int i = 0; i < 10; i++) {
		for (auto x : bucket[i]) {
			a[k] = x;
			k++;
		}
	}

}

// max digits - d
// d * O(n)
void radixSort(int a[], int n) {
	// O(n)
	int mx_place = finMaxPlace(*max_element(a, a + n));

	// d * O(n)
	for (int place = 0; place < mx_place; place++) {
		// O(n)
		radixCountSort(a, n, place);
		// printArr(a, n);
	}
}

// O(right-left+1)
void mergeSortedArray(int a[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = 0;

	int sorted_arr[right - left + 1];
	while (i <= mid && j <= right) {
		if (a[i] <= a[j]) {
			sorted_arr[k++] = a[i++];
		}
		else {
			sorted_arr[k++] = a[j++];
		}
	}
	// copy the left remaining array
	while (i <= mid) sorted_arr[k++] = a[i++];
	// copy the right remaining array
	while (j <= right) sorted_arr[k++] = a[j++];

	k = 0;
	while (left <= right) {
		a[left++] = sorted_arr[k++];
	}
}

// O(nlogn)
void mergeSort(int a[], int left, int right) {
	// base case
	if (left == right) return;

	int mid = (left + right) / 2;
	// sort the left subarray
	mergeSort(a, left, mid);
	// sort the right subarray
	mergeSort(a, mid + 1, right);

	// merge the sorted left and right subarray
	// O(n)
	mergeSortedArray(a, left, mid, right);
}

int partition(int a[], int left, int right) {
	int pivot = a[right], i = left;

	for (int j = left; j < right; j++) {
		if (a[j] < pivot) {
			swap(a[j], a[i]);
			i++;
		}
	}

	// right contains the pivot element
	swap(a[right], a[i]);

	// cout << pivot << '\n';

	return i;
}

void quickSort(int a[], int left, int right) {
	if (left >= right) return;

	int pivot = partition(a, left, right);

	// sort the left array to the pivot
	quickSort(a, left, pivot - 1);

	// sort the right array to the pivot
	quickSort(a, pivot + 1, right);
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// selectionSort(a, n);

	// insertionSort(a, n);

	// BubbleSort(a, n);

	// countSort(a, n);

	// radixSort(a, n);

	// mergeSort(a, 0, n - 1);

	quickSort(a, 0, n - 1);

	printArr(a, n);

	return 0;
}