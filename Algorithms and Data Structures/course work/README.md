### Coursework 10. String matching algorithms. 

**Goal**: Study string matching algorithms: the Rabin-Karp algorithm and KMP. Among many other applications, string-matching algorithms search for particular patterns in DNA sequences, and internet search engines also use them to find Web pages relevant to queries.

**Problems and methods:**
+ Take any chapter from your favourite book or poem.
+ Implement the **naive string-matching algorithm** from Chapter 32.1 of Cormen and the **Rabin-Karp algorithm** to search for a given template (pattern) in a given text.

There are two strings at the input: a pattern P and a text T. The task is to find all occurrences of the string P in the string T as a substring.
Output: In the first line, print the number of occurrences of string P in string T. In the second line, print, in ascending order, the numbers of characters in string T from which occurrences of P begin.

+ Do the same with **Knuth-Morris-Pratt (or KMP)** algorithm.
+ Analyze the results and compare them.
