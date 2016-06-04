# quick-sort
Quick sort 
Advantages of quicksort over merge sort

	inplace sorting (no addition space is required)
	sorting is done by swapping against a selected value called pivot in linear time O(n) (no constants hidden)
	Average running time is O(nlogn)

Disadvantages 
	worst running time is O(n^2)
	whole complexity is dependent on pivot selection
	external sorting is not supported as inplace sorting is done	
1.quicksort.cpp

using general recursive method



First element of Each sub array is selected as Pivot.

    l=first index                                           r =last index
     _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    |_p_|_ _ _<p_ _ _|_ _ _ >p_ _ _|_ _ _unpartitioned_ _ _ |
     pivot           i             j
                (i is the      (j is the
                boundary b/w   boundary b/w
                elements       partitioned &
                <p & >p )     unpartitioned elements)



