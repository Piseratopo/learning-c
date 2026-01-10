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
   
   outputs = []
   expecteds = []
   
   for i in range(len(output_lines)):
      output_l = output_lines[i].strip()
      expected_l = expected_lines[i].strip()

      output = output_l.split()
      parsed_output = []
      for item in output:
         match = re.match(r'^(-?\d+\.?\d*)[eE]([+-]?\d+)$', item)
         if match:
            a = match.group(1)
            b = int(match.group(2))
            parsed_output.append((a, b))
         else:
            print(f"Line {i+1}: Output value '{item}' is not in the expected scientific notation format.")
            return False
      
      outputs.append(parsed_output)

      expected = expected_l.split()
      parse_expected = []
      for item in expected:
         match = re.match(r'^(-?\d+\.?\d*)[eE]([+-]?\d+)$', item)
         a = match.group(1)
         b = int(match.group(2))
         parse_expected.append((a, b))
      
   print(parse_output, gfd`parse_expected)
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
       print("Test passed (format check only)!")
   else:
       print("Test failed.")
  

if __name__ == "__main__":
   if len(sys.argv) < 2:
      print("Usage: python test_editorial.py <program.c|program.cpp>")
   else:
      grade_program(sys.argv[1])
