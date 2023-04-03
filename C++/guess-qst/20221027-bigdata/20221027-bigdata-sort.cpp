#include <iostream>
#include <vector>
#include <algorithm>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector<pair<int, int>> v, t;
void BubbleSort() {
	for (int i = 0; i < v.size() - 1; i ++)
		for (int j = 0; j < v.size() - i - 1; j ++)
			if (v[j].first > v[j + 1].first)
				swap(v[j], v[j + 1]);
}
void QuickSort(int l, int r) {
	if (l >= r) return;
	int x = v[l + r >> 1].first, i = l - 1, j = r + 1;
	while (i < j) {
		do i ++;
		while (v[i].first < x);
		do j --;
		while (v[j].first > x);
		if (i < j) swap(v[i], v[j]);
	}
	QuickSort(l, j);
	QuickSort(j + 1, r);
}
void MergeSort(int l, int r) {
	if (l >= r) return;
	int mid = l + r >> 1;
	MergeSort(l, mid);
	MergeSort(mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (v[i].first <= v[j].first) t[k ++] = v[i ++];
		else t[k ++] = v[j ++];
	}
	while (i <= mid) t[k ++] = v[i ++];
	while (j <= r) t[k ++] = v[j ++];
	for (i = l, j = 0; i <= r; i ++, j ++) v[i] = t[j];
}
int main() {
	IOS
	FILE *fp, *out;
	fp = fopen("bigdata-80w.txt", "r");
	while (!feof(fp)) {
		int idx, x;
		fscanf(fp, "%d %d", &idx, &x);
		v.push_back({x, idx});
	}
	sort(v.begin(), v.end());
//	QuickSort(0, v.size() - 1);
//	MergeSort(0, v.size() - 1);
//	BubbleSort();
	out = fopen("sortdata.txt", "w");
	for (auto xi : v)
		fprintf(out, "%d %d\n", xi.second, xi.first);
	fclose(fp);
	fclose(out);
	return 0;
}
