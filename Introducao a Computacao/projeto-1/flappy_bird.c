#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>
#include <sys/select.h>

// Configurações do jogo
#define LARGURA_TELA 80
#define ALTURA_TELA 20
#define GRAVIDADE 0.5
#define IMPULSO -1
#define LARGURA_OBSTACULO 4
#define VELOCIDADE_JOGO 1

// Estruturas
typedef struct {
    int x, y;
    float velocidade;
} Passaro;

typedef struct {
    int x;
    int altura_superior;
    int altura_inferior;
    int passou;
} Obstaculo;

typedef struct {
    int largura, altura;
    char **buffer;
} Tela;

// Variáveis globais
Passaro passaro;
Obstaculo obstaculos[3];
int pontuacao = 0;
int game_over = 0;
int jogo_iniciado = 0;
Tela tela;

// Funções de sistema
void configurar_terminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void restaurar_terminal() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void limpar_tela() {
    printf("\033[2J\033[H");
    fflush(stdout);
}

void ocultar_cursor() {
    printf("\033[?25l");
    fflush(stdout);
}

void mostrar_cursor() {
    printf("\033[?25h");
    fflush(stdout);
}

// Funções do jogo
void inicializar_tela() {
    tela.largura = LARGURA_TELA;
    tela.altura = ALTURA_TELA;
    tela.buffer = malloc(ALTURA_TELA * sizeof(char*));
    
    for (int i = 0; i < ALTURA_TELA; i++) {
        tela.buffer[i] = malloc((LARGURA_TELA + 1) * sizeof(char));
        memset(tela.buffer[i], ' ', LARGURA_TELA);
        tela.buffer[i][LARGURA_TELA] = '\0';
    }
}

void liberar_tela() {
    for (int i = 0; i < ALTURA_TELA; i++) {
        free(tela.buffer[i]);
    }
    free(tela.buffer);
}

void limpar_buffer() {
    for (int i = 0; i < ALTURA_TELA; i++) {
        memset(tela.buffer[i], ' ', LARGURA_TELA);
    }
}

void desenhar_borda() {
    // Borda superior e inferior
    for (int x = 0; x < LARGURA_TELA; x++) {
        tela.buffer[0][x] = '-';
        tela.buffer[ALTURA_TELA-1][x] = '-';
    }
    
    // Bordas laterais
    for (int y = 0; y < ALTURA_TELA; y++) {
        tela.buffer[y][0] = '|';
        tela.buffer[y][LARGURA_TELA-1] = '|';
    }
}

void inicializar_jogo() {
    // Inicializar pássaro
    passaro.x = 10;
    passaro.y = ALTURA_TELA / 2;
    passaro.velocidade = 0;
    
    // Inicializar obstáculos
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        obstaculos[i].x = LARGURA_TELA + (i * 25);
        obstaculos[i].altura_superior = rand() % (ALTURA_TELA - 8) + 3;
        obstaculos[i].altura_inferior = ALTURA_TELA - obstaculos[i].altura_superior - 4;
        obstaculos[i].passou = 0;
    }
    
    pontuacao = 0;
    game_over = 0;
}

void desenhar_passaro() {
    if (passaro.y >= 1 && passaro.y < ALTURA_TELA-1 && 
        passaro.x >= 1 && passaro.x < LARGURA_TELA-1) {
        tela.buffer[passaro.y][passaro.x] = '#';
    }
}

void desenhar_obstaculos() {
    for (int i = 0; i < 3; i++) {
        if (obstaculos[i].x >= 0 && obstaculos[i].x < LARGURA_TELA) {
            // Obstáculo superior
            for (int y = 1; y < obstaculos[i].altura_superior; y++) {
                for (int x = obstaculos[i].x; x < obstaculos[i].x + LARGURA_OBSTACULO && x < LARGURA_TELA-1; x++) {
                    if (x >= 1) {
                        tela.buffer[y][x] = '|';
                    }
                }
            }
            
            // Obstáculo inferior
            for (int y = ALTURA_TELA - obstaculos[i].altura_inferior; y < ALTURA_TELA-1; y++) {
                for (int x = obstaculos[i].x; x < obstaculos[i].x + LARGURA_OBSTACULO && x < LARGURA_TELA-1; x++) {
                    if (x >= 1) {
                        tela.buffer[y][x] = '|';
                    }
                }
            }
        }
    }
}

void atualizar_passaro() {
    // Aplicar gravidade
    passaro.velocidade += GRAVIDADE;
    passaro.y += passaro.velocidade;
    
    // Verificar colisões com bordas
    if (passaro.y <= 0 || passaro.y >= ALTURA_TELA-1) {
        game_over = 1;
    }
}

void atualizar_obstaculos() {
    for (int i = 0; i < 3; i++) {
        obstaculos[i].x -= VELOCIDADE_JOGO;
        
        // Verificar se passou do pássaro para pontuar
        if (obstaculos[i].x + LARGURA_OBSTACULO < passaro.x && !obstaculos[i].passou) {
            pontuacao++;
            obstaculos[i].passou = 1;
        }
        
        // Reposicionar obstáculo quando sair da tela
        if (obstaculos[i].x + LARGURA_OBSTACULO < 0) {
            obstaculos[i].x = LARGURA_TELA + 10;
            obstaculos[i].altura_superior = rand() % (ALTURA_TELA - 8) + 3;
            obstaculos[i].altura_inferior = ALTURA_TELA - obstaculos[i].altura_superior - 4;
            obstaculos[i].passou = 0;
        }
        
        // Verificar colisão com pássaro
        if (passaro.x >= obstaculos[i].x && passaro.x < obstaculos[i].x + LARGURA_OBSTACULO) {
            if (passaro.y <= obstaculos[i].altura_superior || 
                passaro.y >= ALTURA_TELA - obstaculos[i].altura_inferior) {
                game_over = 1;
            }
        }
    }
}

void desenhar_interface() {
    // Desenhar pontuação
    char pontuacao_str[20];
    snprintf(pontuacao_str, sizeof(pontuacao_str), "Score: %d", pontuacao);
    
    int len = strlen(pontuacao_str);
    int start_x = (LARGURA_TELA - len) / 2;
    
    for (int i = 0; i < len; i++) {
        if (start_x + i < LARGURA_TELA-1) {
            tela.buffer[2][start_x + i] = pontuacao_str[i];
        }
    }
    
    // Desenhar instruções
    if (!jogo_iniciado) {
        char instrucao[] = "Pressione ESPACO para pular!";
        int len_inst = strlen(instrucao);
        int start_inst = (LARGURA_TELA - len_inst) / 2;
        
        for (int i = 0; i < len_inst; i++) {
            if (start_inst + i < LARGURA_TELA-1) {
                tela.buffer[ALTURA_TELA/2][start_inst + i] = instrucao[i];
            }
        }
        
        char start[] = "Pressione ESPACO para iniciar!";
        int len_start = strlen(start);
        int start_start = (LARGURA_TELA - len_start) / 2;
        
        for (int i = 0; i < len_start; i++) {
            if (start_start + i < LARGURA_TELA-1) {
                tela.buffer[ALTURA_TELA/2 + 2][start_start + i] = start[i];
            }
        }
    }
    
    // Desenhar game over
    if (game_over) {
        char game_over_text[] = "GAME OVER!";
        int len_go = strlen(game_over_text);
        int start_go = (LARGURA_TELA - len_go) / 2;
        
        for (int i = 0; i < len_go; i++) {
            if (start_go + i < LARGURA_TELA-1) {
                tela.buffer[ALTURA_TELA/2][start_go + i] = game_over_text[i];
            }
        }
        
        char restart[] = "Pressione R para reiniciar";
        int len_restart = strlen(restart);
        int start_restart = (LARGURA_TELA - len_restart) / 2;
        
        for (int i = 0; i < len_restart; i++) {
            if (start_restart + i < LARGURA_TELA-1) {
                tela.buffer[ALTURA_TELA/2 + 2][start_restart + i] = restart[i];
            }
        }
    }
}

void renderizar_tela() {
    limpar_tela();
    
    for (int y = 0; y < ALTURA_TELA; y++) {
        printf("%s\n", tela.buffer[y]);
    }
}

int tecla_disponivel() {
    struct timeval tv;
    fd_set rdfs;
    
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    
    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);
    
    select(STDIN_FILENO + 1, &rdfs, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &rdfs);
}

char ler_tecla() {
    if (tecla_disponivel()) {
        return getchar();
    }
    return 0;
}

void processar_input() {
    char tecla = ler_tecla();
    
    if (!jogo_iniciado) {
        if (tecla == ' ') {
            jogo_iniciado = 1;
        }
    } else if (!game_over) {
        if (tecla == ' ') {
            passaro.velocidade = IMPULSO;
        }
    } else {
        if (tecla == 'r' || tecla == 'R') {
            inicializar_jogo();
            jogo_iniciado = 1;
        }
        if (tecla == 'q' || tecla == 'Q') {
            exit(0);
        }
    }
}

int main() {
    // Configurar terminal
    configurar_terminal();
    ocultar_cursor();
    
    // Inicializar jogo
    inicializar_tela();
    inicializar_jogo();
    
    printf("=== FLAPPY BIRD - TERMINAL ===\n");
    printf("Controles:\n");
    printf("  ESPACO - Pular / Iniciar jogo\n");
    printf("  R - Reiniciar (após game over)\n");
    printf("  Q - Sair (após game over)\n");
    printf("Pressione ESPACO para iniciar...\n");
    sleep(3);
    
    // Loop principal do jogo
    while (1) {
        processar_input();
        
        if (jogo_iniciado && !game_over) {
            atualizar_passaro();
            atualizar_obstaculos();
        }
        
        // Renderizar
        limpar_buffer();
        desenhar_borda();
        
        if (jogo_iniciado) {
            desenhar_obstaculos();
            desenhar_passaro();
        }
        
        desenhar_interface();
        renderizar_tela();
        
        usleep(100000); // 100ms de delay
    }
    
    // Limpeza
    liberar_tela();
    mostrar_cursor();
    restaurar_terminal();
    
    return 0;
}
