class Solution(object):
  def decodeString(self, s):
    stack = []
    currentNum = 0
    currentString = ''
    # 1 [ => currentString, currentNum,
    # 2 ] => stack.pop() num / stack.pop() str
    # currentString = str + currentString * num
    # 3 ef: currentString += c
    # 4 3,2 c.isdigit(): currentNum = currentNum*10 + int(c)
    for c in s:
      if c.isdigit():
        currentNum = currentNum*10 + int(c)
      elif c == '[':
        stack.append(currentString)
        stack.append(currentNum)
        currentString = ''
        currentNum = 0
      elif c == ']':
        num = stack.pop()
        lastString = stack.pop()
        currentString = lastString + currentString * num
      else:
        currentString += c
    return currentString
