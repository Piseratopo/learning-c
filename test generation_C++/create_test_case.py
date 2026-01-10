import random
from decimal import Decimal, getcontext

getcontext().prec = 28

T = 200000

input_text = str(T) + "\n"
output_text = ""

for t in range(T):
    # print(t)
    x_base = Decimal(random.randint(1000, 9999)) / Decimal('1000')
    
    y_base = Decimal(random.randint(1000, 9999)) / Decimal('1000')
    choice = random.randint(1, 5)
    if choice < 5:
        x_exp = random.randint(-96, 96)
        y_exp = x_exp + random.randint(-3, 3)
    else:
        x_exp = random.randint(-99, 99)
        y_exp = random.randint(-99, 99)

    # x_base, x_exp, y_base, y_exp = 5, 3, 2, 2
    
    input_text += f"{x_base}e{x_exp} {y_base}e{y_exp}\n"
    
    x = float(x_base) * (10 ** x_exp)
    y = float(y_base) * (10 ** y_exp)
    
    output_text += f"{x + y:e} {x - y:e} {x * y:e} {x / y:e}\n"

with open("input.txt", "w", encoding="utf-8") as f:
    f.write(input_text)

with open("output.txt", "w", encoding="utf-8") as f:
    f.write(output_text)
