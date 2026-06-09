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
    int cnt = 0;
    int l = 0;
    int r = len - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == value) {
            if (arr[l] == arr[r]) {
                int k = r - l + 1;
                cnt += k * (k - 1) / 2;
                break;
            } else {
                int l_cnt = 1;
                while (l + 1 < r && arr[l] == arr[l + 1]) {
                    l_cnt++;
                    l++;
                }
                int r_cnt = 1;
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
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        int first_pos = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                first_pos = mid;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (first_pos != -1) {
            left = first_pos;
            right = len - 1;
            int last_pos = first_pos;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) {
                    last_pos = mid;
                    left = mid + 1;
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (arr[i] == target) {
                int k = last_pos - first_pos + 1;
                cnt += k * (k - 1) / 2;
                i = last_pos;
            } else {
                cnt += (last_pos - first_pos + 1);
            }
        }
    }
    return cnt;
}
