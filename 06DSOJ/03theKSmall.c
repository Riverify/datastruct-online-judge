#include <stdio.h>

int quick_select(int arr[], int start, int end, int k) {
  int i = start;
  int j = end;
  int tmp;
  if (start < end) {
    tmp = arr[start];
    while (i != j) {
      while (j > i && arr[j] >= tmp) j--;
      arr[i] = arr[j];
      while (i < j && arr[i] <= tmp) i++;
      arr[j] = arr[i];
    }
    arr[i] = tmp;
    if (k - 1 == i) {
      return arr[i];
    } else if (k - 1 < i) {
      return quick_select(arr, start, i - 1, k);
    } else {
      return quick_select(arr, i + 1, end, k);
    }
  } else if (start == end && start == k - 1) {
    return arr[k - 1];
  }
}

int main() {
  int arr[1024];
  int len;
  int elem;
  scanf("%d", &len);
  for (int i = 0; i < len; ++i) {
    scanf(" %d", &arr[i]);
  }
  scanf("%d", &elem);
  printf("%d\n", quick_select(arr, 0, len - 1, elem));
}
