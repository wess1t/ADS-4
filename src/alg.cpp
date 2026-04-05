// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (i > 0 && arr[i] == arr[i - 1])
      continue;
    for (int j = i + 1; j < len; ++j) {
      if (j > i + 1 && arr[j] == arr[j -1])
        continue;
      if (arr[i] + arr[j] == value)
        ++cnt;
    }
  }
  return cnt;
}
int countPairs2(int *arr, int len, int value) {
  int cnt = 0, left = 0, right = len - 1;
  while (left < right) {
    int currentsum = arr[left] + arr[right];
    if (currentsum == value) {
      int left_cnt = 1, right_cnt = 1;
      while (left + left_cnt < right && arr[left + left_cnt] == arr[left])
        left_cnt++;
      while (right - right_cnt > left && arr[right - right_cnt] == arr[right])
        right_cnt++;
      if (arr[left] == arr[right]) {
        int total = left_cnt + right_cnt;
        cnt += total * (total - 1) / 2;
      } else {
        cnt += left_cnt * right_cnt;
      }
      left += left_cnt;
      right -= right_cnt;
    } else if (currentsum < value) {
      ++left;
    } else {
      --right;
    }
  return cnt;
}
int countPairs3(int *arr, int len, int value) {
  int cnt = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (i > 0 && arr[i] == arr[i - 1])
      continue;
    int k = value - arr[i];
    if (k < arr[i])
      continue;
    int a = i + 1, b = len - 1;
    bool found = false;
    while (a <= b) {
      int s = a + (b - a) / 2;
      if (arr[s] == k) {
        found = true;
        break;
      } else if (arr[s] < k) {
        a = s + 1;
      } else {
        b = s - 1;
      }
    }
    if (found)
      ++cnt;
  }
  return cnt;
}
