import random
from decimal import Decimal, getcontext

getcontext().prec = 28

input_text = ""
output_text = ""

a = random.randint(0, 0)
b = random.randint(0, 9)
c = random.randint(0, 99)

input_text = f"+{a} ({b})-{c}\n"
output_text = f"0{a:03d} {b:03d} {c:03d}\n"

with open("input.txt", "w", encoding="utf-8") as f:
    f.write(input_text)

with open("output.txt", "w", encoding="utf-8") as f:
    f.write(output_text)
