#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

#define CMD(...) run((char *[]){ __VA_ARGS__ })
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

void run(char **argv) {
    pid_t pid = fork();
    if (pid == -1) {
        eprintf("[ERROR] Failed to run %s\n", argv[0]);
        exit(1);
    }
    if (pid == 0) {
        execvp(argv[0], argv);
        exit(127);
    }
    waitpid(pid, NULL, 0);
}

int main(void) {
    eprintf("[GEN] flag_generator\n");
    CMD("cc", "flag_generator.c", "-o", "flag_generator", NULL);

    eprintf("[RUN] flag_generator\n");
    CMD("./flag_generator", NULL);

    eprintf("[GEN] pacmirror\n");
    CMD("cc",
        "pacmirror.c",
        "-o",
        "pacmirror",
        "-lalpm",
        "-Wall",
        "-Wextra",

        // Arch Linux
        "-DARCH",
        "-DMULTILIB",

        // Artix Linux
        "-DARTIX",
        // "-DARTIX_GREMLINS",
        NULL);

    return 0;
}
