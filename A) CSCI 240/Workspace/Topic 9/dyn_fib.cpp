#include <iostream>

uint64_t fib(int n);
uint64_t fib_dyn(int n, uint64_t[]);
uint64_t fib_dyn2(int n, uint64_t[]);

int main(int argc, char const *argv[]){
    const int n{50};
	uint64_t memo[n + 1];

    fib_dyn(n, memo);
	
	return 0;
}

uint64_t fib(int n) {
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

uint64_t fib(int n, uint64_t memo[]) {
    if(n <= 1) return n;
    if(memo[n] == 0) memo[n] = fib_dyn(n - 1, memo) + fib_dyn(n - 1, memo);
    return fib(n - 1) + fib(n - 2);
}

uint64_t fib_dyn2(int n, uint64_t memo[]) {
    static int i{2};

    if(i > n) return memo[n - 1];
    memo[i] = memo[i - 1] + memo[i - 2];
    ++i;
    
    return fib_dyn2(n - 1, memo);
}
