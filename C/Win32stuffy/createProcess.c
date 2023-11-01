//creates process for mspaint

#include <windows.h>
#include <stdio.h>
int main(void){
/*
BOOL CreateProcessW(
  [in, optional]      LPCWSTR               lpApplicationName,
  [in, out, optional] LPWSTR                lpCommandLine,
  [in, optional]      LPSECURITY_ATTRIBUTES lpProcessAttributes,
  [in, optional]      LPSECURITY_ATTRIBUTES lpThreadAttributes,
  [in]                BOOL                  bInheritHandles,
  [in]                DWORD                 dwCreationFlags,
  [in, optional]      LPVOID                lpEnvironment,
  [in, optional]      LPCWSTR               lpCurrentDirectory,
  [in]                LPSTARTUPINFOW        lpStartupInfo,
  [out]               LPPROCESS_INFORMATION lpProcessInformation
);
*/
STARTUPINFOW si;
PROCESS_INFORMATION pi;

  if (!CreateProcessW(L"C://Windows//System32//notepad.exe", NULL,
  NULL, NULL, FALSE,
  BELOW_NORMAL_PRIORITY_CLASS,
  NULL, NULL, &si,
  &pi)){

    printf("(-) failed to create process, error: %ld", GetLastError());
    //getlasterror function
    return EXIT_FAILURE;
    return
  }

  printf("(+) process started! pid: %ld", pi.dwProcessId);
  //verify with processhacker tool
  return EXIT_SUCCESS;
}
