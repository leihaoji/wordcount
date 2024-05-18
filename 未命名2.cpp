#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] input_file_name\n", argv[0]);
        return 1;
    }

    char param = argv[1][1]; // 获取参数，去掉‘-’
    char filename[256];
    strcpy(filename, argv[2]); // 复制文件名

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int charCount = 0;
    int wordCount = 1; // 初始化为1，因为至少有一个单词

    int c;
    while ((c = fgetc(file)) != EOF) {
        charCount++;
        if (c == ' ' || c == '\t' || c == '\n') {
            wordCount++;
        }
    }

    // 根据参数决定输出字符数还是单词数，注意单词计数逻辑需调整以正确统计
    if (param == 'c') {
        printf("Characters: %d\n", charCount);
    } else if (param == 'w') {
        // 减1是因为初始化时多加了一次
        printf("Words: %d\n", wordCount - 1);
    } else {
        printf("Invalid parameter. Use '-c' for characters or '-w' for words.\n");
        return 1;
    }

    fclose(file);
    return 0;
}
