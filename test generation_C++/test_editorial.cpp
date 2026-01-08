#include <chrono>
#include <cstdlib>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

// === Header of file ===

bool customCompareLines(const string& line_program_output, const string& line_output, const string& line_input) {
   string line_program_output_lower = line_program_output;
   transform(line_program_output_lower.begin(), line_program_output_lower.end(), line_program_output_lower.begin(), ::tolower);
   stringstream ss1(line_program_output_lower);
   string line_output_lower = line_output;
   transform(line_output_lower.begin(), line_output_lower.end(), line_output_lower.begin(), ::tolower);
   stringstream ss2(line_output_lower);
   double a_po_base, b_po_base, c_po_base, d_po_base;
   int a_po_exp, b_po_exp, c_po_exp, d_po_exp;
   scanf("%lfe%d %lfe%d %lfe%d %lfe%d", &a_po_base, &a_po_exp, &b_po_base, &b_po_exp, &c_po_base, &c_po_exp, &d_po_base, &d_po_exp);
   double a_o_base, b_o_base, c_o_base, d_o_base;
   int a_o_exp, b_o_exp, c_o_exp, d_o_exp;
   scanf("%lfe%d %lfe%d %lfe%d %lfe%d", &a_o_base, &a_o_exp, &b_o_base, &b_o_exp, &c_o_base, &c_o_exp, &d_o_base, &d_o_exp);

   // Compare number by number

   if (
      a_po_base != a_o_base ||
      b_po_base != b_o_base ||
      c_po_base != c_o_base ||
      d_po_base != d_o_base ||
      a_po_exp != a_o_exp ||
      b_po_exp != b_o_exp ||
      c_po_exp != c_o_exp ||
      d_po_exp != d_o_exp 
   ) {
      printf("WRONG ANSWER: Error more than threshold.");
      printf("Input: %s\n", line_input.c_str());
      printf("Output: %s\n", line_program_output.c_str());
      return false;
   }
   return true;
}

// === Footer of file ===

bool compareFiles(const string& program_output, const string& output, const string& input) {
   ifstream f1(program_output);
   ifstream f2(output);
   ifstream fi(input);

   if (!f1.is_open() || !f2.is_open() || !fi.is_open()) {
      return false;
   }

   string line_program_output, line_output, line_input;
   getline(fi, line_input);
   while (getline(f1, line_program_output) && getline(f2, line_output) && getline(fi, line_input)) {
      if (!customCompareLines(line_program_output, line_output, line_input)) {
         return false;
      }
   }

   if (getline(f1, line_program_output) || getline(f2, line_output)) {
      cout << "File length mismatch" << endl;
      return false;
   }

   return true;
}

void printFileContents(const string& filename) {
   ifstream file(filename);
   if (file.is_open()) {
      string line;
      while (getline(file, line)) {
         cout << line << endl;
      }
   }
}

void grade_program(
   const string& program_file,
   const string& input_file = "input.txt",
   const string& expected_output_file = "output.txt"
) {
   // Determine compiler based on file extension
   string compiler;
   if (program_file.find(".cpp") != string::npos) {
      compiler = "g++";
   } else if (program_file.find(".c") != string::npos) {
      compiler = "gcc";
   } else {
      cout << "Unsupported file type. Please provide a .c or .cpp file." << endl;
      return;
   }

   string executable = "editorial";
#ifdef _WIN32
   executable += ".exe";
#endif

   // Step 1: Compile the program
   string compile_cmd = compiler + " " + program_file + " -o " + executable;
   cout << "Compiling: " << compile_cmd << endl;

   int compile_result = system(compile_cmd.c_str());
   if (compile_result != 0) {
      cout << "Compilation failed." << endl;
      return;
   }
   cout << "Compilation successful." << endl;

   // Step 2: Run the program with input.txt
   string run_cmd;
#ifdef _WIN32
   run_cmd = executable + " < " + input_file + " > program_output.txt";
#else
   run_cmd = "./" + executable + " < " + input_file + " > program_output.txt";
#endif
   cout << "Running: " << run_cmd << endl;

   auto start_time = chrono::high_resolution_clock::now();
   int run_result = system(run_cmd.c_str());
   auto end_time = chrono::high_resolution_clock::now();
   chrono::duration<double> run_time = end_time - start_time;
   if (run_result != 0) {
      cout << "Execution failed." << endl;
      return;
   }
   cout << "Execution successful. Time taken: " << run_time.count() << " seconds." << endl;

   

   // Step 3: Compare output with expected output
   if (compareFiles("program_output.txt", expected_output_file, input_file)) {
      cout << "ACCEPTED" << endl;
   } else {
      cout << "WRONG ANSWER" << endl;
   }
}

int main(int argc, char* argv[]) {
   if (argc < 2) {
      cout << "Usage: " << argv[0] << " <program.c|program.cpp>" << endl;
      return 1;
   }

   string program_file = argv[1];
   grade_program(program_file);

   return 0;
}
