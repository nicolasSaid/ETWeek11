/**
 * QUESTIONS:
 * 
 * 1. What is a hash table?
 * 
 * 2. What are the 4 main characteristics of a good hash function?
 * 
 * 3. What are the benefits of using a hash table?
 * 
 * 
 */

/**
 * QUESTIONS:
 * 
 * 4. When using open addressing, why is it important to use different
 *    tokens to denote that a bucket has been empty forever, or has been occupied and cleared?
 * 
 * 5. Given the following table, with hash function f(x) = x mod 5, and linear probing,
 *    perform the following operations:
 * 
 *       a. Insert 3
 *       b. Insert 8
 *       c. Insert 4
 *       d. Delete 8
 *       e. Delete 4
 *       f. Delete 4 (There is no 4, but how does the table know this?)
 * 
 * 
 *        +3   +8   +4   -8   -4   -4
     ┌─┐  ┌─┐  ┌─┐  ┌─┐  ┌─┐  ┌─┐  ┌─┐
    0│-│  │-│  │-│  │-│  │-│  │-│  │-│
     ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤
    1│-│  │-│  │-│  │-│  │-│  │-│  │-│
     ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤
    2│-│  │-│  │-│  │-│  │-│  │-│  │-│
     ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤
    3│-│  │-│  │-│  │-│  │-│  │-│  │-│
     ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤
    4│-│  │-│  │-│  │-│  │-│  │-│  │-│
     └─┘  └─┘  └─┘  └─┘  └─┘  └─┘  └─┘
 */

/**
 * QUESTIONS:
 * 
 * 6. What is double hashing?
 * 
 * 7. What is meant when a hash table is "aged" or "old"?
 * 
 * 8. What work needs to be done to resize a hash table?
 * 
 * 8.1 Why can't we just use the old hash function?
 * 
 * 9. When will performance be poor on an open-addressed
 *    table?
 */

/**
 * QUESTIONS:
 * 
 * (You should review the linked list insertion/deletion stuff 
 *  for Hash Tables with chaining! 
 *  https://github.com/nicolasSaid/ETWeek7)
 * 
 * 10. Why is collision resolution when dealing with chained hash
 *     tables FASTER than with open addressing?
 * 
 * 11. Why can lookup be just as slow with chained hash tables as
 *     it is with open addressing?
 * 
 */