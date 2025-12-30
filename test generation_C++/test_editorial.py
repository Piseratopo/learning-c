import subprocess
import sys
import os
import filecmp

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
   if filecmp.cmp("program_output.txt", expected_output_file, shallow=False):
      print("✅ Output matches expected output.")
   else:
      print("❌ Output does not match expected output.")
      # Show differences
      with open("program_output.txt") as f1, open(expected_output_file) as f2:
         print("\n--- Program Output ---")
         print(f1.read())
         print("\n--- Expected Output ---")
         print(f2.read())

if __name__ == "__main__":
   if len(sys.argv) < 2:
      print("Usage: python grader.py <program.c|program.cpp>")
   else:
      grade_program(sys.argv[1])
