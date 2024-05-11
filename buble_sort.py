def bubbleSort(array):
    for i in range(len(array)):
        for j in range(0, len(array) - i - 1):
            if array[j] > array[j + 1]:
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp

n = int(input("Enter the size of array: "))
data = []
print("Enter the elements of the array: ")

for _ in range(n):
    element = int(input())
    data.append(element)

bubbleSort(data)

print('Sorted Array in Ascending Order:')
print(data)
