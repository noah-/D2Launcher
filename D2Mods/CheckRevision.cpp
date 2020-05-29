#include <Windows.h>
#include <wincrypt.h>
int __stdcall CheckRevision(CHAR* file, char* unk1, char* unk2, void* formula, char* zero, char* hash, char* base64info)
{
    DWORD formulaSize = 8;
    CryptStringToBinaryA((char*)formula, 0, CRYPT_STRING_BASE64, (BYTE*)base64info, &formulaSize, NULL, NULL);
    base64info[4] = ':';
    base64info[5] = '1';
    base64info[6] = '.';
    base64info[7] = '1';
    base64info[8] = '4';
    base64info[9] = '.';
    base64info[10] = '3';
    base64info[11] = '.';
    base64info[12] = '7';
    base64info[13] = '1';
    base64info[14] = ':';
    base64info[15] = 1;
    base64info[16] = 0;

    HCRYPTPROV hProv = NULL;
    HCRYPTHASH hHash = NULL;
    DWORD dwDataLen = 0;
    CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
    CryptCreateHash(hProv, CALG_SHA1, 0, 0, &hHash);
    CryptHashData(hHash, (const BYTE*)base64info, 16, 0);
    CryptGetHashParam(hHash, HP_HASHVAL, NULL, &dwDataLen, 0);
    CryptGetHashParam(hHash, HP_HASHVAL, (BYTE*)hash, &dwDataLen, 0);
    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);

    DWORD dwB64Length = 0;
    CryptBinaryToStringA((BYTE*)hash, 0x14, CRYPT_STRING_BASE64 | CRYPT_STRING_NOCRLF, NULL, &dwB64Length);
    CryptBinaryToStringA((BYTE*)hash, 0x14, CRYPT_STRING_BASE64 | CRYPT_STRING_NOCRLF, base64info, &dwB64Length);
    *(DWORD*)hash = *(DWORD*)base64info;
    *(DWORD*)base64info = *(DWORD*)(base64info + 4);
    *(DWORD*)(base64info + 4) = *(DWORD*)(base64info + 8);
    *(DWORD*)(base64info + 8) = *(DWORD*)(base64info + 12);
    *(DWORD*)(base64info + 12) = *(DWORD*)(base64info + 16);
    *(DWORD*)(base64info + 16) = *(DWORD*)(base64info + 20);
    *(DWORD*)(base64info + 20) = *(DWORD*)(base64info + 24);
    base64info[dwB64Length - 4] = 0;
    return 1;
}