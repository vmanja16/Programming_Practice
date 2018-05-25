def swap(arr, first, second):
    temp = arr[first]
    arr[first] = arr[second]
    arr[second] = temp

def partition(arr, left, right):
    # choose right most value as pivot value
    pivot_val = arr[right]
    pivot_index = left
    # pivot index is leftmost index with val > pivot value
    
    for j in range(left, right): 
        if arr[j] > pivot_val: continue
        if arr[j] <= pivot_val:
            swap(arr,j,pivot_index)
            pivot_index += 1
    # place pivot val in finalized pivot index
    swap(arr,right, pivot_index)

    return pivot_index
    

def quicksort(arr, left=None, right=None):

    # python defaults checks
    if left == None: left = 0
    if right == None: right = len(arr)-1
    
    # base cases
    diff = right - left
    if diff < 1: return
    if diff == 1:
        swap(arr, left, right)
        return
    # partition
    pivot_index = partition(arr, left, right)
    # recursive call on each partition
    quicksort(arr, left, pivot_index-1)
    quicksort(arr, pivot_index+1, right)
