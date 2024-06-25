#include <iostream>
#include <limits>
#include <string>

// Utility function to check if a string is a positive integer
bool is_positive_integer(const std::string& str) {
    // Check if every character in the string is a digit
    for (char c : str) {
        if (!isdigit(c)) {
            return false; // Return false if any character is not a digit
        }
    }
    try {
        // Convert the string to an integer
        int n = std::stoi(str);
        if (n > 0) {
            return true; // Return true if the integer is positive
        }
    } catch (...) {
        return false; // Return false if conversion fails
    }
    return false; // Return false if the integer is not positive
}

/*Our first solution is a brute force recursive solution solved from top down*/
int bruteForce(int n){
  // Base cases: fib(0) = 0, fib(1) = 1
  if (n < 2) return n;

  return bruteForce(n-1) + bruteForce(n-2);
}

/*Our second solution features a bottom up aprach where we
start at 0 and buid up to n, elimating costly recursion*/
int bottomUp(int n){
  // count for base case where n is part of initaly known numbers and
  // use n+1 becaue we need the sum of the nth term
  int array[std::max(2, n+1)];

  array[0] = 0;
  array[1] = 1;

  for( int i = 2; i <= n ; i++)
    array[i] = array[i-1] + array[i-2];

  return array[n];
  }

int clever(int n){
  int array[] = {0, 1};

  for(int i = 2; i <= n; i++)
    array[i%2] = array[0] + array[1];

  return array[n%2];
}

int main() {
    std::string input;

    std::cout << "How many steps in the Fibonacci sequence do you wish to take? ";
    while (true) {
        std::cin >> input;

        // Check if the input string is a positive integer
        if (is_positive_integer(input)) {
            break; // Break the loop if input is valid
        } else {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid selection, must enter a positive integer. Please try again: ";
        }
    }

    // Convert the valid input string to an integer
    int n = std::stoi(input);

    std::cout << "Fib(" << n << ")  = " << bruteForce(n) << " by the brute force method." << std::endl;
    std::cout << "The recursive, top down, approach has an exponential runtime. It is accurate to write that it is O(2^n), but it is even more precise to say that it is O(φ^n) ≈ O(1.618^n). \n\tNote: φ, the Greek letter phi, represents the golden ratio." << std::endl;

    std::cout << "Fib(" << n << ")  = " << bottomUp(n) << " by the bottom up method." << std::endl;
    std::cout <<"With this method, we start at F0 and F1 then build to FN. The runtime and space complexity of this solution are both O(n). This \"bottom-up\" approach is an example of **dynamic programming**\n\t- One of the key factors of dynamic programming is observing repeated computation in a top-down recursive algorithm, then eliminateing that repeated computation by constructing a bottom-up algorithm that produces the same results." << std::endl;

    std::cout << "Fib(" << n << ")  = " << clever(n) << " by the clever method." << std::endl;
    std::cout << "This approach still has O(n) runtime, but has O(1) space complexity. With each iteration through the for-loop, the (n %% 2) term toggles between 0 and 1, allowing it to overwrite whichever one of the two previous values is no longer needed in its ascent toward FN";




    return 0;
}
