def bubbleSort(arr):
    for i in range(1, len(arr)):
        for j in range(0, len(arr)-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def main():
    arr = [64, 34, 25, 12, 22, 11, 90]
    sorted_arr = bubbleSort(arr)
    print("Sorted array is:")
    for i in range(len(sorted_arr)):
        print("%d" % sorted_arr[i])

if __name__ == "__main__":
    main()