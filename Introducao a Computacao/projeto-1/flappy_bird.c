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
#define GRAVIDADE 0.1
#define IMPULSO -0.3
#define LARGURA_OBSTACULO 4
#define VELOCIDADE_JOGO 0.5
#define FPS_DELAY 33333  // Microssegundos (33ms = 30 FPS)
#define PONTUACAO_PARA_PROXIMO_NIVEL 1

// Estruturas
typedef struct {
    int x, y;
    float velocidade;
    char desenho[3][6];  // Desenho ASCII do pássaro (3 linhas x 6 colunas)
    int nivel_evolucao;  // Nível de evolução baseado na pontuação
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
    fputs("\033[2J\033[H", stdout);
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

void inicializar_desenho_passaro() {
    // Limpar desenho inicial
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            passaro.desenho[i][j] = ' ';
        }
    }
    
    // Nível 0: #
    passaro.desenho[1][2] = '#';
    passaro.nivel_evolucao = 0;
}

void atualizar_desenho_passaro() {
    int novo_nivel = pontuacao / PONTUACAO_PARA_PROXIMO_NIVEL;  // Novo nível baseado na pontuação
    
    if (novo_nivel != passaro.nivel_evolucao) {
        passaro.nivel_evolucao = novo_nivel;
        
        // Limpar desenho anterior
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 6; j++) {
                passaro.desenho[i][j] = ' ';
            }
        }
        
        // Evolução baseada no nível
        if (passaro.nivel_evolucao >= 0) {  // Nível 0: #
            passaro.desenho[1][2] = '#';
        }
        if (passaro.nivel_evolucao >= 1) {  // Nível 1: ##
            passaro.desenho[1][2] = '#';
            passaro.desenho[1][3] = '#';
        }
        if (passaro.nivel_evolucao >= 2) {  // Nível 2: ###
            passaro.desenho[1][2] = '#';
            passaro.desenho[1][3] = '#';
            passaro.desenho[1][4] = '#';
        }
        if (passaro.nivel_evolucao >= 3) {  // Nível 3: ### + #
            passaro.desenho[1][2] = '#';
            passaro.desenho[1][3] = '#';
            passaro.desenho[1][4] = '#';
            passaro.desenho[0][2] = '#';
        }
        if (passaro.nivel_evolucao >= 4) {  // Nível 4: ### + ##
            passaro.desenho[1][2] = '#';
            passaro.desenho[1][3] = '#';
            passaro.desenho[1][4] = '#';
            passaro.desenho[0][2] = '#';
            passaro.desenho[0][3] = '#';
        }
        if (passaro.nivel_evolucao >= 5) {  // Nível 5: ### + ###
            passaro.desenho[1][2] = '#';
            passaro.desenho[1][3] = '#';
            passaro.desenho[1][4] = '#';
            passaro.desenho[0][2] = '#';
            passaro.desenho[0][3] = '#';
            passaro.desenho[0][4] = '#';
        }
        if (passaro.nivel_evolucao >= 6) {  // Nível 6: #### + ###
            passaro.desenho[1][1] = '#';
            passaro.desenho[1][2] = '#';
            passaro.desenho[1][3] = '#';
            passaro.desenho[1][4] = '#';
            passaro.desenho[0][2] = '#';
            passaro.desenho[0][3] = '#';
            passaro.desenho[0][4] = '#';
        }
        if (passaro.nivel_evolucao >= 7) {  // Nível 7: #### + # + ###
            passaro.desenho[1][1] = '#';
            passaro.desenho[1][2] = '#';
            passaro.desenho[1][3] = '#';
            passaro.desenho[1][4] = '#';
            passaro.desenho[0][0] = '#';
            passaro.desenho[2][2] = '#';
            passaro.desenho[2][3] = '#';
            passaro.desenho[2][4] = '#';
        }
        if (passaro.nivel_evolucao >= 8) {  // Nível 8: #### + ## + ###
            passaro.desenho[1][1] = '#';
            passaro.desenho[1][2] = '#';
            passaro.desenho[1][3] = '#';
            passaro.desenho[1][4] = '#';
            passaro.desenho[0][0] = '#';
            passaro.desenho[0][1] = '#';
            passaro.desenho[2][2] = '#';
            passaro.desenho[2][3] = '#';
            passaro.desenho[2][4] = '#';
        }
    }
}

void inicializar_jogo() {
    // Inicializar pássaro
    passaro.x = 10;
    passaro.y = ALTURA_TELA / 2;
    passaro.velocidade = 0;
    inicializar_desenho_passaro();
    
    // Inicializar obstáculos
    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        obstaculos[i].x = LARGURA_TELA + (i * 25);
        // Garantir que sempre há um espaço de 8 linhas entre os obstáculos
        int espaco_obstaculos = 8;
        int altura_maxima_superior = ALTURA_TELA - espaco_obstaculos - 2; // -2 para bordas
        obstaculos[i].altura_superior = rand() % altura_maxima_superior + 1;
        obstaculos[i].altura_inferior = ALTURA_TELA - obstaculos[i].altura_superior - espaco_obstaculos;
        obstaculos[i].passou = 0;
    }
    
    pontuacao = 0;
    game_over = 0;
}

void desenhar_passaro() {
    // Desenhar o pássaro completo (3x6)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            int y = passaro.y - 1 + i;  // Centralizar verticalmente
            int x = passaro.x - 2 + j;  // Centralizar horizontalmente
            
            if (y >= 1 && y < ALTURA_TELA-1 && 
                x >= 1 && x < LARGURA_TELA-1 && 
                passaro.desenho[i][j] != ' ') {
                tela.buffer[y][x] = passaro.desenho[i][j];
            }
        }
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
    
    // Verificar colisões com bordas (hitbox baseada no nível de evolução)
    if (passaro.nivel_evolucao == 0) {
        // Nível 0: Apenas um # (1x1)
        if (passaro.y <= 0 || passaro.y >= ALTURA_TELA-1) {
            game_over = 1;
        }
    } else {
        // Níveis 1+: Pássaro completo (3x6)
        if (passaro.y - 1 <= 0 || passaro.y + 1 >= ALTURA_TELA-1) {
            game_over = 1;
        }
    }
}

void atualizar_obstaculos() {
    static int contador = 0;
    contador++;
    
    // Mover obstáculos apenas a cada 2 frames (velocidade reduzida)
    if (contador >= 2) {
        contador = 0;
        for (int i = 0; i < 3; i++) {
            obstaculos[i].x -= 1;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        // Verificar se passou do pássaro para pontuar
        if (obstaculos[i].x + LARGURA_OBSTACULO < passaro.x && !obstaculos[i].passou) {
            pontuacao++;
            obstaculos[i].passou = 1;
        }
        
        // Reposicionar obstáculo quando sair da tela
        if (obstaculos[i].x + LARGURA_OBSTACULO < 0) {
            obstaculos[i].x = LARGURA_TELA + 10;
            // Manter o mesmo espaço de 8 linhas entre os obstáculos
            int espaco_obstaculos = 8;
            int altura_maxima_superior = ALTURA_TELA - espaco_obstaculos - 2; // -2 para bordas
            obstaculos[i].altura_superior = rand() % altura_maxima_superior + 1;
            obstaculos[i].altura_inferior = ALTURA_TELA - obstaculos[i].altura_superior - espaco_obstaculos;
            obstaculos[i].passou = 0;
        }
        
        // Verificar colisão com pássaro (hitbox baseada no nível de evolução)
        int passaro_left, passaro_right, passaro_top, passaro_bottom;
        
        if (passaro.nivel_evolucao == 0) {
            // Nível 0: Apenas um # (1x1)
            passaro_left = passaro.x;
            passaro_right = passaro.x;
            passaro_top = passaro.y;
            passaro_bottom = passaro.y;
        } else {
            // Níveis 1+: Pássaro completo (3x6)
            passaro_left = passaro.x - 2;
            passaro_right = passaro.x + 3;
            passaro_top = passaro.y - 1;
            passaro_bottom = passaro.y + 1;
        }
        
        // Verificar se há sobreposição horizontal (com margem de segurança nas bordas)
        int margem_seguranca = 1; // Margem de 1 caractere nas bordas dos obstáculos
        int obstaculo_left = obstaculos[i].x + margem_seguranca;
        int obstaculo_right = obstaculos[i].x + LARGURA_OBSTACULO - margem_seguranca;
        
        if (passaro_right >= obstaculo_left && passaro_left < obstaculo_right) {
            // Verificar colisão com obstáculo superior (ignorando bordas)
            // Obstáculo superior ocupa de y=1 até y=altura_superior-1
            // Colisão se: passaro_bottom >= 1 E passaro_top < altura_superior (com margem)
            int altura_superior_com_margem = obstaculos[i].altura_superior - margem_seguranca;
            if (passaro_bottom >= 1 + margem_seguranca && passaro_top < altura_superior_com_margem) {
                game_over = 1;
            }
            // Verificar colisão com obstáculo inferior (ignorando bordas)
            // Obstáculo inferior ocupa de y=ALTURA_TELA-altura_inferior até y=ALTURA_TELA-2
            // Colisão se: passaro_top < ALTURA_TELA-1 E passaro_bottom >= obstaculo_inferior_top (com margem)
            int obstaculo_inferior_top = ALTURA_TELA - obstaculos[i].altura_inferior;
            int obstaculo_inferior_top_com_margem = obstaculo_inferior_top + margem_seguranca;
            if (passaro_top < ALTURA_TELA-1 - margem_seguranca && passaro_bottom >= obstaculo_inferior_top_com_margem) {
                game_over = 1;
            }
        }
    }
}

void desenhar_interface() {
    // Desenhar pontuação e nível de evolução
    char pontuacao_str[30];
    snprintf(pontuacao_str, sizeof(pontuacao_str), "Score: %d | Nivel: %d", pontuacao, passaro.nivel_evolucao);
    
    int len = strlen(pontuacao_str);
    int start_x = (LARGURA_TELA - len) / 2;
    
    for (int i = 0; i < len; i++) {
        if (start_x + i < LARGURA_TELA-1) {
            tela.buffer[2][start_x + i] = pontuacao_str[i];
        }
    }
    
    // Desenhar menu inicial
    if (!jogo_iniciado) {
        char titulo[] = "=== FLAPPY TERMINAL ===";
        int len_titulo = strlen(titulo);
        int start_titulo = (LARGURA_TELA - len_titulo) / 2;
        
        for (int i = 0; i < len_titulo; i++) {
            if (start_titulo + i < LARGURA_TELA-1) {
                tela.buffer[4][start_titulo + i] = titulo[i];
            }
        }
        
        char controles1[] = "Controles:";
        int len_cont1 = strlen(controles1);
        int start_cont1 = (LARGURA_TELA - len_cont1) / 2;
        
        for (int i = 0; i < len_cont1; i++) {
            if (start_cont1 + i < LARGURA_TELA-1) {
                tela.buffer[6][start_cont1 + i] = controles1[i];
            }
        }
        
        char controles2[] = "ESPACO - Pular / Iniciar jogo";
        int len_cont2 = strlen(controles2);
        int start_cont2 = (LARGURA_TELA - len_cont2) / 2;
        
        for (int i = 0; i < len_cont2; i++) {
            if (start_cont2 + i < LARGURA_TELA-1) {
                tela.buffer[7][start_cont2 + i] = controles2[i];
            }
        }
        
        char controles3[] = "R - Reiniciar (apos game over)";
        int len_cont3 = strlen(controles3);
        int start_cont3 = (LARGURA_TELA - len_cont3) / 2;
        
        for (int i = 0; i < len_cont3; i++) {
            if (start_cont3 + i < LARGURA_TELA-1) {
                tela.buffer[8][start_cont3 + i] = controles3[i];
            }
        }
        
        char controles4[] = "Q - Sair (apos game over)";
        int len_cont4 = strlen(controles4);
        int start_cont4 = (LARGURA_TELA - len_cont4) / 2;
        
        for (int i = 0; i < len_cont4; i++) {
            if (start_cont4 + i < LARGURA_TELA-1) {
                tela.buffer[9][start_cont4 + i] = controles4[i];
            }
        }
        
        char start[] = "Pressione ESPACO para iniciar...";
        int len_start = strlen(start);
        int start_start = (LARGURA_TELA - len_start) / 2;
        
        for (int i = 0; i < len_start; i++) {
            if (start_start + i < LARGURA_TELA-1) {
                tela.buffer[11][start_start + i] = start[i];
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
        
        char quit[] = "Pressione Q para sair";
        int len_quit = strlen(quit);
        int start_quit = (LARGURA_TELA - len_quit) / 2;
        
        for (int i = 0; i < len_quit; i++) {
            if (start_quit + i < LARGURA_TELA-1) {
                tela.buffer[ALTURA_TELA/2 + 4][start_quit + i] = quit[i];
            }
        }
    }
}

void renderizar_tela() {
    limpar_tela();
    
    // Renderizar todas as linhas de uma vez para melhor performance
    for (int y = 0; y < ALTURA_TELA; y++) {
        fputs(tela.buffer[y], stdout);
        fputs("\n", stdout);
    }
    fflush(stdout);
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
    
    // Menu inicial será mostrado dentro do jogo
    
    // Loop principal do jogo
    while (1) {
        processar_input();
        
        if (jogo_iniciado && !game_over) {
            atualizar_passaro();
            atualizar_obstaculos();
            atualizar_desenho_passaro();
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
        
        usleep(FPS_DELAY);
    }
    
    // Limpeza
    liberar_tela();
    mostrar_cursor();
    restaurar_terminal();
    
    return 0;
}
