import random

T = 100000

input_text = str(T) + "\n"
output_text = ""

with open("input.txt", "w") as f:
    f.write(input_text)
with open("output.txt", "w") as f:
    f.write(output_text)

for t in range(T):
    print(t)
    a = ""
    no_digits = 1000
    for _ in range(no_digits):
        a += str(random.randint(0, 9))
    with open("input.txt", "a") as f:
        f.write(str(a) + "\n")
    with open("output.txt", "a") as f:
        f.write("C" if int(a) % 11 == 0 else "K")
        f.write("\n")
