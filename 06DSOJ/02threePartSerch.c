// #include <stdio.h>

// int ternarySearch(int l, int r, int key, int ar[]) {
//   if (r >= l) {
//     int mid1 = l + (r - l) / 3;
//     int mid2 = r - (r - l) / 3;

//     if (ar[mid1] == key) {
//       return mid1;
//     }
//     if (ar[mid2] == key) {
//       return mid2;
//     }

//     if (key < ar[mid1]) {
//       return ternarySearch(l, mid1 - 1, key, ar);
//     } else if (key > ar[mid2]) {
//       return ternarySearch(mid2 + 1, r, key, ar);
//     } else {
//       return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
//     }
//   }

//   return -1;
// }

// int main() {
//   int arr[1024];
//   int r, p, key;
//   scanf("%d", &r);
//   for (int i = 0; i < r; ++i) {
//       scanf(" %d", &arr[i]);
//   }
//   scanf("%d", &key);

//   printf("%d\n",ternarySearch(0, r, key, arr));
// }
#include <stdio.h>

int ternarySearch(int l, int r, int key, int ar[]) {
  if (r >= l) {
    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;

    if (ar[mid1] == key) {
      return mid1;
    }
    if (ar[mid2] == key) {
      return mid2;
    }

    if (key < ar[mid1]) {
      return ternarySearch(l, mid1 - 1, key, ar);
    } else if (key > ar[mid2]) {
      return ternarySearch(mid2 + 1, r, key, ar);
    } else {
      return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
    }
  }

  return -1;
}

int main() {
  int arr[1024];
  int r, p, key;
  scanf("%d", &r);
  for (int i = 0; i < r; ++i) {
      scanf(" %d", &arr[i]);
  }
  scanf("%d", &key);

  printf("%d\n",ternarySearch(0, r - 1, key, arr));
}
