// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int res = 0;
  for (int i = 0; i < (len - 1); i++) {
    for (int j = 1 + i; j < len; j++) {
      if ((arr[i] + arr[j]) == value) {
        res++;
      }
    }
  }
  return res;
}
int countPairs2(int *arr, int len, int value) {
  int left = len;
  int test = 0;
  while (arr[left - 1] > value) {
    left--;
  }
  int res = 0;
  for (int right = 0; right < left - 1; right++) {
    for (int j = right + 1; j < left; j++) {
      if ((arr[right] + arr[j]) == value) {
        res++;
      }
    }
    if (arr[right] != arr[right + 1]) {
      left--;
    }
  }
  return res;
}
int cbinsearch(int* arr, int size, int value) {
  int res = 0;
  int left = -1, right = size;
  while (left < right - 1) {
    int ind = (left + right) / 2;
    if (arr[ind] < value) {
      left = ind;
    } else {
      right = ind;
    }
  }
  int rightInd = right;
  int leftInd = right - 1;
  while (rightInd < size && arr[rightInd] == value) {
    rightInd++;
    res++;
  }
  while (leftInd > 0 && arr[leftInd] == value) {
    leftInd--;
    res++;
  }
  return res;
}

int countPairs3(int *arr, int len, int value) {
  int res = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] >= value / 2) {
      int mid1 = cbinsearch(arr, len, value - arr[i]);
      int mid2 = cbinsearch(arr, len, arr[i]);
      for (int j = mid1 - 1; j > 0; j--) {
        if (value % 2 != 0) {
          res += mid1 * mid2;
          break;
        }
        res += j;
      }
      break;
    }
    int num = cbinsearch(arr, len, value - arr[i]);
    res += num;
  }
  return res;
}
