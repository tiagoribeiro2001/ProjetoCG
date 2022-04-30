import math
import sys

x = float(sys.argv[1])
y = float(sys.argv[2])
z = float(sys.argv[3])
r = float(math.pi/4)
for i in range(0,8):
    new_x = str(math.cos(r*i)*x)
    new_y = str(math.sin(r*i)*y)
    new_z = str(-(math.sin(r*i)*z))
    print("<point x=\"" + new_x + "\" y=\"" + new_y + "\" z=\"" + new_z + "\"/>")