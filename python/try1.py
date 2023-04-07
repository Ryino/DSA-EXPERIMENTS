def swap(array,a,b):
    array[a],array[b] = array[b],array[a]
def partition(array,start,end):
    median = (end - 1 - start) / 2
    median = median + start
    left = start + 1
    if (array[median] - array[end-1])*(array[start]-array[median]) >= 0:
        swap(array,start,median)
    elif (array[end - 1] - array[median]) * (array[start] - array[end - 1]) >=0:
         swap(array,start,end - 1)
    pivot = array[start]
    for right in range(start,end):
        if pivot > array[right]:
            swap(array,left,right)
            left = left + 1
    swap(array,start,left-1)
    return left-1
def quickSortHelper(array,start,end):
    if start < end:
        splitPoint = partition(array,start,end)
        quickSortHelper(array,start,splitPoint)
        quickSortHelper(array,splitPoint+1,end)
def quickSort(array):
    quickSortHelper(array,0,len(array))
if __name__ == "_main_":
    array = list(xrange(10))
    array.reverse()
    quickSort(array)
    print(array)

