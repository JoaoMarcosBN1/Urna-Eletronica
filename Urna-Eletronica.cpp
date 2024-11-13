#include <stdio.h>
#include <locale.h>

main(){
    int eleitores, senha, resposta, menu, candidatos[10] = {0}, branco, nulo, voto[10] = {0}, votoContabilizado = 0;
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
                        printf("Digite os números dos candidatos participantes (número mínimo de candidatos é 4 ):\n\n");
                        for (int i = 0; i < 4; i++)
                        {
                            printf("Digite o número do candidato %d: ", i + 1);
                            scanf("%d", &candidatos[i]);
                            printf("O candidato %d foi adicionado\n", candidatos[i]);
                        } 
                        
                        for (int i = 4; i < 10; i++)
                        {
                            printf("Digite o número do candidato %d: ", i + 1);
                            scanf("%d", &candidatos[i]);
                            printf("O candidato %d foi adicionado\n", candidatos[i]);
                            printf("Deseja continuar?\n[1]SIM\n[2]NÃO\n\n");
                            scanf("%d", &resposta);
                                
                                if (resposta == 2){
                                    printf("Finalizando a inserção de candidatos\n\n");
                                break;

                                } else if (resposta != 1) {
                                    printf("Opção inválida.\n");
                                return 0;
                                }
                            printf("Candidatos adicionados:\n");
                                for (int i = 0; i < 10; i++)
                                {
                                    if(candidatos[i] != 0) {
                                        printf("Candidato %d: %d\n", i+1, candidatos[i]);
                                    }
                                }
                                                       
                        }    
                    
                    break;
                
                case 2:
                    printf("Opção 2 escolhida: Iniciar votação\n");
                        printf("Digite a quantidade de votantes (população da cidade maiores de 18 e/ou com título de eleitor)\n");
                        scanf("%d", &eleitores);
                            for(int i = 0; i < eleitores; i++){
                                printf("Digite o número do candito ou 0 para branco:\n");
                                scanf("%d", &voto);
                                for (int j = 0; j < 10; j++)
                                {
                                    if(candidatos[j] != 0 && voto == candidatos[j]){
                                        votos[j]++;
                                        votoContabilizado = 1;
                                        printf("Sou voto foi no candidato %d", candidatos[j]);
                                        break;
                                    }
                                }
                                if (voto == 0)
                                {
                                    printf("Voto em Branco\n");
                                    branco++;
                                }else if (!votoContabilizado)
                                {
                                    printf("Voto nulo\n");
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