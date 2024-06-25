#include <stdio.h>
#include <stdbool.h>

int max(int x, int y){
  if (x > y)
    return x;
  else
    return y;
}

/*Our first solution is a brute force recursive solution solved from top down*/
int bruteForce(int n){
  // base case
  if (n < 2)
    return n;

  return bruteForce(n-1) + bruteForce(n-2);
}

/*Our second solution features a bottom up aprach where we
start at 0 and buid up to n, elimating costly recursion*/
int bottomUp(int n){
  // count for base case where n is part of initaly known numbers and
  // use n+1 becaue we need the sum of the nth term
  int size = max(2, n+1);
  int array[size];

  array[0] = 0;
  array[1] = 1;

  for(int i = 2; i <= n ; i++)
    array[i] = array[i-1] + array[i-2];

  return array[n];
}

/*The Third apprach is especialy clever, we optimize the
second approace to use less space*/
int clever(int n){
  int array[] = {0, 1};

  for(int i = 2; i <= n; i++)
    array[i%2] = array[0] + array[1];

  return array[n%2];
}

int main(){
    int n = 0, r;

    printf("How many steps in the Fibonacci sequence do you wish to take? ");

    // Loop until valid input is received (r == 1 and n >= 0)
    while ((r = scanf("%d", &n)) != 1 || n < 0) {
          // Check if scanf failed to read an integer or if n is negative
          if (r != 1) {
              // If scanf failed to read an integer, clear the input buffer
              int c;
              while ((c = getchar()) != '\n' && c != EOF);
          } else {
              // If n < 0, clear the input buffer
              getchar(); // Consume newline character left by scanf
          }

          // Prompt user again for valid input
          printf("Invalid selection, must enter a positive integer. Please try again: ");
      }


    printf("Fib(%d)  = %d by the brute force method.\n", n, bruteForce(n));
    printf("The recursive, top down, approach has an exponential runtime. It is accurate to write that it is O(2^n), but it is even more precise to say that it is O(φ^n) ≈ O(1.618^n). \n\tNote: φ, the Greek letter phi, represents the golden ratio.\n");
    printf("Fib(%d)  = %d by the bottom Up method.\n", n,  bottomUp(n));
    printf("With this method, we start at F0 and F1 then build to FN. The runtime and space complexity of this solution are both O(n). This \"bottom-up\" approach is an example of **dynamic programming**\n\t- One of the key factors of dynamic programming is observing repeated computation in a top-down recursive algorithm, then eliminateing that repeated computation by constructing a bottom-up algorithm that produces the same results.\n");
    printf("Fib(%d)  = %d by the clever method.\n", n, clever(n));
    printf("This approach still has O(n) runtime, but has O(1) space complexity. With each iteration through the for-loop, the (n %% 2) term toggles between 0 and 1, allowing it to overwrite whichever one of the two previous values is no longer needed in its ascent toward FN");

    return 0;
}
