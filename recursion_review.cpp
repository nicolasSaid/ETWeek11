/**
 * QUESTION:
 * 1. Define the following terms:
 *      a. Base Case
 *      b. Recursive Call
 *      c. Tail recursion
 * 
 * 2. Where in memory do recursive calls reside?
 * 
 * 3. What would happen if we didn't have a base case?
 * 
 * 4. Why do we need to make recursive calls on smaller
 *    subproblems than the one we're dealing with?
 * 
 * 5. Why is tail recursion good?
 */

/**
 * QUESTION:
 * 6. Locate the following in these functions:
 *      a. Base case
 *      b. Recursive call
 *      c. Tail recursion
 * 
 * 7. If each call to these functions only
 *     requires 4B of memory on the call stack
 *     to be allocated, how much memory
 *     will be required for:
 *      a. fib(10)
 *      b. factorial(10)
 */
int fib(int n, int a = 0, int b = 1){
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fib(n - 1, b, a + b);
}

int factorial(int n){
    if(n < 2)
        return 1;
    return n * factorial(n);
}