#include <stdio.h>
#include <stdint.h>

uint32_t read_and_convert_number(FILE* file) {
    uint32_t num;

    if (fread(&num, sizeof(uint32_t), 1, file) != 1) {
        printf("Error reading from file.\n");
        return 0;
    }

    // byte order를 변환하여 값을 반환합니다.
    return ((num >> 24) & 0xFF) | ((num >> 8) & 0xFF00) | ((num << 8) & 0xFF0000) | ((num << 24) & 0xFF000000);
}

void add_and_print_result(uint32_t num1, uint32_t num2) {
    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");

    if (!file1 || !file2) {
        printf("Error opening files.\n");
        return 1;
    }

    uint32_t num1 = read_and_convert_number(file1);
    uint32_t num2 = read_and_convert_number(file2);

    fclose(file1);
    fclose(file2);

    if (num1 == 0 || num2 == 0) {
        return 1;
    }

    add_and_print_result(num1, num2);

    return 0;
}

