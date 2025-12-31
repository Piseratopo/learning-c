import random

# Step 1: Generate a random number N
N = random.randint(10, 999999)  # ensure at least 2 digits

# Step 2: Write N to input.txt
with open("input.txt", "w") as f:
    f.write(str(N))

# Step 3: Create M by moving the last digit of N to the front
N_str = str(N)
M_str = N_str[-1] + N_str[:-1]
M = int(M_str)

# Step 4: Find the positive difference between N and M
difference = abs(N - M)

# Step 5: Write the difference to output.txt
with open("output.txt", "w") as f:
    f.write(str(difference))

print(f"N = {N}, M = {M}, |N - M| = {difference}")