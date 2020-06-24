The first line is n - the number of test cases. The next 2*n lines is all the test cases. Each test case is consists of 2 lines, the first line contains the index, the second line contains the name.

```sh
79
172
Factorial Trailing Zeroes
179
Largest Number
198
House Robber
200
Number of Islands
202
Happy Number
203
Remove Linked List Elements
207
Course Schedule
208
Implement Trie (Prefix Tree)
213
House Robber II
215
Kth Largest Element in an Array
221
Maximal Square
226
Invert Binary Tree
230
Kth Smallest Element in a BST
231
Power of Two
237
Delete Node in a Linked List
238
Product of Array Except Self
278
First Bad Version
283
Move Zeroes
300
Longest Increasing Subsequence
322
Coin Change
328
Odd Even Linked List
334
Increasing Triplet Subsequence
338
Counting Bits
344
Reverse String
347
Top K Frequent Elements
367
Valid Perfect Square
368
Largest Divisible Subset
380
Insert Delete GetRandom O(1)
383
Ransom Note
387
First Unique Character in a String
392
Is Subsequence
402
Remove K Digits
438
Find All Anagrams in a String
442
Find All Duplicates in an Array
451
Sort Characters By Frequency
476
Number Complement
518
Coin Change 2
525
Contiguous Array
528
Random Pick with Weight
540
Single Element in a Sorted Array
560
Subarray Sum Equals K
567
Permutation in String
678
Valid Parenthesis String
700
Search in a Binary Search Tree
704
Binary Search
718
Maximum Length of Repeated Subarray
719
Find K-th Smallest Pair Distance
733
Flood Fill
768
Max Chunks To Make Sorted II
769
Max Chunks To Make Sorted
771
Jewels and Stones
815
Bus Routes
844
Backspace String Compare
845
Longest Mountain in Array
870
Advantage Shuffle
875
Koko Eating Bananas
876
Middle of the Linked List
886
Possible Bipartition
901
Online Stock Span
918
Maximum Sum Circular Subarray
931
Minimum Falling Path Sum
973
K Closest Points to Origin
986
Interval List Intersections
992
Subarrays with K Different Integers
993
Cousins in Binary Tree
997
Find the Town Judge
1008
Construct Binary Search Tree from Preorder Traversal
1029
Two City Scheduling
1035
Uncrossed Lines
1046
Last Stone Weight
1079
Letter Tile Possibilities
1109
Corporate Flight Bookings
1143
Longest Common Subsequence
1207
Unique Number of Occurrences
1232
Check If It Is a Straight Line
1277
Count Square Submatrices with All Ones
1426
Counting Elements
```


```python
def solve():
	path = "D:\\_\\leetcode\\"
	n = int(input(""))
	for i in range(n):
		idx = input("")
		while (len(idx) < 4):
			idx = "0" + idx
		prolem_name = input("")
		name = idx + ". " + prolem_name
		try:
		    os.mkdir(path + name)
		except OSError:
		    print ("Create %s failed" % name)
		else:
		    print ("Accepted %s" % name)

def solve():
	path = "D:\\_\\leetcode\\"
	dir_list = os.listdir(path)
	for x in dir_list:
		if os.path.isdir(path + x):
			file = "s1.cpp"
			with open(path + x + "\\" + file, "w") as fp:
				fp.write("#include <bits/stdc++.h>\nusing namespace std;\n\n")
			file = "README.md"
			with open(path + x + "\\" + file, "w") as fp:
				fp.write("## " + x + "\n\n")
```