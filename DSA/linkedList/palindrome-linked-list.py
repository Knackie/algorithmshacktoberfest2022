#Output returns True if the linked list is palindrome else returns False
class ListNode:
   def __init__(self, data, next = None):
      self.data = data
      self.next = next

def make_list(elements):
   head = ListNode(elements[0])
   for element in elements[1:]:
      ptr = head
      while ptr.next:
         ptr = ptr.next
      ptr.next = ListNode(element)
   return head

class Solution(object):
   def isPalindrome(self, head):
      fast,slow = head,head
      rev = None
      flag = 1
      if not head:
         return True
      while fast and fast.next:
         if not fast.next.next:
            flag = 0
            break
         fast = fast.next.next
         temp = slow
         slow = slow.next
         temp.next = rev
         rev = temp
      #print(fast.val)
      fast = slow.next
      slow.next = rev
      if flag:
         slow = slow.next
      while fast and slow:
         if fast.data != slow.data:
            return False
         fast = fast.next
         slow = slow.next
      return True

head = make_list([1,2,3,2,1])
ob1 = Solution()
print(ob1.isPalindrome(head))
