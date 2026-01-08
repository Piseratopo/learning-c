import random
from decimal import Decimal

T = 10

input_text = str(T) + "\n"
output_text = ""

for t in range(T):
    # print(t)
    x_base = Decimal(random.randint(1000, 9999)) / Decimal(1000)
    x_exp = Decimal(random.randint(-99, 99))
    y_base = Decimal(random.randint(1000, 9999)) / Decimal(1000)
    y_exp = Decimal(random.randint(-99, 99))
    
    input_text += f"{x_base}e{x_exp} {y_base}e{y_exp}\n"
    
    x = x_base * Decimal(10) ** x_exp
    y = y_base * Decimal(10) ** y_exp
    
    output_text += f"{x + y:.3e} {x - y:.3e} {x * y:.3e} {x / y:.3e}\n"

with open("input.txt", "w", encoding="utf-8") as f:
    f.write(input_text)

with open("output.txt", "w", encoding="utf-8") as f:
    f.write(output_text)
