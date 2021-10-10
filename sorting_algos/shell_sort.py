def Shell_sort(lis):
    """
    :lis: list with orderable type
    :returns: None

    """
    sublistcount = len(lis)//2
    while sublistcount > 0:
        for i in range(sublistcount):
            gap_insertion_sort(lis, i, sublistcount)
        print(sublistcount, lis)
        sublistcount //= 2

def gap_insertion_sort(lis, start, gap):
    """
    selection sorts a list in place
    :returns: None
    :lis: a list with orderable type
    """
    for i in range(start+gap, len(lis), gap):
        temp = lis[i]
        k = i
        while k>=gap and temp<lis[k-gap]:
           lis[k] = lis[k-gap]
           k -= gap
        lis[k] = temp

if __name__=='__main__':
    lis = [4,5,6,4,54,6,7,0,4,7]
    print(lis)
    Shell_sort(lis)
    print(lis)

