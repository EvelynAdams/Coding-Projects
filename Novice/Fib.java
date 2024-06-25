import java.util.Scanner;

class Fib{
  /*Our first solution is a brute force recursive solution solved from top down*/
  public static int bruteForce(int n){
    // Base cases: fib(0) = 0, fib(1) = 1
    if (n < 2) return n;

    return bruteForce(n-1) + bruteForce(n-2);
  }

  /*Our second solution features a bottom up aprach where we
  start at 0 and buid up to n, elimating costly recursion*/
  public static int bottomUp(int n){
    //count for base case where n is part of initaly known numbers and
    // use n+1 becaue we need the sum of the nth
    int [] array = new int[Math.max(2, n+1)];

    array[0] = 0;
    array[1] = 1;

    for(int i = 2; i <= n; i++)
      array[i] = array[i-1] + array[i-2];

    return array[n];
  }

  /*The Third apprach is especialy clever, we optimize the
  second approace to use less space*/
  public static int clever(int n){
    int [] array = new int[]{0, 1};

    for (int i = 2; i <= n; i++)
       array[i%2] = array[0] + array[1];

    return array[n%2];
  }

  public static void main(String args[])
  {
    System.out.println("How many steps in the Fibonacci sequence do you wish to take?");
    Scanner myObj = new Scanner(System.in);
    int n = myObj.nextInt();

    while (n < 0){
        System.out.println("Invalid selection, must select a positive integer. Please try again: ");
        n = myObj.nextInt();
    }

    System.out.println("Fib(" + n + ")  = " + bruteForce(n) + " by the brute force method." );
    System.out.println("The recursive, top down, approach has an exponential runtime."
                        + "It is accurate to write that it is O(2^n), but it is even more precise to say that it is O(φ^n) ≈ O(1.618^n). \n"
                        + "\tNote: φ, the Greek letter phi, represents the golden ratio.\n");
    System.out.println("Fib(" + n + ")  = " + bottomUp(n) + " by the bottom Up method." );
    System.out.println("With this method, we start at F0 and F1 then build to FN. "
                      + "The runtime and space complexity of this solution are both O(n)."
                      + "This \"bottom-up\" approach is an example of **dynamic programming**\n"
                      + "\t- One of the key factors of dynamic programming is observing repeated computation in a top-down recursive algorithm, "
                      + " then eliminateing that repeated computation by constructing a bottom-up algorithm that produces the same results.\n");
    System.out.println("Fib(" + n + ")  = " + clever(n) + " by the clever method." );
    System.out.println("This approach still has O(n) runtime, but has O(1) space complexity. "
                      + "With each iteration through the for-loop, the (n % 2) term toggles between 0 and 1,"
                      + " allowing it to overwrite whichever one of the two previous values is no longer needed in its ascent toward FN");


  }
}
