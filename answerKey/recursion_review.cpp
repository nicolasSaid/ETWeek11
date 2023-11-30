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
 * 
 * ANSWERS:
 * 1. Definitions:
 *      a. The smallest possible case that the
 *         recursive function can encounter. Hitting
 *         the base case is what STOPS the recursive
 *         function calls, if there weren't one, 
 *         the recursive calls would repeat forever.
 *      b. The recursive call is a call made by a function
 *         to itself, with a smaller version of the same
 *         problem. Each call generates another function
 *         call on the call stack, with a slightly smaller
 *         problem size.
 *      c. Tail recursion is when the last thing to happen
 *         in the function call is the recursive call.
 * 
 * 2. The recursive calls reside on the call stack, (yes, the
 *    same "stack" as local variables in a function), and each
 *    recursive call gets a chunk of memory on the stack to 
 *    allocate those local variables and handle returns and stuff
 *    like that. Here's a crude visual representation of calling
 *    factorial(3) from the main() function:
 * 
*    Call stack                   Call stack                  Call stack
 * 
 * │ ┌────────────────┐ │      │ ┌─────────────────┐ │    │ ┌────────────────┐ │
 * │ │                │ │      │ │                 │ │    │ │                │ │
 * │ │ main()         │ │      │ │ main()          │ │    │ │  main()        │ │
 * │ │                │ │      │ │                 │ │    │ │                │ │
 * │ ├────────────────┤ │      │ ├─────────────────┤ │    │ ├────────────────┤ │
 * │ │                │ │      │ │                 │ │    │ │                │ │
 * │ │ factorial(3)   │ │  ->  │ │ factorial(3)    │ │ -> │ │  factorial(3)  │ │
 * │ │                │ │      │ │                 │ │    │ │                │ │
 * │ └────────────────┘ │      │ ├─────────────────┤ │    │ ├────────────────┤ │
 * │                    │      │ │                 │ │    │ │                │ │
 * │         .          │      │ │ factorial(2)    │ │    │ │  factorial(2)  │ │
 * │         .          │      │ │                 │ │    │ │                │ │
 * │         .          │      │ └─────────────────┘ │    │ ├────────────────┤ │
 * │         .          │      │                     │    │ │                │ │
 * │         .          │      │          .          │    │ │  factorial(1)  │ │
 * │         .          │      │          .          │    │ │                │ │
 * │         .          │      │          .          │    │ └────────────────┘ │
 * │         .          │      │          .          │    │                    │
 * │         .          │      │          .          │    │          .         │
 * │         .          │      │          .          │    │          .         │
 * ▼         .          ▼      ▼          .          ▼    ▼          .         ▼
 * 
 * NOTE: the call stack usually grows DOWN. But since it's
 *       a Stack, we add and remove from the bottom. Same
 *       principle as if we did it to the top.
 * 
 * 3. If we didn't have a base case (in factorial, we might stop
 *    if n == 1), it would just keep calling itself as n got 
 *    smaller and smaller ... and never stop!
 * 
 * 4. Think about it like Proof By Induction:
 *    you start with N, N-1, N-2 ... all the way down
 *    to 1 or 0. If we didn't decrease the size of 
 *    the problem that we're dealing with, the function 
 *    would just loop forever, unchanging.
 * 
 * 5. To understand why tail recursion is good, you have to 
 *     first understand why non-tail recursion is BAD. Consider
 *     the stack diagram from above, there is memory allocated 
 *     for each function call because each function call would
 *     theoretically be storing one of the numbers which then 
 *     all get multiplied together once we get down to the
 *     base case. 
 * 
 *     With tail recursion, since you're passing all the relevant
 *     data from the parent function to the child (unlike regular
 *     non-tail recursion where the parent is WAITING for the child),
 *     the parent doesn't need to wait around for the child to finish --
 *     the child can handle everything from the point that it gets called
 *     and we **no longer need the parent**! Because of this, the 
 *     compiler gets to say "hmmm... we could just de-allocate the
 *     parent as soon as the child gets called" and we get to save a
 *     ton of extra space! 
 * 
 *     Consider what a call to factorial(100) would look like with 
 *     the previous diagram, and compare it to the following with
 *     tail recursion:
 * 
 *   Call stack                   Call stack                        Call stack
 * 
 * │ ┌────────────────┐ │      │ ┌─────────────────┐ │            │ ┌─────────────────┐ │
 * │ │                │ │      │ │                 │ │            │ │                 │ │
 * │ │ main()         │ │      │ │  main()         │ │            │ │  main()         │ │
 * │ │                │ │      │ │                 │ │            │ │                 │ │
 * │ ├────────────────┤ │      │ ├─────────────────┤ │            │ ├─────────────────┤ │
 * │ │                │ │      │ │                 │ │            │ │                 │ │
 * │ │ factorial(100) │ │  ->  │ │ factorial(99)   │ │ ->... ->   │ │  factorial(1)   │ │
 * │ │                │ │      │ │                 │ │            │ │                 │ │
 * │ └────────────────┘ │      │ └─────────────────┘ │            │ └─────────────────┘ │
 * │         .          │      │          .          │            │          .          │
 * │         .          │      │          .          │            │          .          │
 * │         .          │      │          .          │            │          .          │
 * │                    │      │                     │            │                     │
 * │                    │      │                     │            │                     │
 * ▼                    ▼      ▼                     ▼            ▼                     ▼
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
 * 
 * ANSWERS:
 * 6. See functions
 * 
 * 7. Memory requirements:
 *      a. Although you'd think 40B, since this
 *         function uses tail recursion, each
 *         subsequent call gets to overwrite
 *         the previous and it only uses 4B
 *         of memory. It uses those 4B of memory
 *         10 times though!
 *      b. 40B since it allocates 4B 10 times!
 */
int fib(int n, int a = 0, int b = 1){
    if (n == 0) // base case!
        return a;
    if (n == 1) // another base case!
        return b;
    return fib(n - 1, b, a + b); // tail recursive call!
}

int factorial(int n){
    if(n < 2) // base case!
        return 1;
    return n * factorial(n); // regular recursive call!
}