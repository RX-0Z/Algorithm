import random

# Quick sort 만들기 - 12/19 ~ 26일 (완료)
# 4-1 처음 나왔던 sum 함수를 작성해 보세요. (완료)
# 4-2 리스트에 포함된 원소의 숫자를 세는 재귀 함수를 작성해 보세요. (완료)
# 4-3 리스트에서 가장 큰 수를 찾아보세요. (완료)
# 4-4 1장에서 나왔던 이진탐색은 분할 정복 전략이었습니다. 이진 탐색에 대해 기본 단계와 재귀 단계를 찾을 수 있나요?

# 모두 완성한 뒤 코드 비교해보기

testArr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
result = 0

# sum function base (use loop)
def sum_base_useLoop(arr):
    total = 0

    for i in range(len(arr)):
        total += arr[i]

    return total
#print(sum_base_useLoop(testArr))

#4-1 sum
def sum_recursion(arr, total):
    total += arr[0]
    del arr[0]

    if len(arr) <= 0:
        return print(total)
    else:
        sum_recursion(arr, total)
#sum_recursion(testArr, result)

# upgrade : 마지막에 총합이 더 해지도록 만들어 보기
# version 2
def sum_recursion2(arr):
    total = 0
    total += arr[0]
    del arr[0]

    if 0 == len(arr):
        return total
    else:
        return total + sum_recursion2(arr)
#print("sum_recursion2 result :", sum_recursion2(testArr))

#4-1 teaching material version
def sum(list):
    if list == []:
        return 0
    return list[0] + sum(list[1:])

#print(sum(testArr))

# Quick Sort
# 1. 기준 원소를 고른다.
# 2. 배열을 기준 원소보다 작은 원소의 배열과 기준 원소보다 큰 원소의 배열, 이렇게 두 개의 하위 배열로 분할한다.
# 3. 하위 배열에 대해 재귀적으로 퀵 정렬을 호출한다.
def quicksort(array):
    leftArr =  [] # 피벗보다 작은 수 -> leftArr
    rightArr = [] # 피벗보다 높은 수 -> rightArr
    pivotArr = [] # 기준 원소

    print("Array : ", array)

    # 1. 기본 단계 : 비어 있는 배열, 원소가 하나인 배열은 정렬할 필요가 없다.
    if len(array) < 2:
        return array
    else:
        pivot = random.choice(array)
        pivotArr.append(pivot)
        print("pivot : ", pivotArr)
        # 2. 첫 번째 원소가 두 번째 원소보다 작은지 살펴본다. 만약 그렇지 않다면 두 원소를 교환한다.
        for i in array:
            if pivot > i:
                leftArr.append(i)
            elif pivot < i:
                rightArr.append(i)
        return quicksort(leftArr) + pivotArr + quicksort(rightArr)

#random.randrange(1, 11) #1 이상 11미만 (1 ~ 10)
#random.shuffle(testArr)
#print("Quick Sort : ", quicksort(testArr))

#4-2 리스트에 포함된 원소의 숫자를 세는 재귀 함수
def count_listSize(targetList):
    # 기본 단계
    if (1 == len(targetList)):
        return 1
    # 재귀 단계
    else:
        del targetList[0]
        return count_listSize(targetList) + 1

#print("array size : ", count_listSize(testArr))

#4-2 teaching material version
def count(list):
    if list == []:
        return 0
    return 1 + count(list[1:])

# 4-3 리스트에서 가장 큰 수를 찾기
def findMaxNum(targetList):
    maxNum = random.choice(targetList)

    for i in targetList:
        if (i >= maxNum):
            maxNum = i

    return maxNum

#print("Max :", findMaxNum(testArr))

# 4-3 리스트에서 가장 큰 수를 찾기 : 재귀 사용
def findMaxNum2(list, max):
    print("function call")
    # 기본 단계
    if (len(list) == 1):
        print("list size:", len(list))
        return max
    elif (list[0] > list[1]):
        max = list[0]
        temp = list[1]
        list[0] = temp
        list[1] = max
    else:
        max = list[1]
    # 재귀 단계
    return findMaxNum2(list[1:], max)

#4-3 teaching material version
def max(list):
    if len(list) == 2:
        return list[0] if list[0] > list[1] else list[1]
    sub_max = max(list[1:])
    return list[0] if list[0] > sub_max else sub_max

temp = 0
random.shuffle(testArr)
print(testArr)
print("Max :", findMaxNum2(testArr, temp))

# 4-4 binary_search : 이진탐색 - 분할 정복 전략
def binary_search(arr, startIndex, endIndex, findNum):
    # !배열이 정렬되어 있어야 함.
    print("function call-----")

    if (0 == len(arr)):
        print("Array is empty.")
        return -1

    if ((0 == startIndex) and (0 == endIndex)):
        endIndex = len(arr)

    mid = int((startIndex + endIndex) / 2)

    # 기본 단계
    if (arr[mid] == findNum):
        return mid
    # 재귀 단계
    else:
        if (arr[mid] > findNum):
            print("arr[mid] > findNum")
            endIndex = mid
        else:
            print("arr[mid] < findNum")
            startIndex = mid + 1
            endIndex = len(arr) - 1
        return binary_search(arr, startIndex, endIndex, findNum)

#findNum = random.choice(testArr)
#print(findNum)
#print("findNum index :", binary_search(testArr, 0, 0, findNum))