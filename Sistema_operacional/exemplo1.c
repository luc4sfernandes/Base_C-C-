#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("--- INÍCIO: Só existe UM processo (O PAI) ---\n\n");

    int resultado = fork(); // A partir daqui, o programa se duplica!

    if (resultado == 0) {
        // --- TUDO AQUI SÓ O FILHO FAZ ---
        printf("[FILHO]: Oi, eu sou o clone! Meu ID é %d.\n", getpid());
        
        for (int i = 1; i <= 3; i++) {
            printf("[FILHO]: Contando... %d\n", i);
            sleep(1); // Faz o filho esperar 1 segundo para podermos ver
        }
        
        printf("[FILHO]: Tchau! Terminei meu trabalho.\n");
    } 
    else {
        // --- TUDO AQUI SÓ O PAI FAZ ---
        printf("[PAI]: Eu sou o original! Meu ID é %d.\n", getpid());
        printf("[PAI]: O ID do meu filho é %d.\n", resultado);
        printf("[PAI]: Vou esperar meu filho terminar...\n\n");

        wait(NULL); // O Pai trava aqui até o filho acabar
        
        printf("\n[PAI]: Meu filho já foi embora. Agora vou fechar o programa.\n");
    }

    return 0;
}
