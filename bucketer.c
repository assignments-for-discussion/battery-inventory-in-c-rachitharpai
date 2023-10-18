#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  int ratedCapacity = 120;

  for (int i = 0; i < nBatteries; i++) {
    int soh = (100 * presentCapacities[i]) / ratedCapacity;

    if (soh > 80) 
      counts.healthy++;
      
    else if (soh >= 63 && soh <= 80)
      counts.exchange++;
      
    else
      counts.failed++;
  }
  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  printf("Healthy: %d\nExchange: %d\nFailed: %d\n", counts.healthy, counts.exchange, counts.failed);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByHealth();
  return 0;
}
