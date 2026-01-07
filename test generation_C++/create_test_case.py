import random
from decimal import Decimal

T = 1000

input_text = str(T) + "\n"
output_text = ""

for t in range(T):
    # print(t)
    choice = random.randint(0, 1)
    if choice == 0:
        a = Decimal(random.randint(-100000, 100000)) / Decimal(100)
        b = a
        c = Decimal(random.randint(-1000, 1000)) / Decimal(100)
        input_text += f"{a} {b} {c}\n"
        output_text += f"Vô nghiệm\n"
    elif choice == 1:
        a = Decimal(random.randint(-100000, 100000)) / Decimal(100)
        b = Decimal(random.randint(-100000, 100000)) / Decimal(100)
        if a == b:
            b += Decimal(1)
        c = -1
        input_text += f"{a} {b} {c}\n"
        output_text += f"Vô nghiệm\n"
    elif choice == 2:
        a = Decimal(random.randint(-100000, 100000)) / Decimal(100)
        b = a
        c = -1
        input_text += f"{a} {b} {c}\n"
        output_text += "_\n"
    else:
        a = Decimal(random.randint(-100000, 100000)) / Decimal(100)
        b = Decimal(random.randint(-100000, 100000)) / Decimal(100)
        if a == b:
            b += 1
        c = -100
        while c == -100:
            c = Decimal(random.randint(-1000, 1000))
        c = c / Decimal(100)
        input_text += f"{a} {b} {c}\n"
        output_text += "_\n"

with open("input.txt", "w", encoding="utf-8") as f:
    f.write(input_text)

with open("output.txt", "w", encoding="utf-8") as f:
    f.write(output_text)
