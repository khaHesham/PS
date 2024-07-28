'''
Problem statement
You have been given an array/list 'ARR' consisting of 'N' integers. Your task is to find the majority element in the array. If there is no majority element present, print -1.

Note:
A majority element is an element that occurs more than floor('N' / 2) times in the array.
'''


from math import *
from collections import *
from sys import *
from os import *

def findMajorityElement(arr, n):
	
	threshold = n // 2

	freq = defaultdict(int)

	for num in arr:
		freq[num] += 1

	for key,value in freq.items():
		if value > threshold:
			return key

	return -1
