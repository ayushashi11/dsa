def bubble_sort(lis):
    """
    selection sorts a list in place
    :returns: None
    :lis: a list with orderable type
    """
    for i in range(len(lis)):
        for k in range(len(lis)-1, i, -1):
            if lis[k]<lis[k-1]:
                lis[k-1], lis[k] = lis[k], lis[k-1]

if __name__=='__main__':
    lis = [4,5,6,4,54,6,7,0,4,7]
    print(lis)
    bubble_sort(lis)
    print(lis)

