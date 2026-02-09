#include <stdio.h>
#include <unistd.h>

int main() {
    int quem_sou_eu = fork();

    if (quem_sou_eu > 0) {
        // --- BLOCO DO PAI ---
        printf("[PAI] Eu vou fechar agora e deixar meu filho sozinho...\n");
        // O pai termina aqui, sem o comando 'wait'
    } 
    else if (quem_sou_eu == 0) {
        // --- BLOCO DO FILHO ---
        printf("[FILHO] Meu pai original tem o ID: %d\n", getppid());
        
        printf("[FILHO] Vou esperar 2 segundos para o meu pai sumir...\n");
        sleep(2); // Tempo para o pai fechar
        
        printf("[FILHO] Agora que meu pai se foi, quem é meu pai adotivo?\n");
        printf("[FILHO] Meu novo pai (ID) é: %d\n", getppid());
    }

    return 0;
}
