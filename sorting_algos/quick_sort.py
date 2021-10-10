def quick_sort(arr, low, high):
    """TODO: Docstring for quick_sort.

    :ar: TODO
    :returns: TODO

    """
    if low<high:
        pivot = partition(arr, low, high)
        quick_sort(arr, low, pivot-1)
        quick_sort(arr, pivot+1, high)

def partition(arr, low, high):
    """TODO: Docstring for partition.

    :ar: TODO
    :returns: TODO

    """
    pivot = low
    arr[pivot], arr[high] = arr[high], arr[pivot]
    for i in range(low, high):
        if arr[i] <= arr[high]:
            arr[i], arr[low] = arr[low], arr[i]
            low += 1
    arr[low], arr[high] = arr[high], arr[low]
    return low

if __name__=='__main__':
    lis = [4,5,6,4,54,6,7,0,4,7]
    print(lis)
    quick_sort(lis, 0, len(lis)-1)
    print(lis)

