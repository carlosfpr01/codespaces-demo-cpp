#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    pthread_t thread;
    char filename[20];
} ThreadInfo;

ThreadInfo threadInfos[4];

void* create_file_01(void* arg) {
    ThreadInfo* info = (ThreadInfo*)arg;
    printf("Gerando o %s...\n", info->filename);
    FILE *txt;
    if((txt = fopen(info->filename, "w")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        return NULL;
    }

    unsigned int ex = ((unsigned) time(NULL));
    srand(ex);
    int c;
    for (int i = 0; i < 1000000000; ++i) {
        c = rand() % 1000000;
        if (((c % 7) == 0) && ((c % 14) == 0) && ((c % 42) == 0) && ((c % 84) == 0) && ((c % 89) == 0) && (c != 0)) {
            fprintf(txt, "%d\n", c);
        }
    }
    fclose(txt);
    printf("%s gerado com sucesso!\n", info->filename);
    return NULL;
}

void* create_file_02(void* arg) {
    ThreadInfo* info = (ThreadInfo*)arg;
    printf("Gerando o %s...\n", info->filename);
    FILE *txt;
    if((txt = fopen(info->filename, "w")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        return NULL;
    }

    unsigned int ex = ((unsigned) time(NULL));
    srand(ex);
    int c;
    for (int i = 0; i < 1000000000; ++i) {
        c = rand() % 100000;
        if (((c % 3) == 0) && ((c % 6) == 0) && ((c % 31) == 0) && ((c % 99) == 0) && ((c % 12) == 0)) {
            fprintf(txt, "%d\n", c);
        }
    }
    fclose(txt);
    printf("%s gerado com sucesso!\n", info->filename);
    return NULL;
}

void* create_file_03(void* arg) {
    ThreadInfo* info = (ThreadInfo*)arg;
    printf("Gerando o %s...\n", info->filename);
    FILE *txt;
    if((txt = fopen(info->filename, "w")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        return NULL;
    }

    unsigned int ex = ((unsigned) time(NULL));
    srand(ex);
    int c;
    for (int i = 0; i < 1000000000; ++i) {
        c = rand();
        if (((c % 36) == 0) && ((c % 9) == 0) && ((c % 900) == 0) && ((c % 360) == 0) && ((c % 180) == 0) && (c != 0) && (c <= 8000)) {
            fprintf(txt, "%d\n", c);
        }
    }
    fclose(txt);
    printf("%s gerado com sucesso!\n", info->filename);
    return NULL;
}

void* create_file_04(void* arg) {
    ThreadInfo* info = (ThreadInfo*)arg;
    printf("Gerando o %s...\n", info->filename);
    FILE *txt;
    if((txt = fopen(info->filename, "w")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        return NULL;
    }

    unsigned int ex = ((unsigned) time(NULL));
    srand(ex);
    int c;
    for (int i = 0; i < 1000000000; ++i) {
        c = rand() % 1000000;
        if (((c % 8) == 0) && ((c % 16) == 0) && ((c % 1024) == 0) && ((c % 256) == 0) && ((c % 512) == 0) && (c <= 3100)) {
            fprintf(txt, "%d\n", c);
        }
    }
    fclose(txt);
    printf("%s gerado com sucesso!\n", info->filename);
    return NULL;
}

int main() {
    const int quantArq = 4;

    for (int j = 0; j < quantArq; j++) {
        switch (j) {
    case 0:
        strcpy(threadInfos[j].filename, "ArquivoThread01.txt");
        pthread_create(&threadInfos[j].thread, NULL, create_file_01, &threadInfos[j]);
        break;
    case 1:
        strcpy(threadInfos[j].filename, "ArquivoThread02.txt");
        pthread_create(&threadInfos[j].thread, NULL, create_file_02, &threadInfos[1]);
        break;
    case 2:
        strcpy(threadInfos[j].filename, "ArquivoThread03.txt");
        pthread_create(&threadInfos[j].thread, NULL, create_file_03, &threadInfos[2]);
        break;
    case 3:
        strcpy(threadInfos[j].filename, "ArquivoThread04.txt");
        pthread_create(&threadInfos[j].thread, NULL, create_file_04, &threadInfos[3]);
        break;
    default:
        printf("Erro ao selecionar o arquivo\n");
        break;
    }
    }

    for (int i = 0; i < quantArq; ++i) {
        pthread_join(threadInfos[i].thread, NULL);
    }

    return 0;
}
