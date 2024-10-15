#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void create_file(const char *filename, int mod[], int mod_size, int max_rand, int limit) {
    printf("Gerando o %s...\n", filename);
    FILE *txt;
    if ((txt = fopen(filename, "w")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    unsigned int ex = (unsigned) time(NULL);
    srand(ex);
    int c, i = 0;
    while (i < limit) {
        c = rand() % max_rand;
        int valid = 1;
        for (int j = 0; j < mod_size; j++) {
            if (c % mod[j] != 0) {
                valid = 0;
                break;
            }
        }
        if (valid && c != 0) {
            fprintf(txt, "%d\n", c);
        }
        ++i;
    }
    fclose(txt);
}

int main() {
    pid_t pid;

    // Criacao do Arquivo 01
    if ((pid = fork()) == 0) {
        int mod[] = {7, 14, 42, 84, 89};
        create_file("ArquivoFork01.txt", mod, 5, 1000000, 1000000000);
        exit(0);
    }

    // Criacao do Arquivo 02
    if ((pid = fork()) == 0) {
        int mod[] = {3, 6, 31, 99, 12};
        create_file("ArquivoFork02.txt", mod, 5, 100000, 1000000000);
        exit(0);
    }

    // Criacao do Arquivo 03
    if ((pid = fork()) == 0) {
        int mod[] = {36, 9, 900, 360, 180};
        create_file("ArquivoFork03.txt", mod, 5, RAND_MAX, 1000000000);
        exit(0);
    }

    // Criacao do Arquivo 04
    if ((pid = fork()) == 0) {
        int mod[] = {8, 16, 1024, 256, 512};
        create_file("ArquivoFork04.txt", mod, 5, 1000000, 1000000000);
        exit(0);
    }

    // Espera todos os processos filhos terminarem
    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    return 0;
}
