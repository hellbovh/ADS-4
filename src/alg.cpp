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
  for (int i = 0; i < len; i++)
    for (int j = len - 1; j > i; j--)
      if (arr[i] + arr[j] == value)
        counter++;
  return counter;
}
int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i;
    int right = len - 1;
    while (left < right - 1) {
      int middle = (left + right) / 2;
      if (arr[middle] + arr[i] < value) {
        left = middle;
      } else if (arr[middle] + arr[i] > value) {
        right = middle;
      } else {
        counter++;
        int m_temp = middle - 1;
        while (m_temp > left && arr[m_temp] + arr[i] == value) {
          counter++;
          m_temp--;
        }
        m_temp = middle + 1;
        while (m_temp < right && arr[m_temp] + arr[i] == value) {
          counter++;
          m_temp++;
        }
        break;
      }
    }
  }
  return counter;
}
