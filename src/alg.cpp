// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < len; ++j) {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;
            if (arr[i] + arr[j] == value)
                ++cnt;
        }
    }
    return cnt;
}

int countPairs2(int *arr, int len, int value) {
    int cnt = 0, l = 0, r = len - 1;
    while (l < r) {
        int currentsum = arr[l] + arr[r];
        if (currentsum == value) {
            int l_cnt = 1, r_cnt = 1;
            while (l + l_cnt < r && arr[l + l_cnt] == arr[l])
                l_cnt++;
            while (r - r_cnt > l && arr[r - r_cnt] == arr[r])
                r_cnt++;
            
            if (arr[l] == arr[r]) {
                int total = l_cnt + r_cnt - 1;
                cnt += total * (total - 1) / 2;
            } else {
                cnt += l_cnt * r_cnt;
            }
            
            l += l_cnt;
            r -= r_cnt;
        } else if (currentsum < value) {
            ++l;
        } else {
            --r;
        }
    }
    return cnt;
}

int countPairs3(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        
        int target = value - arr[i];
        if (target < arr[i])
            continue;
            
        int l = i + 1, r = len - 1;
        int first_pos = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                first_pos = mid;
                r = mid - 1;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        if (first_pos != -1) {
            l = first_pos;
            r = len - 1;
            int last_pos = first_pos;
            
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (arr[mid] == target) {
                    last_pos = mid;
                    l = mid + 1;
                } else if (arr[mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            if (arr[i] == target) {
                int count = last_pos - first_pos + 1;
                cnt += count * (count - 1) / 2;
            } else {
                cnt += (last_pos - first_pos + 1);
            }
        }
    }
    return cnt;
}
