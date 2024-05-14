def bubbleSort1(arr):
    for i in range(1, len(arr)):
        for j in range(0, len(arr)-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def bubbleSort(array):
    for i in range(0, len(array) - 1):
        for j in range(0, len(array) - i - 1):
            if array[j] < array[j+1]:
                array[j], array[j + 1] = array[j + 1], array[j]
    return array

def bubbleSort2(array):
    for i in range(1, len(array)):
        for j in range(0, len(array) - i):
            if array[j] < array[j+1]:
                array[j], array[j + 1] = array[j + 1], array[j]
    return array


def main():
    arr = [3, 6, 25]
    sorted_arr = bubbleSort(arr)
    print("Sorted array is:")
    for i in range(len(sorted_arr)):
        print("%d" % sorted_arr[i])

if __name__ == "__main__":
    main()


