#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define FLAG_NAME "flags.h"

int main(void) {
        const char *file = "pacmirror.c";

        FILE *output = fopen(FLAG_NAME, "w");

        FILE *fp = fopen(file, "r");
        assert(fp);

        char c = 0;

        char *buff = malloc(sizeof(char) * 1024);
        size_t buff_size = 0;

        while ((c = fgetc(fp)) != EOF) {
                buff[buff_size++] = c;
                if (c == '\n') {
                        int i = 0;
                        bool has_define = false;

                        if (strncmp(buff, "#define", 7) == 0) {
                                has_define = true;
                                i = 7;
                        } else if (strncmp(buff, "// #define", 10) == 0) {
                                has_define = true;
                                i = 10;
                        } else if (strncmp(buff, "// EOF DEFINES", 14) == 0) {
                                break;
                        }

                        if (has_define) {
                                for (; i < buff_size; i++) {
                                        if (buff[i] != ' ') break;
                                }
                                const char *flag_name = buff + i;
                                const size_t flag_size = buff_size - i - 1;

                                char *flag_name_low = malloc(sizeof(char) * flag_size);
                                memcpy(flag_name_low, flag_name, flag_size);

                                for (int j = 0; j < flag_size; j++) {
                                        flag_name_low[j] = tolower(flag_name_low[j]);
                                }

                                fprintf(output, "#ifdef %.*s\n", (int)flag_size, flag_name);
                                fprintf(output, "#define %.*s(...) #__VA_ARGS__\n", (int)flag_size,
                                        flag_name_low);
                                fprintf(output, "#else\n");
                                fprintf(output, "#define %.*s(...) \"0\"\n", (int)flag_size,
                                        flag_name_low);
                                fprintf(output, "#endif\n\n");
                        }
                        buff_size = 0;
                }
        }

        fclose(fp);
        fclose(output);
        return 0;
}
