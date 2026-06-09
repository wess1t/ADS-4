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
        int l = i + 1;
        int r = len - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                int r_cnt = 1;
                int temp = mid;
                while (temp + 1 <= r && arr[temp + 1] == target) {
                    r_cnt++;
                    temp++;
                }
                temp = mid;
                while (temp - 1 >= l && arr[temp - 1] == target) {
                    r_cnt++;
                    temp--;
                }
                cnt += r_cnt;
                break;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return cnt;
}
