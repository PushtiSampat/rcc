# Heap Data Structure

<!-- :: is used to center Element -->
<!-- https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet#tables -->
| Element     | root at 0   |   root at 1
| ----------- |:-----------:| ------------
| Left child  | index*2 + 1 |   index*2
| Right child | index*2 + 2 |   index*2 + 1
| Parent      | (index-1)/2 |   index/2

## Full Binary Tree
- A full binary tree (sometimes proper binary tree or 2-tree)
is a tree in which every node other than the leaves has two children.

- A full binary tree can have (2 ^ (h+1) - 1) number of nodes
where h is height and height starts from 0


## Complete Binary Tree
- A complete binary tree is a binary tree in which every level,
except possibly the last, is completely filled,
and all nodes are as far left as possible.

1. The level before the last level must be full binary tree 
2. The last most level must have elements from left side only

>For Using Heap, we must see that Complete Binary Tree Data Structure is always maintained

## Types Of Heap
* **Max Heap:** Every parent is having value greater than its children
* **Min Heap:** Every parent is having value less than its children

## Operations in Heap

### Insertion in Heap
* To insert element, insert to next possible node of Complete Binary Tree and then swap and adjust it according to heap tree
* Thus, the Operations takes place from bottom to top

### Deletion in Heap
* To delete element, delete the root node of Tree and then swap and adjust it according to heap tree
* Thus, the Operations takes place from top to bottom

> In max heap tree, after Deleting each element, we have extra space in array and thus we move every deleted element to last. Doingso, till al nodes are deleted, the array will be sorted in Ascending order. This is how heap sort works

## Heapify
* Create a heap tree from array is called Heapify
* Heapify is the process of converting a binary tree into a Heap data structure.

### Steps (According to Max heap)
1. Go to last level of Complete Binary Tree
2. Take the right most element
3. Examine if it has any child or not.
4. If yes, check if heap is maintained or not
5. If heap Structure is not maintained, swap and adjust accordingly
6. Select next element and repeat from Step 3.
7. Thus, A heap tree will be formed.

----

Link
[Youtube Video for Heap Data Structure](https://www.youtube.com/watch?v=HqPJF2L5h9U&t=793s&ab_channel=AbdulBari)
