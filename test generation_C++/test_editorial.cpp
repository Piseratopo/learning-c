#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

bool compareFiles(const string& file1, const string& file2) {
   ifstream f1(file1);
   ifstream f2(file2);
   
   if (!f1.is_open() || !f2.is_open()) {
      return false;
   }
   
   string line1, line2;
   while (getline(f1, line1) && getline(f2, line2)) {
      if (line1 != line2) {
         return false;
      }
   }
   
   // Check if one file has more lines than the other
   if (getline(f1, line1) || getline(f2, line2)) {
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

void grade_program(const string& program_file, const string& input_file = "input.txt", 
               const string& expected_output_file = "output.txt") {
   // Determine compiler based on file extension
   string compiler;
   if (program_file.find(".c") != string::npos) {
      compiler = "gcc";
   } else if (program_file.find(".cpp") != string::npos) {
      compiler = "g++";
   } else {
      cout << "Unsupported file type. Please provide a .c or .cpp file." << endl;
      return;
   }
   
   string executable = "editorial.exe";
   
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
   string run_cmd = ".\\" + executable + " < " + input_file + " > program_output.txt";
   cout << "Running: " << run_cmd << endl;
   
   int run_result = system(run_cmd.c_str());
   if (run_result != 0) {
      cout << "Execution failed." << endl;
      return;
   }
   cout << "Execution successful." << endl;
   
   // Step 3: Compare output with expected output
   if (compareFiles("program_output.txt", expected_output_file)) {
      cout << "ACCEPTED: Output matches expected output." << endl;
   } else {
      cout << "WRONG ANSWER: Output does not match expected output." << endl;
      
      // Show differences
      cout << "\n--- Program Output ---" << endl;
      printFileContents("program_output.txt");
      
      cout << "\n--- Expected Output ---" << endl;
      printFileContents(expected_output_file);
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
