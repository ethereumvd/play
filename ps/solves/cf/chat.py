def find_completion_days(test_cases):
    results = []
    for n, a, b, c in test_cases:
        sum3 = a + b + c
        full_cycles = (n - 1) // sum3  # Full 3-day cycles completed
        days_so_far = full_cycles * 3
        remaining_distance = n - full_cycles * sum3
        
        # Simulate the days in the current cycle
        if remaining_distance <= a:
            results.append(days_so_far + 1)
        elif remaining_distance <= a + b:
            results.append(days_so_far + 2)
        else:
            results.append(days_so_far + 3)
    
    return results

# Input Handling
t = int(input())
test_cases = [tuple(map(int, input().split())) for _ in range(t)]
results = find_completion_days(test_cases)
print("\n".join(map(str, results)))

