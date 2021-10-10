def selection_sort(lis):
    """
    selection sorts a list in place
    :returns: None
    :lis: a list with orderable type
    """
    for i in range(len(lis)):
        least = i
        for k in range(i+1, len(lis)):
           if lis[k]<lis[least]:
               least = k
        lis[least], lis[i] = lis[i], lis[least]

if __name__=='__main__':
    lis = [4,5,6,4,54,6,7,0,4,7]
    print(lis)
    selection_sort(lis)
    print(lis)

