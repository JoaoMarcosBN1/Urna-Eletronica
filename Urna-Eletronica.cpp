#include <stdio.h>
#include <locale.h>

#define MAX_CANDIDATOS 10

int main() {
    int eleitores, senha, resposta, menu, candidatos[MAX_CANDIDATOS] = {0}, branco = 0, nulo = 0, voto;
    int votos[MAX_CANDIDATOS] = {0};
    int votoContabilizado;
    float porcentagem, totalVotos, maiorVotoPorcentagem;
    int vencedor = -1;

    setlocale(LC_ALL, "portuguese");

    printf("Bem-vindo ao Simulador de Urna Eletrônica!\n\n");
    printf("Para seguir, por favor insira a senha de 4 dígitos.\n\n");
    scanf("%d", &senha);

    if (senha == 3131) {
        do {
            printf("\n\nMenu ADM-Técnico TRE\n\n");
            printf("[1] INSERIR CANDIDATOS\n");
            printf("[2] INICIAR VOTAÇÃO\n");
            printf("[3] ENCERRAR VOTAÇÃO\n");
            printf("[4] COMPUTAR VOTOS\n");
            printf("[0] SAIR\n");
            printf("Digite a opção desejada: ");
            scanf("%d", &menu);

            switch (menu) {
                case 1:
                    printf("Opção 1 escolhida: Inserir candidatos\n\n");
                    printf("Digite os números dos candidatos participantes (mínimo de 4):\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("Digite o número do candidato %d: ", i + 1);
                        scanf("%d", &candidatos[i]);
                        printf("O candidato %d foi adicionado\n", candidatos[i]);
                    }

                    for (int i = 4; i < MAX_CANDIDATOS; i++) {
                        printf("Digite o número do candidato %d: ", i + 1);
                        scanf("%d", &candidatos[i]);
                        printf("O candidato %d foi adicionado\n", candidatos[i]);
                        printf("Deseja continuar?\n[1] SIM\n[2] NÃO\n\n");
                        scanf("%d", &resposta);

                        if (resposta == 2) {
                            printf("Finalizando a inserção de candidatos\n\n");
                            break;
                        } else if (resposta != 1) {
                            printf("Opção inválida.\n");
                            return 0;
                        }
                    }
                    break;

                case 2:
                    printf("Opção 2 escolhida: Iniciar votação\n");
                    printf("Digite a quantidade de votantes (população maior de 18 e/ou com título de eleitor):\n");
                    scanf("%d", &eleitores);
                    for (int i = 0; i < eleitores; i++) {
                        votoContabilizado = 0;
                        printf("\nDigite o número do candidato ou 0 para branco:\n");
                        scanf("%d", &voto);

                        for (int j = 0; j < MAX_CANDIDATOS; j++) {
                            if (candidatos[j] != 0 && voto == candidatos[j]) {
                                votos[j]++;
                                votoContabilizado = 1;
                                break;
                            }
                        }
                        if (voto == 0) {
                            branco++;
                        } else if (!votoContabilizado) {
                            nulo++;
                        }
                    }
                    break;

                case 3:
                    printf("Opção 3 escolhida: Encerrar votação\n");

                    totalVotos = branco + nulo;
                    for (int i = 0; i < MAX_CANDIDATOS; i++) {
                        totalVotos += votos[i];
                    }

                    maiorVotoPorcentagem = 0;
                    for (int i = 0; i < MAX_CANDIDATOS; i++) {
                        if (candidatos[i] != 0 && totalVotos > 0) {
                            porcentagem = ((float)votos[i] / totalVotos) * 100;
                            printf("Candidato %d: %d votos (%.2f%%)\n", candidatos[i], votos[i], porcentagem);
                            if (porcentagem > maiorVotoPorcentagem) {
                                maiorVotoPorcentagem = porcentagem;
                                vencedor = i;
                            }
                        }
                    }

                    if (totalVotos > 0 && maiorVotoPorcentagem > 50) {
                        printf("O candidato %d venceu com %.2f%% dos votos!\n", candidatos[vencedor], maiorVotoPorcentagem);
                    } else {
                        printf("Nenhum candidato obteve mais de 50%% dos votos. Uma nova votação será realizada com os dois mais votados.\n");
                        int segundoLugar = -1;
                        for (int i = 0; i < MAX_CANDIDATOS; i++) {
                            if (i != vencedor && candidatos[i] != 0) {
                                if (segundoLugar == -1 || votos[i] > votos[segundoLugar]) {
                                    segundoLugar = i;
                                }
                            }
                        }
                        if (vencedor != -1 && segundoLugar != -1) {
                            printf("A nova votação será entre os candidatos %d e %d.\n", candidatos[vencedor], candidatos[segundoLugar]);
                        } 
                        for (int i = 0; i < MAX_CANDIDATOS; i++)
                        {
                            votos[i] = 0;
                        } 
                        branco = 0;
                        nulo = 0;
                        
                        printf("Iniciando a nova votação entre os dois candidatos mais votados.\n");                        
                        for (int i = 0; i < eleitores; i++){
                            printf("\nDigite o número do candidato (%d ou %d):\n", candidatos[vencedor], candidatos[segundoLugar]);
                            scanf("%d", &voto);

                            if (voto == candidatos[vencedor]){
                                votos[vencedor]++;
                            } else if(voto == candidatos[segundoLugar]){
                                votos[segundoLugar]++;
                            } else if(voto == 0) {
                                branco++;
                            } else {
                                nulo++;
                            }  
                        }    
                        totalVotos = votos[vencedor] + votos[segundoLugar] + branco + nulo;
                        porcentagem = ((float)votos[vencedor] / totalVotos) * 100;
                        printf("Candidato %d: %d votos (%.2f%%)\n", candidatos[vencedor], votos[vencedor], porcentagem);
                        porcentagem = ((float)votos[segundoLugar] / totalVotos) * 100;
                        printf("Candidato %d: %d votos (%.2f%%)\n", candidatos[segundoLugar], votos[segundoLugar], porcentagem);

                        if (votos[vencedor] > votos[segundoLugar])
                        {
                            printf("O candidato %d venceu a nova votação!\n", candidatos[vencedor]);
                        } else if (votos[segundoLugar] > votos[vencedor]) {
                            printf("O candidato %d venceu a nova votação!\n", candidatos[segundoLugar]);
                        } else {
                            printf("A nova votação terminou em empate.\n");
                        }                        


                    }
                    break;

                case 4:
                    printf("Opção 4 escolhida: Computar votos\n");
                    for (int i = 0; i < MAX_CANDIDATOS; i++) {
                        if (candidatos[i] != 0) {
                            printf("Candidato %d: %d votos\n", candidatos[i], votos[i]);
                        }
                    }
                    printf("Votos em branco: %d\n", branco);
                    printf("Votos nulos: %d\n", nulo);
                    break;

                case 0:
                    printf("Saindo do sistema...\n");
                    break;

                default:
                    printf("Opção inválida!\n");
            }

        } while (menu != 0);
    } else {
        printf("Senha incorreta!");
    }

    return 0;
}
