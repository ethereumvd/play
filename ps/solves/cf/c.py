def construct_permutation(n):
    if n % 2 == 0:
        return [-1]
    
    perm = [2, 1] + list(range(n, 2, -1))
    return perm


def main():
    t = int(input())
    results = []
    for _ in range(t):
        n = int(input())
        results.append(" ".join(map(str, construct_permutation(n))))
    
    print("\n".join(results))

if __name__ == "__main__":
    main()
