// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        counter++;
    }
  }
  return counter;
}
int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  int left = 0;
  int right = len - 1;
  while (left != right) {
    if (arr[left] + arr[right] < value)
      left++;
    else if (arr[left] + arr[right] > value)
      right--;
    else
      counter++;
  }
  return counter;
}
int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i;
    int right = len - 1;
    while (left < right) {
      int middle = (left + right) / 2;
      if (arr[middle] + arr[i] < value) {
        left = middle;
      } else if (arr[middle] + arr[i] > value) {
        right = middle;
      } else {
        counter++;
        int temp = middle - 1;
        while (temp > left && arr[temp] + arr[i] == value) {
          counter++;
          temp--;
        }
        temp = middle + 1;
        while (temp < right && arr[temp] + arr[i] == value) {
          counter++;
          temp++;
        }
      }
    }
  }
  return counter;
}
