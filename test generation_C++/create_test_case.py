import random

T = 1000

input_text = str(T) + "\n"
output_text = ""

for t in range(T):
    # print(t)
    x = random.randint(1, 1000)
    y = random.randint(1, 1000)
    c = random.randint(1, 1000)
    input_text += f"{a} {b} {c}\n"
    if a == b or c == -1:
        output_text += "Vô nghiệm\n"
        continue

    x = (a - b) / (c + 1)
    y = (a * c + b) / (c + 1)
    z = (a - b) * c / (c + 1)
    output_text += f"{round(x, 4)} {round(y, 4)} {round(z, 4)}\n"

with open("input.txt", "w") as f:
    f.write(input_text)

with open("output.txt", "w") as f:
    f.write(output_text)
