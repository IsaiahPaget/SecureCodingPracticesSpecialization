#include <cstdlib>
#include <iostream>

// for the love of god don't run this program
int main() {
   const char* newPath = "/usr/local/bin:/sbin:/bin:/usr/bin";
   if (setenv("PATH", newPath, 1) == 0)
       std::cout << "The PATH environment variable has been set to: " << newPath << '\n';
   else
       std::cout << "Failed to set the PATH environment variable.\n";
   return 0;
}
