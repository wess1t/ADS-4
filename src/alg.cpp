// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++cnt;
            }
        }
    }
    return cnt;
}

int countPairs2(int *arr, int len, int value) {
    int cnt = 0;
    int l = 0;
    int r = len - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == value) {
            int l_val = arr[l];
            int r_val = arr[r];
            if (l_val == r_val) {
                int n = r - l + 1;
                cnt += n * (n - 1) / 2;
                break;
            }
            int l_cnt = 0;
            while (l < r && arr[l] == l_val) {
                l_cnt++;
                l++;
            }
            int r_cnt = 0;
            while (l <= r && arr[r] == r_val) {
                r_cnt++;
                r--;
            }
            cnt += l_cnt * r_cnt;
        } else if (sum < value) {
            l++;
        } else {
            r--;
        }
    }
    return cnt;
}

int countPairs3(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int target = value - arr[i];
        if (target < arr[i]) continue;
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                cnt++;
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return cnt;
}
