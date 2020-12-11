testCases = int(input())

for tc in range(testCases):
    n = int(input())
    v = []
    for i in range(n):
        start, end = map(int, input().split())
        v.append((start, end, i))
    v = sorted(v, key=lambda a : a[0])  # sorted according to start time

    m = {}
    m[v[0]] = "C"
    C_lastTakenActivityIndex = 0
    for i in range(1, n):
        if v[C_lastTakenActivityIndex][1] <= v[i][0]:
            m[v[i]] = "C"
            C_lastTakenActivityIndex = i

#   assigning J's first activity
    J_lastTakenActivityIndex = 0
    for i in range(1, n):
        if m.get(v[i], "NONE") == "NONE":
            J_lastTakenActivityIndex = i
            m[v[i]] = "J"
            break

    for i in range(1, n):
        if m.get(v[i], "NONE") == "NONE":
            if v[J_lastTakenActivityIndex][1] <= v[i][0]:
                m[v[i]] = "J"
                J_lastTakenActivityIndex = i

    v = sorted(v, key=lambda a : a[2])
    flag = True
    for i in range(0, n):
        if m.get(v[i], "NONE") == "NONE":
            flag = False
            break
    print(f'Case #{tc+1}: ', end="")
    if flag:
        for i in range(n):
            print(f'{m[v[i]]}', end="")
    else:
        print(f'IMPOSSIBLE', end="")
    print()
