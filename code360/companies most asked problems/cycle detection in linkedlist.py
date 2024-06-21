'''
Following is the structure of the Node class already defined.

class Node :
    def __init__(self, data) :
        self.data = data
        self.next = None
'''

def detectCycle(head) :

    fast = head.next
    slow = head

    while fast is not None:

        if fast.data == slow.data:
            return True

        if fast.next:
            fast = fast.next.next
        else: 
            break
            
        slow = slow.next

    return False