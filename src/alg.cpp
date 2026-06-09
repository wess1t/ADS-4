// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value)
                ++cnt;
        }
    }
    return cnt;
}

int countPairs2(int *arr, int len, int value) {
    int cnt = 0, l = 0, r = len - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == value) {
            if (arr[l] == arr[r]) {
                int n = r - l + 1;
                cnt += n * (n - 1) / 2;
                break;
            } else {
                int l_cnt = 1, r_cnt = 1;
                while (l + 1 < r && arr[l] == arr[l + 1]) {
                    l_cnt++;
                    l++;
                }
                while (r - 1 > l && arr[r] == arr[r - 1]) {
                    r_cnt++;
                    r--;
                }
                cnt += l_cnt * r_cnt;
                l++;
                r--;
            }
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
        int l = i + 1, r = len - 1;
        int first = -1, last = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                first = mid;
                r = mid - 1;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (first != -1) {
            l = first;
            r = len - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (arr[mid] == target) {
                    last = mid;
                    l = mid + 1;
                } else if (arr[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            cnt += (last - first + 1);
        }
        while (i + 1 < len && arr[i] == arr[i + 1])
            i++;
    }
    return cnt;
}
