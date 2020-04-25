## template
from collections import deque
s = input()
n = len(s)

stack = deque()

def solve():

  for i in range(n):
    c = s[i]
    if c=='(' or c=='[':
      stack.append(c)
    else:
      if len(stack) >= 1 and c==')' and stack[-1] == '(':
        stack.pop()
        stack.append(2)
      elif len(stack) >= 1 and c==']' and stack[-1] == '[':
        stack.pop()
        stack.append(3)
      elif len(stack) >= 2 and c==')' and stack[-1] > 0 and stack[-2] == '(':
        num = stack[-1]
        stack.pop()
        stack.pop()
        stack.append(num*2)
      elif len(stack) >= 2 and c==']' and stack[-1] > 0 and stack[-2] == '[':
        num = stack[-1]
        stack.pop()
        stack.pop()
        stack.append(num*3)
      else:
        print(0)
        return

      if len(stack) >= 2 \
          and type(stack[-1]) == int and stack[-1] > 0 \
          and type(stack[-2]) == int and stack[-2] > 0:
        num1 = stack.pop()
        num2 = stack.pop()
        stack.append(num1+num2)

  if(len(stack) == 1):
    print(stack[-1])
  else:
    print(0)

solve()