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
            if (arr[l] == arr[r]) {
                int n = r - l + 1;
                cnt += n * (n - 1) / 2;
                break;
            }
            int l_cnt = 1;
            while (l + l_cnt < r && arr[l + l_cnt] == arr[l]) {
                l_cnt++;
            }
            int r_cnt = 1;
            while (r - r_cnt > l && arr[r - r_cnt] == arr[r]) {
                r_cnt++;
            }
            cnt += l_cnt * r_cnt;
            l += l_cnt;
            r -= r_cnt;
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
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                int r_cnt = 1;
                int temp = mid + 1;
                while (temp <= right && arr[temp] == target) {
                    r_cnt++;
                    temp++;
                }
                temp = mid - 1;
                while (temp >= left && arr[temp] == target) {
                    r_cnt++;
                    temp--;
                }
                cnt += r_cnt;
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
