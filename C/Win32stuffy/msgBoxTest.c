#include <windows.h>

int main(void) {
   MessageBoxW(
     NULL,
     L"My first message box!",
     L"Hello World!",
     MB_YESNOCANCEL

   );
   return EXIT_SUCCESS;
}
