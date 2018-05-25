
def merge(arr, left, right, mid):

    # split arr into the two sorted halves to compare
    lowHalf = list(arr[left:mid+1])
    highHalf = list(arr[mid+1:right+1])

    i=0
    j=0
    k=left
                
    while(i<len(lowHalf) and j<len(highHalf)):
        if lowHalf[i] < highHalf[j]:
            arr[k] = lowHalf[i]
            i+=1
        else:
            arr[k] = highHalf[j]
            j+=1
        k+=1

    while(i<len(lowHalf)):
        arr[k] = lowHalf[i]
        i+=1;k+=1
    while(j<len(highHalf)):
        arr[k] = highHalf[j]
        j+=1;k+=1
          
 
def mergesort(arr, left=None, right=None):
    # python defaults checks
    if left == None: left = 0
    if right == None: right = len(arr)-1

    # base case
    if (right-left) < 1: return
    
    mid = int((left+right)/2)

    mergesort(arr,left,mid)
    mergesort(arr,mid+1,right)
    merge(arr,left,right, mid)
    

    
    
    
