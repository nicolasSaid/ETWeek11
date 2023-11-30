/**
 * QUESTIONS:
 * 1. What is Huffman Encoding and what is its goal?
 * 
 * 2. What Data Structure does Huffman Encoding use to represent its data?
 * 
 * ANSWERS:
 * 
 * 1. Huffman Encoding is a lossless compression algorithm that can convert
 *    a string into binary that takes up less bits than normal charaters would
 * 
 * 2. Huffman Encoding using a Binary Tree to represent its data, and the leaves
 *    of the tree represents the characters that are encoded
 */

/**
 * QUESTIONS:
 * 3. How can we build a Huffman Tree to represent the Huffman Encoding of a string?
 *      Try and create a Huffman Tree for the string: "Banana"
 *      Note: Huffman trees are not unique, so if your tree looks differnt than someone elses, don't worry!
 * 
 * 4. After creating a Huffman Tree, how can we convert our string into binary?
 *      Try and convert "Banana" into binary!
 * 
 * ANSWERS:
 * 
 * 3. create a freqency chart that represents the number of occurances for each character.
 *    then, remove the two least-occuring characters, create a sub tree by combining them,
 *    then re-insert the combined sub-tree into the frequency chart with their combined frequency
 *    repeat the process until there is only one tree
 * 
 * 4. There isnt a unique answer to this! try and create a tree and see what you get!
 */