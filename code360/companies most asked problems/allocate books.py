'''
Problem statement
Ayush is studying for ninjatest which will be held after 'N' days, And to score good marks he has to study 'M' chapters and the ith chapter requires TIME[i] seconds to study. The day in Ayush’s world has 100^100 seconds. There are some rules that are followed by Ayush while studying.

1. He reads the chapter in a sequential order, i.e. he studies i+1th chapter only after he studies ith chapter.

2. If he starts some chapter on a particular day he completes it that day itself.

3. He wants to distribute his workload over 'N' days, so he wants to minimize the maximum amount of time he studies in a day.

Your task is to find out the minimal value of the maximum amount of time for which Ayush studies in a day, in order to complete all the 'M' chapters in no more than 'N' days.

For example

if Ayush want to study 6 chapters in 3 days and the time that each chapter requires is as follows:
Chapter 1 = 30
Chapter 2 = 20
Chapter 3 = 10
Chapter 4 = 40
Chapter 5 = 5
Chapter 6 = 45

Then he will study the chapters in the following order 

| day 1 : 1 , 2 | day 2 : 3 , 4 | day 3 : 5 , 6 |
Here we can see that he study chapters in sequential order and the maximum time to study on a day is 50, which is the minimum possible in this case.
'''

from os import *
from sys import *
from collections import *
from math import *

def ayushGivesNinjatest(n, m, time):
    
    # problem is find max sum of 2 executive elements 
    
    low = max(time)   # min time he can take is one course per day
    high = sum(time)  # theoritically he can take all courses in one day

    # binary search for solution
    while low < high:
        mid = (low + high) // 2

        if canCompleteInDays(n,m,time,mid):
            # search for smaller time
            high = mid
        else:
            # try bigger time
            low = mid + 1


    return low # minimum time of study per day


def canCompleteInDays(n,m,time,maxTime):
    currentDay = 1
    currentTime = 0

    for i in range(len(time)):
        if currentTime + time[i] <= maxTime:
            currentTime += time[i]
        else:
            currentDay += 1
            currentTime = time[i]

            # check if we exceeded limit of days
            if currentDay > n:
                return False

    return True


