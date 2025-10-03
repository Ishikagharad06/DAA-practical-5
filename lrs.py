def LRS(a, b):
    n = len(a)
    m = len(b)
    c = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i - 1] == b[j - 1] and i != j:
                c[i][j] = 1 + c[i - 1][j - 1]
            else:
                c[i][j] = max(c[i - 1][j], c[i][j - 1])
    i, j = n, m
    lrs_subsequence = []
    while i > 0 and j > 0:
        if a[i - 1] == b[j - 1] and i != j:
            lrs_subsequence.append(a[i - 1])
            i -= 1
            j -= 1
        elif c[i - 1][j] >= c[i][j - 1]:
            i -= 1
        else:
            j -= 1
    lrs_subsequence.reverse()
    return ''.join(lrs_subsequence), c[n][m]

a = "AABCBDC"
b = a
lrs_subsequence, length = LRS(a, b)
print(f"Longest Repeated Subsequence: {lrs_subsequence}")
print(f"Length of LRS: {length}")