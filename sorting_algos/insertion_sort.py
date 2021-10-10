def insertion_sort(lis):
    """
    selection sorts a list in place
    :returns: None
    :lis: a list with orderable type
    """
    for i in range(len(lis)):
        temp = lis[i]
        k = i
        while k>0 and temp<lis[k-1]:
           lis[k] = lis[k-1]
           k-=1
        lis[k] = temp

if __name__=='__main__':
    lis = [4,5,6,4,54,6,7,0,4,7]
    print(lis)
    insertion_sort(lis)
    print(lis)

