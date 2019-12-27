def solve(pos, end, path, lis=[]):
    lis.append(pos)
    if pos == end:
        return [pos]
    ret, h = [pos], len(path)
    w = len(path[0]) if h else 0
    if pos[0] < w - 1 and path[pos[1]][pos[0]+1] != '*' and (pos[0]+1, pos[1])\
       not in lis:
        temp = solve((pos[0]+1, pos[1]), end, path, lis)
        if temp:
            return ret + temp
    if pos[1] < h - 1 and path[pos[1]+1][pos[0]] != '*' and (pos[0], pos[1]+1)\
       not in lis:
        temp = solve((pos[0], pos[1]+1), end, path, lis)
        if temp:
            return ret + temp
    if pos[0] >= 1 and path[pos[1]][pos[0]-1] != '*' and (pos[0]-1, pos[1])\
       not in lis:
        temp = solve((pos[0]-1, pos[1]), end, path, lis)
        if temp:
            return ret + temp
    if pos[1] >= 1 and path[pos[1]-1][pos[0]] != '*' and (pos[0], pos[1]-1)\
       not in lis:
        temp = solve((pos[0], pos[1]-1), end, path, lis)
        if temp:
            return ret + temp
    lis.pop()
    return []


print(*solve(
    (3, 0),
    (3, 5),
    [
        [' ', ' ', ' ', ' ', '*', '*'],
        [' ', '*', '*', '*', '*', '*'],
        [' ', ' ', '*', ' ', '*', '*'],
        ['*', ' ', ' ', ' ', ' ', '*'],
        ['*', '*', ' ', '*', ' ', ' '],
        ['*', '*', ' ', ' ', ' ', '*']
    ]
))
