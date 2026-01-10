import subprocess
import sys
import os
import filecmp
import re

def compare_file(input_f, output_f, expected_f):
   with open(input_f, 'r') as f:
      input_lines = f.readlines()
   with open(output_f, 'r') as f:
      output_lines = f.readlines()
   with open(expected_f, 'r') as f:
      expected_lines = f.readlines()

   if len(output_lines) != len(expected_lines):
      print("Incorrect line count.")
      return False
   
   for i in range(len(output_lines)):
      output = output_lines[i].strip().split()
      if len(output) != 4:
         print(f"Line {i+1}: Output value '{item}' should have 4 values.")
         return False

      parsed_output = []
      for item in output:
         match = re.match(r'^(-?\d+\.?\d*)[eE]([+-]?\d+)$', item)
         if match:
            a = float(match.group(1))
            b = int(match.group(2))
            parsed_output.append((a, b))
         else:
            print(f"Line {i+1}: Output value '{item}' is not in the expected scientific notation format.")
            return False

      expected = expected_lines[i].strip() .split()
      parsed_expected = []
      for item in expected:
         match = re.match(r'^(-?\d+\.?\d*)[eE]([+-]?\d+)$', item)
         a = float(match.group(1))
         b = int(match.group(2))
         parsed_expected.append((a, b))
      
      for j in range(len(parsed_output)):
         out_base, out_exp = parsed_output[j]
         exp_base, exp_exp = parsed_expected[j]

         first_check = abs(out_base - exp_base) > 1e-3 or out_exp != exp_exp
         second_check = abs(out_base * 10 - exp_base) > 1e-3 or out_exp - 1 != exp_exp
         third_check = abs(out_base / 10 - exp_base) > 1e-3 or out_exp + 1 != exp_exp
         if first_check and second_check and third_check:
            print(f"Line {i+1}: Input value '{input_lines[i].strip()}' does not match with the expected value '{expected_lines[i].strip()}': Output value '{output_lines[i].strip()}'.")
            return False
   return True
      

def grade_program(program_file, input_file="input.txt", expected_output_file="output.txt"):
   # Determine compiler based on file extension
   if program_file.endswith(".c"):
      compiler = "gcc"
   elif program_file.endswith(".cpp"):
      compiler = "g++"
   else:
      print("Unsupported file type. Please provide a .c or .cpp file.")
      return
   
   executable = "editorial.exe"  # default output name
   
   # Step 1: Compile the program
   try:
      subprocess.run([compiler, program_file, "-o", executable], check=True)
      print("Compilation successful.")
   except subprocess.CalledProcessError:
      print("Compilation failed.")
      return
   
   # Step 2: Run the program with input.txt
   try:
      with open(input_file, "r") as infile, open("program_output.txt", "w") as outfile:
         subprocess.run([f"./{executable}"], stdin=infile, stdout=outfile, check=True)
      print("Execution successful.")
   except subprocess.CalledProcessError:
      print("Execution failed.")
      return
   
   # Step 3: Compare output with expected output
   if compare_file(input_file, "program_output.txt", expected_output_file):
       print("All test passed!")
   else:
       print("Test failed.")
  

if __name__ == "__main__":
   if len(sys.argv) < 2:
      print("Usage: python test_editorial.py <program.c|program.cpp>")
   else:
      grade_program(sys.argv[1])
