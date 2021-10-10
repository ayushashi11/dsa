def merge_sort(arr):
    """

    :arr: TODO
    :returns: TODO

    """
    if len(arr) > 1:
        mid = len(arr)//2
        lefthalf = arr[:mid]
        righthalf = arr[mid:]
        merge_sort(lefthalf)
        merge_sort(righthalf)
        i=j=k=0
        while i<len(lefthalf) and j<len(righthalf):
            if lefthalf[i]<righthalf[j]:
                arr[k] = lefthalf[i]
                i += 1
            else:
                arr[k] = righthalf[j]
                j += 1
            k += 1
        while i<len(lefthalf):
            arr[k] = lefthalf[i]
            i += 1
            k += 1
        while j<len(righthalf):
            arr[k] = righthalf[j]
            j += 1
            k += 1

if __name__=='__main__':
    lis = [4,5,6,4,54,6,7,0,4,7]
    print(lis)
    merge_sort(lis)
    print(lis)

