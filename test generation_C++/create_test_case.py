import random

T = 200000

input_text = str(T) + "\n"
output_text = ""
    
for t in range(T):
    a = random.randint(100000000, 999999999)
    input_text += str(a) + "\n"
    output_text += "Y" if a % 11 == 0 else "N"
    output_text += "\n"
    

with open("input.txt", "w") as f:
    f.write(input_text)
with open("output.txt", "w") as f:
    f.write(output_text)