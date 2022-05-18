# HW3: Algorithms with Stacks, Sets, Maps, & Heaps

The goal of this homework is to practice creating and analyzing algorithms that use fundamental data structures previously covered. This assignment is due at **11:59pm on February 10, 2022**.

### Submitting & Grading
In order to submit this assignment, you must download your code as a ZIP file and upload it to Gradescope. Please include all files.

We've provided some example inputs and outputs to help you test your code and check your work. The autograder in general may have other test cases beyond what is provided here. You should consider writing your own examples.

Your grade on this homework will be a combination of the below:
- Written questions (7 points)
- LeetCode (3 points)
- Autograder test cases (21 points)
- Documentation (6 points)
- C++ Code Style (3 points)

For each coding question, you may lose up to half of the earned autograder points by not satisfying runtime constraints.

### Corrections
*If you miss points on this assignment,* there will be an opportunity to earn them back by doing homework corrections, so don't worry about the grade if you're having a tough time on some of the questions. More information will be posted on Piazza.

### Academic Integrity
Remember that you can consult outside resources and work with other students as long as you write up your own solutions and cite any links or people you received help from within `citations.txt`.


## Q1. PermissionChecker

We want to design `PermissionChecker` to quickly check if users visiting our service have permission. The `PermissionChecker::PermissionChecker(std::vector<int>& passlistUserIDs)` constructor is initialized with `passlistUserIDs`, the integer IDs of all users who have permission. Afterward, `PermissionChecker::hasPermission(int userID)` will be called several thousand times an hour as multiple users ping our service.

Note that because the constructor is called only once on machine startup, we are not as worried about the runtime of whatever code we write in the constructor, but `hasPermission` should run as efficiently as possible. Please write your answers in q1.txt.

**Q1.A (2 points)** If we could not use any additional space beyond the non-const vector<int\> `passlistUserIDs`, what would your design be to make `hasPermission` run faster than O(n) time, where `n` is the size of `passlistUserIDs`? Please provide:
 - the proposed procedure in the `PermissionChecker` constructor
 - the proposed procedure in `hasPermission`
 - the tight upper-bound time complexity of one call of `hasPermission` in your proposal

**Q1.B (2 points)** If we had no space constraints, what would a design be to make `hasPermission` run even faster?
 - the proposed procedure in the `PermissionChecker` constructor
 - the proposed procedure in `hasPermission`
 - the tight upper-bound time complexity of one call of `hasPermission` in your proposal

## Q2. LeetCode: Daily Temperatures (3 points)
Problem: [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)

**Q2.A** Provide one set of expected inputs and outputs that is not provided to be sure you understand the question.

**Q2.B** What would a straightforward approach to this problem be that runs in O(N^2) time complexity and O(1) space complexity? Describe an approach in words.

**Q2.C** Describe your approach in words and be sure to use a monotonic stack as discussed during lecture. Then, solve the problem. After clicking "Submit" and getting status "Accepted", take a screenshot of the entire window (with the time submitted and your code). Attach the complete and successful screenshot as an image named Q2.jpg in your code submissions. Hint: you may find it helpful to refer to the monotonic stack code provided in lecture.

**Q2.D** What change(s) would you make to your code if `answer[i]` is the number of days you have to wait after the ith day to get a **colder** temperature? 

**Q2.E** Examine your code. What is the largest number of times that push() will be called in the worst case (hint: look at the loop)? What is the largest number of times pop() will be called (hint: pop() will never be called unless there are elements to pop because we check if the stack is empty)? Use this to give a tight upper-bound on the worst-case time complexity and space complexity.

**[Optional]** If you want to practice using the monotonic stack on a new problem, try [Final Prices with a Special Discount](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/submissions/) ideally without referencing your previous code. Note: there is no credit here - we are just providing additional practice for your own reference.


## Q3. countLegoHouses (6 points)

You have N lego pieces, with each piece represented as a character in the `std::string bucket`.

You're given a `std::string recipe` of length-M which represents the M pieces it takes to build one lego house. Order doesn't matter for either `recipe` or `bucket`. Count the number of `recipe` lego houses you can create from your lego `bucket`. Once a piece from the bucket is used to create a house, it cannot be used in another house. Write `countLegoHouses`. Examples:
```cpp
  std::cout << countLegoHouses("abb", "babab"); // 1
  std::cout << countLegoHouses("abb", "bababcdb"); // 2
```
If `recipe` is an empty string, throw an `invalid_argument` exception. Your runtime must be O(M + N) to receive full credit. Note: here and in the future, please use `unordered_map` and `unordered_set` instead of (ordered) `set` and `map` which do not have O(1) insertsion / operations because they do not use hashing like their unordered counterparts.

## Q4. findLargestAnagroup (6 points)

Given a `vector<string>` of size N, return the the largest "anagroup". An anagroup contains all words that are anagrams of each other. The anagroup's words should appear in your returned vector in the same relative ordering they appeared in the input vector. Examples:
```
  std::cout << "Q4" << std::endl;
  std::vector<std::string> anagroup1 = findLargestAnagroup({"act", "tac", "yam", "cat", "may", "hello"}); 
  std::cout << containerToString(anagroup1) << std::endl;  // {"act", "tac", "cat"}
  std::vector<std::string> anagroup2 = findLargestAnagroup({"bear", "hello", "bare"}); 
  std::cout << containerToString(anagroup2) << std::endl;  // {"bear", "bare"}
```
Assume that none of the words will be larger than 20 characters (i.e. constant size) and only contain the lowercase characters a-z. If there are multiple tied for the largest anagroup, you may return any of the largest. Your runtime must be O(N) to receive full credit. Hint: You may use `algorithm`s built-in "sort" on the characters of a word. Why might this be helpful when working with anagrams?

## Q5. mergeSortedLists

You are given M sorted already-sorted `vector<double>`s. Each of the vectors is at most length N. For simplicity, you may assume that across all vectors, there are no duplicate doubles. Our task is to efficiently merge these vectors into one sorted vector to return. Example:
```
  std::vector<double> q5Output = mergeSortedLists({{1.1, 2.4}, {4.5}, {-3.4, 8.9}});
  std::cout << containerToString(q5Output) << std::endl;  // {-3.4, 1.1, 2.4, 4.5, 8.9}
```


**Q5.A (2 points)** Propose a "straightforward" solution (no constraints on runtime) to this problem. Describe your proposal in words and analyze its time complexity. Please use M and N as defined above, provide a tight upper bound, and justify your answer in q5.txt.

**Q5.B (1 point)** What is the tight upper-bound on the worst case time complexity for the approach described below? Please use M and N as defined above, provide a tight upper bound, and justify your answer in q5.txt.

*Initialize a length-M vector `vecPointers`  with 0's that represent pointing to the beginning of each sorted vector. On each step, we iterate through the elements pointed to by `vecPointers` to find the minimum value. When it is found, we push_back that value to our answer, increment that vector's pointer in `vecPointers` and repeat the process until we've accounted for all elements.*

**Q5.C (9 points)** Write the implementation for a more efficient mergeSortedLists in answers.cpp. To earn full points, you must have a runtime of O(N \* M \* log(M)) and use `std::priority_queue`.

Hints:
- The solution is **NOT** to insert all elements into a heap at one time, then extract them from the heap. That solution would O(N \* M \* log(M \* N)), not the required O(N \* M \* log(M)).
- At each step in Q5.B, we are considering one element from every vec at a time, and at each step, we find the minimum of those m values. What if we stored these m values in a heap that we update?
