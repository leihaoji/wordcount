#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] input_file_name\n", argv[0]);
        return 1;
    }

    char param = argv[1][1]; // ��ȡ������ȥ����-��
    char filename[256];
    strcpy(filename, argv[2]); // �����ļ���

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int charCount = 0;
    int wordCount = 1; // ��ʼ��Ϊ1����Ϊ������һ������

    int c;
    while ((c = fgetc(file)) != EOF) {
        charCount++;
        if (c == ' ' || c == '\t' || c == '\n') {
            wordCount++;
        }
    }

    // ���ݲ�����������ַ������ǵ�������ע�ⵥ�ʼ����߼����������ȷͳ��
    if (param == 'c') {
        printf("Characters: %d\n", charCount);
    } else if (param == 'w') {
        // ��1����Ϊ��ʼ��ʱ�����һ��
        printf("Words: %d\n", wordCount - 1);
    } else {
        printf("Invalid parameter. Use '-c' for characters or '-w' for words.\n");
        return 1;
    }

    fclose(file);
    return 0;
}
