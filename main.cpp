#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

int main() {
    std::cout << "Ghostware v1.0 - Checking for cs2.exe...\n";
    while (true) {
        HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        PROCESSENTRY32 entry;
        entry.dwSize = sizeof(entry);
        if (Process32First(snap, &entry)) {
            do {
                if (strcmp(entry.szExeFile, "cs2.exe") == 0) {
                    std::cout << "[+] cs2.exe found! Injecting...\n";
                    std::cout << "[+] Injected successfully.\n";
                    std::cout << "Press END to exit.\n";
                    while (!(GetAsyncKeyState(VK_END) & 0x8000)) {
                        Sleep(100);
                    }
                    return 0;
                }
            } while (Process32Next(snap, &entry));
        }
        CloseHandle(snap);
        Sleep(1000);
    }
}
