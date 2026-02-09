#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 100;
    pid_t pid = fork();

    if (pid == 0) {
        x = x + 50; // Altera apenas no filho
        printf("Filho: Mudei meu x para %d\n", x);
    } else {
        sleep(1); // Espera um pouco para o filho rodar primeiro
        printf("Pai: Meu x continua sendo %d\n", x);
    }
    return 0;
}
