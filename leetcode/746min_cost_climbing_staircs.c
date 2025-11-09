int getSmaller(int a, int b) { return (a < b) ? a : b; }

int minCostClimbingStairs(int* cost, int costSize) {
   int costFar = cost[costSize - 1], costNear = cost[costSize - 2];

   for (int i = costSize - 3; i >= 0; i--) {
      int currCost = getSmaller(costFar, costNear);
      costFar = costNear;
      costNear = cost[i] + currCost;
   }

   return getSmaller(costFar, costNear);
}