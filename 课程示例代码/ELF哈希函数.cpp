#include <iostream>  

#define M 256  

int ELFhash(const char* key) {
    unsigned long h = 0;
    while (*key) {
        h = (h << 4) + *key++; // ��h����4λ������16���������ϵ�ǰ�ַ���ASCIIֵ  
        unsigned long g = h & 0xF0000000L; // ��ȡh�����8λ������24λ����31λ��  
        if (g) h ^= g >> 24; // ���g��Ϊ0����h�����8λ��g�����8λ������24λ�󣩽���������  
        h &= ~g; // ���h�����8λ
    }
    return h % M;
}

int main() {
    const char* testKey = "hello";
    int hashValue = ELFhash(testKey);
    printf("Hash value of '%s' is %d\n", testKey, hashValue);
    return 0;
}