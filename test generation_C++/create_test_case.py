import random
from decimal import Decimal

T = 1000

input_text = str(T) + "\n"
output_text = ""

for t in range(T):
    # print(t)
    choice = random.randint(0, 10)
    if choice == 0:
        a = Decimal(random.randint(-50000, 50000)) / Decimal(100)
        b = a
        c = Decimal(random.randint(-50000, 50000)) / Decimal(100)
        input_text += f"{a} {b} {c}\n"
        output_text += f"Vô nghiệm\n"
    elif choice == 1:
        a = Decimal(random.randint(-50000, 50000)) / Decimal(100)
        b = Decimal(random.randint(-50000, 50000)) / Decimal(100)
        c = -1
        input_text += f"{a} {b} {c}\n"
        output_text += f"Vô nghiệm\n"
    else:
        x = Decimal(random.randint(-50000, 50000)) / Decimal(100)
        y = Decimal(random.randint(-50000, 50000)) / Decimal(100)
        z = Decimal(random.randint(-50000, 50000)) / Decimal(100)

        a = x + y
        b = y - z
        c = Decimal(round(z / x, 4))

        x = (a - b) / (c + Decimal("1.0"))
        y = (a * c + b) / (c + Decimal("1.0"))
        z = (a - b) * c / (c + Decimal("1.0"))

        input_text += f"{a} {b} {c}\n"
        output_text += f"{x} {y} {z}\n"

with open("input.txt", "w", encoding="utf-8") as f:
    f.write(input_text)

with open("output.txt", "w", encoding="utf-8") as f:
    f.write(output_text)
