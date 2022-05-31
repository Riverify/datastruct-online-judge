#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int coinChange(std::vector<int>& coins, int amount) {
  int n = coins.size();
  if (n == 0 || amount == 0)  //边界情况
    return 0;

  std::vector<int> dp(amount + 1);  // dp[0]必须初始化为0

  for (int i = 1; i <= amount; i++) {
    int cost = INT_MAX;
    for (int j = 0; j < n; j++) {
      if (i >= coins[j]) {
        if (dp[i - coins[j]] != INT_MAX)
          cost = std::min(cost, dp[i - coins[j]] + 1);
      }
    }
    dp[i] = cost;
  }
  if (dp[amount] == INT_MAX)
    return -1;
  else
    return dp[amount];
}

int main() {
  int len, money;
  std::vector<int> coin;

  std::cin >> len >> money;

  coin.resize(len);
  for (int i = 0; i < len; i++) {
    std::cin >> coin[i];
  }

  std::cout << coinChange(coin, money) << "\n";
  return 0;
}

















// #include <bits/types/FILE.h>
// #include <iostream>
// #include <algorithm> 
// #include <vector> 

// using namespace std;


// int * slice2(int *arr,const int n){
//     int* a = new int[n];
//     for(int i = 0;i < n;i++){
//         a[i] = arr[i];
//     }
//     return a;
// }


// int func1(int* values, int sum, int num)
// {
//     int total = 0;
//     int count = 0;
//     int discount = 1;
//     while (true)
//     {
//         for (int i = num - discount; i >= 0; i--)
//         {
//             total += values[i];
//             count++;
//             if (total == sum) 
//             {
//                 // cout << count << "\n";
//                 return count;
//             } else if (total > sum) {
//                 if (i == 0) {
//                     total -= values[i];
//                     total -= values[num - discount];
//                     count -= 2;
//                     if (discount == num) {
//                         return -1;
//                     }
//                     discount++;
//                     break;
//                     }
//                     count--;
//                     total -= values[i];
//                 } else {
//                     break;
//                 }
//             }
//     }   
// }

// int main(){
	
//     int num, sum;
//     cin >> num >> sum;
//     int values[num];
//     for (int i = 0; i < num; i++) 
//     {
//         cin >> values[i];
//     }
//     sort(values, values + num);
//     int array[num];
//     for (int i = 0; i < num; i++) {
//         array[i] = func1(values, sum, num - 1);
//         // array[i] = func1(values, sum, num);
//     }
//     sort(array, array + num);
//     cout << array[0] << "\n";
// } 