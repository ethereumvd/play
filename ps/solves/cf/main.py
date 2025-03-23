for _ in range(int(input())):
    x, y = map(int, input().split())
    z = 1 << max(x, y).bit_length()
    k = z - max(x, y)
    if (x == y):
        print("-1")
        continue
    print(k)
