class Solution:
  def calculate(self, s: str) -> int:
    if not s:
      return 0
    sign, num, stack = '+', 0, []
    for i, c in enumerate(s):
      if c.isdigit():
        num = num*10 + int(c)
      if (not c.isdigit() and not c.isspace()) or i == len(s)-1:
        if sign == '+':
          stack.append(num)
        elif sign == '-':
          stack.append(-num)
        elif sign == '*':
          prev = stack.pop()
          stack.append(prev*num)
        elif sign == '/':
          prev = stack.pop()
          if prev // num < 0 and prev % num != 0:
            stack.append(prev//num + 1)
          else:
            stack.append(prev//num)
        sign = c
        num = 0
    return sum(stack)