def binary_search(lis, val):
    if len(lis)==0:
        return -1
    mid=len(lis)//2
    if lis[mid]==val:
        return mid
    elif lis[mid]>val:
        return binary_search(lis[:mid], val)
    else:
        return mid+1+binary_search(lis[mid+1:], val)
if __name__=="__main__":
    lis=[-98,64,0,72,1069,23,4,2.5,-420.69,72]
    lis.sort()
    print(lis)
    v=1069
    index=binary_search(lis,v)
    print(index)
    if index!=-1:
        print("Found at",index)
    else:
        print("Not Found")