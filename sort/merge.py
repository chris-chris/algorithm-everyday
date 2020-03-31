def merge_sort(arr, start, end):
    """
    merge sort form index start ~ end
    """
    if len(arr) <= 1:
        return
    if start >= end:
        return

    mid = int((start + end) / 2)
    merge_sort(arr, start, mid)
    merge_sort(arr, mid+1, end)
    merging(arr, start, mid, mid+1, end)


def merging(arr, s1, e1, s2, e2):
    """
    merging two arrays in ascending order
    """
    p1 = s1
    p2 = s2
    tmp = [0 for _ in range(len(arr))]
    idx = s1

    while p1 <= e1 and p2 <= e2:
        if arr[p1] < arr[p2]:
            tmp[idx] = arr[p1]
            idx += 1
            p1 += 1
        else:
            tmp[idx] = arr[p2]
            idx += 1
            p2 += 1

    if p1 <= e1:
        for i in range(p1, e1+1):
            tmp[idx] = arr[p1]
            idx += 1
            p1 += 1
    else:
        for i in range(p2, e2+1):
            tmp[idx] = arr[p2]
            idx += 1
            p2 += 1

    for i in range(s1, e2+1):
        arr[i] = tmp[i]

    # done


arr = [5, 2, 1, 0, 4]
merge_sort(arr, 0, len(arr)-1)
print(arr)
