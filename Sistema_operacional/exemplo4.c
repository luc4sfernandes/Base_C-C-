#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv, char* envp[]) {
    int pid, i;

    printf("--- PAI: Vou dar a ordem para abrir tudo de uma vez! ---\n");

    // PASSO 1: Criar todos os filhos rapidamente
    for (i = 1; i <= 3; i++) {
        pid = fork();

        if (pid == 0) { // Sou um dos filhos
            if (i == 1) execve("/usr/bin/xcalc", argv, envp);
            if (i == 2) execve("/usr/bin/gedit", argv, envp);
            if (i == 3) execve("/usr/bin/xeyes", argv, envp);
            
            // Se o execve funcionar, o filho "morre" aqui e vira o novo programa.
            // O código abaixo só roda se o programa (calculadora, etc) NÃO for encontrado.
            perror("Erro ao abrir programa");
            return 0; 
        }
        
        // REPARE: O waitpid NÃO está mais aqui dentro! 
        // O pai não espera, ele volta direto para o 'for' para criar o próximo filho.
    }

    // PASSO 2: Agora que todos estão rodando, o pai espera os 3 terminarem
    printf("[PAI]: Todos os filhos foram criados. Agora vou aguardar vocês fecharem tudo.\n");
    
    for (i = 1; i <= 3; i++) {
        wait(NULL); // O pai espera 3 vezes (uma para cada filho que fechar)
    }

    printf("[PAI]: Todos os programas foram fechados. Fim da execução.\n");
    return 0;
}
