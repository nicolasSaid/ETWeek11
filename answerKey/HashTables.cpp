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
 * ANSWERS:
 *
 * 1. Basically it is an array of values, where insertion,
 *    retrieval, placement, etc. are governed by a hash function
 *    that maps those values to those places.
 *
 * 2. 4 main characteristics:
 *      a. The hash value is fully determined by the data being hashed.
 *      b. The hash function uses all the input data.
 *      c. The hash function "uniformly" distributes the data across the entire set of possible hash values.
 *      d. The hash function generates very different hash values for similar strings.
 *      extra. Shouldn't rely on patterns!
 *
 * 3. In general, hash tables promise us O(1) access time for our data, but obviously come with
 *    a lot of restrictions on that.
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
 *
 * ANSWERS:
 *
 * 4. Because if value a and b collide, causing b to be placed in the next bucket, and
 *    then a is deleted, how will a find() function know that a being a's bucket being
 *    empty does NOT signify that there is no b?
 *
 * 5. Table:
 *
 *        +3   +8   +4   -8   -4   -4
     ┌─┐  ┌─┐  ┌─┐  ┌─┐  ┌─┐  ┌─┐  ┌─┐
    0│-│  │-│  │-│  │4│  │4│  │X│  │x│◄─Probe2
     ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤
    1│-│  │-│  │-│  │-│  │-│  │-│  │-│◄─Probe3
     ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤
    2│-│  │-│  │-│  │-│  │-│  │-│  │-│
     ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤
    3│-│  │3│  │3│  │3│  │3│  │3│  │3│
     ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤  ├─┤
    4│-│  │-│  │8│  │8│  │x│  │X│  │x│◄─Probe1
     └─┘  └─┘  └─┘  └─┘  └─┘  └─┘  └─┘
 *
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
 *
 * ANSWERS:
 *
 * 6. When a collision happens, the value is hashed again
 *    by a different hash function.
 *
 * 7. The table is either full of data or full of data and
 *    "deleted" tokens, in the case of open addressing
 *
 * 8. A new hash function must be defined for our new table,
 *    and ALL of the old data from the old table must be
 *    re-hashed with the new hash function.
 *
 * 8.1 Imagine if we were resizing our table of size 5 to
 *     a table of size 10. If we just used the old hash
 *     function, everything would be placed in the first
 *     5 slots of the new table, defeating the purpose
 *     of resizing it!
 *
 * 9. When it's full! Real data and "deleted" tokens will
 *    both slow down performance because of collisions.
 *
 */

/**
 * QUESTIONS:
 *
 * (You should review the linked list insertion/deletion stuff
 *  for Hash Tables with chaining!
 *   https://github.com/nicolasSaid/ETWeek7)
 *
 * 10. Why is collision resolution when dealing with chained hash
 *     tables FASTER than with open addressing?
 *
 * 11. Why can lookup be just as slow with chained hash tables as
 *     it is with open addressing?
 *
 * ANSWERS:
 *
 * 10. If a collision is detected, we essentially just add a new node
 *     to the linked list at that bucket. Inserting a new node into
 *     a linked list will ALWAYS be constant time! Compare this
 *     to the potential worst case scenario in open addressing, where
 *     the whole table is full and you need to do an O(N) iteration!
 *
 * 11. If everything gets hashed to the same chain, you have a linked list
 *     of O(N) size. Lookup can take O(N) time, which is the same as our
 *     worst case scenario with open addressing!
 *
 */
