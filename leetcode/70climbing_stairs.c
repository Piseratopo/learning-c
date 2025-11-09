int climbStairs(int n) {
   int numberOfWays[50] = {1, 1, 2};
   for (int i = 3; i <= n; i++) {
      numberOfWays[i] = numberOfWays[i - 1] + numberOfWays[i - 2];
   }
   return numberOfWays[n];
}