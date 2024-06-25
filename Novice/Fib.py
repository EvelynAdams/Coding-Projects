# import numpy as np

'''
Our first solution is a brute force recursive solution solved from top down
'''
def bruteForce(n):
    #base case
    if n < 2: return n

    return bruteForce(n-1) + bruteForce(n-2)

'''
Our second solution features a bottom up aprach where we
start at 0 and buid up to n, elimating costly recursion
'''
def bottomUp(n):
    # count for base case where n is part of initaly known numbers and
    # use n+1 becaue we need the sum of the nth term
    array = [None] * max(2, n+1)

    array[0] = 0
    array[1] = 1

    for i in range(2, n+1):
        array[i] = array[i-1] + array[i-2]

    return array[n]

'''The Third apprach is especialy clever, we optimize the
second approace to use less space
'''
def clever(n):
    array = [0, 1]

    for i in range (2, n+1):
        array[i%2] = array[0] + array[1]

    return array[n%2]

def main():
    n = input('How many steps in the Fibonacci sequence do you wish to take? ')

    while not n.isdigit():
        n = input ('Invalid selection, must select a positive integer. Please try again:')
    
    n = int(n)
    print('Fib(' + str(n) + ')  = ' + str(bruteForce(n)) + ' by the brute force method.' )
    print('The recursive, top down, approach has an exponential runtime.'
        + 'It is accurate to write that it is O(2^n), but it is even more precise to say that it is O(φ^n) ≈ O(1.618^n). \n'
        + '\tNote: φ, the Greek letter phi, represents the golden ratio.\n')
    print('Fib(' + str(n) + ')  = ' + str(bottomUp(n)) + ' by the bottom Up method.' )
    print('With this method, we start at F0 and F1 then build to FN. '
        + 'The runtime and space complexity of this solution are both O(n).'
        + 'This \'bottom-up\' approach is an example of **dynamic programming**\n'
        + '\t- One of the key factors of dynamic programming is observing repeated computation in a top-down recursive algorithm, '
        + ' then eliminateing that repeated computation by constructing a bottom-up algorithm that produces the same results.\n')
    print('Fib(' + str(n) + ')  = ' + str(clever(n)) + ' by the clever method.' )
    print('This approach still has O(n) runtime, but has O(1) space complexity. '
        + 'With each iteration through the for-loop, the (n % 2) term toggles between 0 and 1,'
        + ' allowing it to overwrite whichever one of the two previous values is no longer needed in its ascent toward FN')


if __name__ == '__main__':
    main()
