# Recursive Solution
def solveR(N, command, i = 0, vars = {}, output = []):
    while i < len(command):
        if '{' == command[i]:
            i = solveR(command, i + 1, vars.copy(), output)
            continue

        if '}' == command[i]:
            return i + 1

        carr = command[i].split(" ")
        if carr[0] == 'print':
            v = carr[1] # variable to print
            output.append(vars[v] if v in vars.keys() else 'undefined')

        if carr[0] == 'assign':
            v = carr[1] # variable to print
            vVal = carr[2] # value of variable
            vars[v] = vVal
        i += 1

    return output

def removeElems(vars, depth):
  toPop = []
  for i in vars.keys():
    if len(i) > depth:
      vars.pop()
    elif len(i) == 1:
      toPop.append(i)

  for i in toPop:
    vars.pop(i)

# Iterative Solution
def solve(N, command):
  output = []
  vars = [{}]
  depth = 0
  i = 0

  while i < len(command):
    # print("Loop ", i)
    if '{' == command[i]:
      depth += 1
      vars.append(vars[depth-1].copy())

    elif '}' == command[i]:
      vars.pop(depth)
      depth -= 1

    else:
      carr = command[i].split(" ")
      if carr[0] == 'print':
          v = carr[1] # variable to print
          output.append(vars[depth][v] if v in vars[depth].keys() else 'undefined')

      if carr[0] == 'assign':
          v = carr[1] # variable to print
          vVal = carr[2] # value of variable
          vars[depth][v] = vVal

    i += 1

  return output

N = 11
command = '''assign a 1
{
assign b 2
{
assign a 3
print a
}
print b
print a
print c
}'''.split("\n")

out_ = solve(N, command)
print("\n".join(out_))
