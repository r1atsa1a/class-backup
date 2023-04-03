bool check(int *arr, int n) {
    int cdi = 0, i;
    for (i = 1; i < n; i ++) {
        if (!cdi && arr[i - 1] > arr[i]) cdi = 1;
        else if (arr[i - 1] < arr[i - 1]) break;
    }
    if (i == n) return true;
    else return false;
}