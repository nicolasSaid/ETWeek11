/**
 * QUESTIONS:
 * 1. Describe the general operation of the following sorting
 *    algorithms:
 *      a. Merge Sort
 *      b. Selection Sort
 *      c. Quick Sort
 *      d. Insertion Sort
 *      e. BST Sort
 * 
 * ANSWERS:
 * 1. General operations:
 *      a. Recursively split the array into sub-arrays of size n/2,
 *         then n/4, then n/8 ... until they are of size 1. Then merge
 *         the individual arrays into arrays of size 2. Then merge
 *         those arrays into arrays of size 4 ... until the entire array
 *         is sorted.
 * 
 *      b. Selection sort builds a "sorted" section on the left side
 *         of the array by iterating through the array and "selecting"
 *         the next smallest value. After it finds that smallest value,
 *         it appends it to the end of the "sorted section", increasing
 *         the size of the sorted section:
 * 
 *         iterate
 *         ────────►
 *        │    │find smallest
 *  ┌─┬─┬─┼─┬─┐▼┌─┬─┐
 *  │1│2│3│5│8│4│6│7│
 *  └─┴─┴─┼─┴─┴─┴─┴─┘
 * Sorted │
 * 
 * 
 *           Swap with value
 *         ┌───┐ at the end
 *         │   │ of the sorted
 *  ┌─┬─┬─┐▼┌─┬┴┬─┬─┐  section.
 *  │1│2│3│4│8│5│6│7│
 *  └─┴─┴─┴─┼─┴─┴─┴─┘  Now the sorted
 *   Sorted │          section is bigger!
 * 
 *      c. Quick sort selects a "pivot" element from the array
 *         and "partitions" the array, to have everything smaller than
 *         that element on the left and everything bigger on the right.
 *         Then it treats the left and right subarrays as their own 
 *         unsorted arrays which get a pivot and it partitions them.
 *         It does this until the sub arrays are all of size 1 and then
 *         we know the array is sorted.
 * 
 *      d. Insertion sort works by maintaining a "sorted" section on
 *         the left of the array. It looks at the next element outside
 *         of the "sorted section" and iterates back through the
 *         "sorted section" until that new element is in the right spot.
 *         Then it "inserts" that new element into the sorted section,
 *         growing it! Diagram:
 * 
 *          │Grab next element
 *   ┌─┬─┬─┐▼┌─┬─┬─┬─┐
 *   │1│2│7│4│5│3│8│6│
 *   └─┴─┴─┼─┴─┴─┴─┴─┘
 * "Sorted"│
 * 
 * 
 *        Iterate back
 *        ◄──
 *        │insert
 *   ┌─┬─┐▼┌─┬─┬─┬─┬─┐
 *   │1│2│4│7│5│3│8│6│
 *   └─┴─┴─┴─┼─┴─┴─┴─┘  Now the sorted
 *  "Sorted" │          section is bigger!
 * 
 *
 *      e. BST sort just uses the values in an array to create a Binary Search Tree
 *         and performs an "In-order traversal" to visit the values in increasing
 *         order
 * /

/**
 * QUESTIONS:
 * 2. What are the runtime complexities
 *    of the following:
 *      a. Merge Sort
 *      b. Selection Sort
 *      c. Quick Sort
 *      d. Insertion Sort
 * 
 * 3. Would it be accurate to describe
 *    Merge Sort as "O(n^2)"?
 * 
 * 4. Would it be accurate to describe
 *    Selection Sort as "O(n^5)"?
 * 
 * 5. Under what circumstances will Quick Sort
 *    perform exceptionally poorly?
 * 
 * 6. Under what circumstances will Insertion
 *    Sort perform exceptionally well?
 * 
 * 7. Under what circumstances will Merge Sort
 *    perform exactly as well as you would 
 *    expect?
 * 
 * ANSWERS:
 * 2. Runtime complexities:
 *      a. Merge Sort = tight upper bound O(nlogn)
 *      b. Selection Sort = tight upper bound O(n^2)
 *      c. Quick Sort = tight upper bound O(n^2) 
 *      d. Insertion Sort = tight upper bound O(n^2)
 *      e. BST Sort = tight upper bound O(n^2) [Note: if tree is balance O(nlogn)]
 * 
 * 3. Yes! remember, Big-O just means "Won't perform worse than...",
 *    And it is TRUE that Merge Sort won't perform worse than n^2! 
 *    It's just not very helpful. Remember, "big-O" and "tight upper bound
 *    big-O" aren't necessarily the same.
 * 
 * 4. Sure, same reason as above. Selection sort won't EVER perform
 *    worse than n^5!
 * 
 * 5. Quick sort will perform poorly when the partition puts everything
 *    on one side of the pivot and nothing else on the other. This
 *    could be caused by the pivots being selected in ascending order,
 *    descending order, or alternating between min/max since all of
 *    those choices cut the sub-arrays into arrays of size 1 and n-1.
 * 
 * 6. Insertion sort is great on arrays that are NEARLY sorted. Refer
 *    back to the diagram in 2b, the algorithm would grab the out of
 *    place item, insert it into place, and not have to do much work
 *    for the rest of the array.
 * 
 * 7. Merge sort will ALWAYS take O(nlogn) time, no matter what! 
 */