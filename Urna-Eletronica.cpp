#include <stdio.h>
#include <locale.h>

main(){
    int eleitores, senha, menu, cand1, cand2, cand3, cand4, branco = 0, nulo = 0, admin, voto = 0, voto1 = 0, voto2 = 0, voto3 = 0, voto4 = 0;
    float porcentagem;
    
    setlocale(LC_ALL, "portuguese");

    printf("Bem vindo ao Simulador de Urna Eletrônica!\n\n");
    printf("Para seguir, por favor inserir a senha de 4 dígitos.\n\n");
    scanf("%d", &senha);

    if (senha == 3131){
        do
        {
            printf("Menu ADM-Técnico TRE\n\n");
            printf("[1]INSERIR CANDIDATOS\n");
            printf("[2]INICIAR VOTAÇÃO\n");
            printf("[3]ENCERRAR VOTAÇÃO\n");
            printf("[4]COMPUTAR VOTOS\n");
            printf("[0]SAIR\n");
            printf("Digite a opção desejada: ");
            scanf("%d", &menu);

            switch (menu) {
                case 1:
                    printf("Opção 1 escolhida: Inserir candidatos\n\n");
                        printf("Digite os números dos 4 candidatos participantes:\n\n");
                        printf("Candidato 1:\n");
                        scanf("%d", &cand1);
                        printf("Candidato 2:\n");
                        scanf("%d", &cand2);
                        printf("Canditado 3:\n");
                        scanf("%d", &cand3);
                        printf("Candidato 4:\n");
                        scanf("%d", &cand4);
                    break;
                case 2:
                    printf("Opção 2 escolhida: Iniciar votação\n");
                        printf("Digite a quantidade de votantes (população da cidade maiores de 18 e/ou com título de eleitor)\n");
                        scanf("%d", &eleitores);
                            for(int i = 0; i < eleitores; i++){
                                printf("Digite o número do candito ou 0 para branco:\n");
                                scanf("%d", &voto);
                                    if (voto == cand1)
                                    {
                                       voto1++;
                                    } else if (voto == cand2) {
                                        voto2++;
                                    } else if (voto == cand3) {
                                        voto3++;
                                    } else if (voto == cand4) {
                                        voto4++;                            
                                    } else if (voto == 0){
                                        branco++;
                                    } else {
                                        printf ("voto nulo");
                                        nulo++;
                                    }
                            }
                    break;
                case 3:
                    printf("Opção 3 escolhida: Encerrar votação\n");
                        printf("A votação será encerrada\n");
                        return 0;

                    break;
                case 4:
                    printf("Opção 4 escolhida: Computar votos\n");
                        printf("O resultado da votação foi:\n");
                        printf("O resultado da votação foi:\n");
                        printf("Candidato 1: %d votos\n", voto1);
                        printf("Candidato 2: %d votos\n", voto2);
                        printf("Candidato 3: %d votos\n", voto3);
                        printf("Candidato 4: %d votos\n", voto4);
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
        printf ("Senha incorreta!");
    }
}