from math import *
from collections import *
from sys import *
from os import *

"""***************************************************************

    Following is the class structure of the LinkedListNode class:

    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None


*****************************************************************"""


def reverseLinkedList(head):
    # Write your code here.
    curr = head
    prev = None
    next = None

    if curr is None:
        return

    # reverse main loop
    while curr:
        next = curr.next
        curr.next = prev
        prev = curr

        curr = next

    head = prev

    return head

