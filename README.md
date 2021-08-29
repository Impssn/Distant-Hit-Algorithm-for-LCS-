# Optimized-LCS-Algorithm
This finds the LCS in two given Strings in an Optimized way by Reducing Space Complexity primarily
I) Generally in this Approach the Characters of String 1 is taken to be in a row-wise manner and Characters of String 2 is taken to be in a column-wise manner.
Both of them are kept traversing in the Order of m*n Where m=>String 1's length , n=>String 2's length.
If there is a equal Letter(Character) found we assign '1' to the bool array initialized with 0 priorly
starting this Algorithm and keep the track of which is the larger index where 2 Characters coincided
and also weather row was larger or else column was larger is also kept into track. Next time we find 
a matching element in row and column we assign it's index to '1' only if the current index of the element
is greater than the previous greatest row if row was greatest in previous iteration or if the current
index of the element is greater than the previous greatest column if column was greatest in previous 
iteration.
II) Assign the elements of row's string whose indices are same as that of the indices in the bool array
where entries are '1'
III) Swap both the Strings
IV) Repeat (I) and (II)
V) Compare results obtained in (II) before Swapping and After Swapping
VI) The Substring with greater length is the LCS


Optimization Done : i) As We only use to Boolean arrays of length m and n Where m=>String 1's length , 
n=>String 2's length We reduce the Space Complexity compared to Traditional Dynamic Programming (DP)
where Space Complexity would be O(m)*O(n) but here Space Complexity would be O(m)+O(n).
ii) Here table type used may be reduced to bool which utilizes only 1 byte of space but in 
traditional (DP) we need to use integer type which costs 2 - 4 bytes of space.
