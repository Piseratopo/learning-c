#define _USE_MATH_DEFINES // For M_PI on Windows
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
   int freq = 100;
   int duration = 1000;
   int sample_rate = 44100;
   int num_samples = duration * sample_rate / 1000;
   short int *samples = malloc(num_samples * sizeof(short int));
   int amplitude = 32767;
   
   // Generate samples
   for (int i = 0; i < num_samples; i++) {
      samples[i] = (short int)(amplitude * sin(2 * M_PI * i * freq / sample_rate));
   }
   
   // Proper WAV header
   int byte_rate = sample_rate * 2; // 16-bit samples
   int data_size = num_samples * 2;
   int file_size = 36 + data_size;
   
   fwrite("RIFF", 1, 4, stdout);
   fwrite(&file_size, 4, 1, stdout);
   fwrite("WAVE", 1, 4, stdout);
   fwrite("fmt ", 1, 4, stdout);
   fwrite("\x10\x00\x00\x00", 1, 4, stdout); // fmt chunk size
   fwrite("\x01\x00", 1, 2, stdout); // PCM format
   fwrite("\x01\x00", 1, 2, stdout); // mono
   fwrite(&sample_rate, 4, 1, stdout);
   fwrite(&byte_rate, 4, 1, stdout);
   fwrite("\x02\x00", 1, 2, stdout); // block align
   fwrite("\x10\x00", 1, 2, stdout); // bits per sample
   fwrite("data", 1, 4, stdout);
   fwrite(&data_size, 4, 1, stdout);
   
   fwrite(samples, sizeof(short int), num_samples, stdout);
   free(samples);
   return 0;
}