def find_completion_day(t, test_cases):
    results = []
    for n, a, b, c in test_cases:
        total_per_cycle = a + b + c
        full_cycles = n // total_per_cycle
        distance_after_full_cycles = full_cycles * total_per_cycle
        remaining_distance = n - distance_after_full_cycles
        
        if remaining_distance <= 0:
            # Completed at the end of the last full cycle
            results.append(full_cycles * 3)
        else:
            # Check how many more days are needed
            if remaining_distance <= a:
                results.append(full_cycles * 3 + 1)
            elif remaining_distance <= a + b:
                results.append(full_cycles * 3 + 2)
            else:
                results.append(full_cycles * 3 + 3)
    
    return results

# Example usage:
t = int(input())
test_cases = [tuple(map(int, input().split())) for _ in range(t)]
results = find_completion_day(t, test_cases)
for result in results:
    print(result)
