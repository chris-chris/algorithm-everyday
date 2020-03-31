def quick_sort(arr):
    """quick sort algorithm"""
    if len(arr) <= 1:
        return arr

    left = []
    right = []
    pivot = arr[0]
    for i in range(1, len(arr)):
        item = arr[i]
        if item < pivot:
            left.append(item)
        else:
            right.append(item)

    left = quick_sort(left)
    right = quick_sort(right)

    return left + [pivot] + right

arr = [1,5,2,3,0]
result = quick_sort(arr)
print(result)
