#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void run(char **argv) {
        pid_t pid = fork();
        if (pid == -1) {
                fprintf(stderr, "ERROR: Failed to run %s\n", argv[0]);
                exit(1);
        }
        if (pid == 0) {
                execvp(argv[0], argv);
                exit(127);
        }
}

#define CMD(...) run((char *[]){ __VA_ARGS__ })

int main(void) {
        printf("[GEN] flag_generator\n");
        CMD("cc flag_generator.c -o flag_generator", NULL);

        printf("[RUN] flag_generator\n");
        CMD("./flag_generator", NULL);

        printf("[GEN] pacmirror\n");
        CMD("cc pacmirror.c -o pacmirror", NULL);

        return 0;
}
