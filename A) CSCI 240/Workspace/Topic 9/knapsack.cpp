#include <iostream>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int capacity, int weight[], int val[], int n) {
    // base case, if capacity or N = 0
    if(capacity == 0 || n == 0) return 0;

    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution
    if(weight[n - 1] > capacity) return knapSack(capacity, weight, val, (n - 1));

    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else return max(val[n - 1] + knapSack(capacity - weight[n - 1], weight, val, (n - 1)),
                    knapSack(capacity, weight, val, (n - 1)));
}

int main(int argc, char const *argv[]){
	int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int capacity = 50;
    int n = sizeof(val) / sizeof(val[0]);
    std::cout << knapSack(capacity, wt, val, n);
	
	return 0;
}
