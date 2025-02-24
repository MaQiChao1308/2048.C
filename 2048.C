    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    #include<string.h>
    #include<time.h>
    #include<conio.h>

    void inicializarMatriz(int **Matriz,int lin,int col)//inicia a matriz com 0 
    {
        for(int i=0;i<lin;i++)
        {
            for(int j=0;j<col;j++)
            {
                Matriz[i][j]=0;
            }
        }
    }

    void gerarNumeros(int **Matriz)//gerar números aleatórios na matriz
    {
        int linha;
        int coluna;
        do
        {
            linha = rand() % 4;
            coluna = rand() %4;
        } while (Matriz[linha][coluna] != 0);

        Matriz[linha][coluna] =(rand() % 2 == 0) ? 2 : 4;

    }

    void imprimirMatriz(int  **Matriz,int lin,int col)// função para imprimir a matriz 
    {
        for(int i=0;i<lin;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(Matriz[i][j]!=0)
                {
                    printf("||%5d ",Matriz[i][j]);
                }
                else
                {
                    printf("||      ");
                }
            }
            printf("||\n\n\n");
        }
    }

    bool matrizCheia(int **Matriz,int lin,int col)//verificar se a matriz está cheia
    {
        for(int i=0;i<lin;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(Matriz[i][j]==0)
                {
                    return false;
                }
            } 
        }
        return true;
    }

    void movCima(int **Matriz,int lin,int col,int *score)//função para movimentar os números nas colunas de baixo para cima
    {
        for(int j=0;j<col;j++)
        {
            int temp[lin];
            int k=0;

            for(int i=0;i<lin;i++)// cria um array temporario
            {
                temp[i]=0;
            }

            for(int i=0;i<lin;i++)// percorre a coluna, os !=0 vai p array temp
            {
                if(Matriz[i][j] !=0)
                {
                    temp[k++]=Matriz[i][j];
                }
            }

            for(int i=0;i<lin-1;i++)// array temp recebe os números diferente de 0, e se o primeiro N da coluna for igual ao proximo, N1=N1*2 e N2 zera e assim segue
            {
                if(temp[i]==temp[i+1] && temp[i] !=0)
                {
                    temp[i]*=2;
                    *score +=temp[i];
                    temp[i+1]=0;
                }
            }

            k=0;// zera o contador k
            for(int i=0;i<lin;i++)// alinha os números, deixando os 0 em baixo 
            {
                if(temp[i]!=0)
                {
                    temp[k++]=temp[i];
                }
            }
            while(k<lin)//preenche o resto da coluna com 0
            {
                temp[k++]=0;
            }

            for(int i=0;i<lin;i++)//passa a coluna temporaria para a matriz principal
            {
                Matriz[i][j]=temp[i];
            }


        }
    }

    void movBaixo(int **Matriz,int lin,int col, int *score)//função para movimentar os números nas colunas de cima para baixo
    {
        for(int j=0;j<col;j++)
        {
            int temp[lin];
            int k=lin-1;

            for(int i=0;i<lin;i++)
            {
                temp[i]=0;
            }

            for(int i=lin-1;i>=0;i--)
            {
                if(Matriz[i][j]!= 0)
                {
                    temp[k--]=Matriz[i][j];
                }
            }
            
            for(int i=lin-1;i>0;i--)
            {
                if(temp[i]==temp[i-1] && temp[i] != 0)
                {
                    temp[i] *=2;
                    *score +=temp[i];
                    temp[i-1]=0;
                }
            }

            k=lin -1;

            for(int i=lin-1;i>=0;i--)
            {
                if(temp[i]!=0)
                {
                    temp[k--]= temp[i];
                }
            }

            while(k>=0)
            {
                temp[k--]=0;
            }

            for(int i=0;i<lin;i++)
            {
                Matriz[i][j]=temp[i];
            }
        }
    }

    void movDireita(int **Matriz,int lin,int col, int *score)//função para movimentar os números nas linhas da esquerda para direita
    {
        for(int i=0;i<lin;i++)
        {
            int temp[col];
            int k=col-1;

            for(int j=0;j<col;j++)
            {
                temp[j]=0;
            }

            for(int j=col-1;j>=0;j--)
            {
                if(Matriz[i][j] !=0 )
                {
                    temp[k--]=Matriz[i][j];
                }
            }

            for(int j=col-1;j>0;j--)
            {
                if(temp[j]==temp[j-1]&& temp[j]!=0)
                {
                    temp[j] *=2;
                    *score +=temp[j];
                    temp[j-1]=0;
                }
            }

            k=col-1;

            for(int j =col-1;j>=0;j--)
            {
                if(temp[j]!=0)
                {
                    temp[k--]=temp[j];
                }
            }

            while (k>=0)
            {
                temp[k--]=0;
            }

            for(int j=0;j<col;j++)
            {
                Matriz[i][j]=temp[j];
            }

        }
    }

    void movEsquerda(int **Matriz,int lin,int col, int *score)//função para movimentar os números nas linhas da direita para esquerda
    {
        for(int i=0;i<lin;i++)
        {
            int temp[col];
            int k=0;

            for(int j=0;j<col;j++)//array temporário
            {
                temp[j]=0;
            }

            for(int j=0;j<col;j++)/*faz a verificação començando da esquerda para a direita versificando se 
            os numeros diferentes de 0 passam para o arryz temporário ex:[0,2,2,8], linha da matriz temp[2,2,8]*/
            {
                if(Matriz[i][j] !=0)
                {
                    temp[k++]=Matriz[i][j];
                }
            }

            for(int j=0;j<col-1;j++)// soma se o primeiro numero for igual da segunda, seguindo o ex a linha ficaria [4,0,8]
            {
                if(temp[j]==temp[j+1]&& temp[j] != 0)
                {
                    temp[j] *=2;
                    *score +=temp[j];
                    temp[j+1]=0;
                }
            }
            k=0;

            for(int j=0;j<col;j++)// alinha deixando [4,8,0]
            {
                if(temp[j] !=0)
                {
                    temp[k++]= temp[j];
                }
            }
            while(k<col)//completa os numeros restantes com 0 [4,8,0,0]
            {
                temp[k++]=0;
            }

            for(int j=0;j<col;j++)//passa para a matriz do jogo
            {
                Matriz[i][j]=temp[j];
            }
        }
    }

    bool validarMovimento(int **Matriz, int lin, int col, char direcao)//verificar se o movimento é possível
    {
        int **tempMatriz= (int **)malloc(lin *sizeof(int*));//Matriz temporaria pra simular
        
        for(int i=0;i<lin;i++)
        {
            tempMatriz[i]=(int*)malloc(col *sizeof(int));
            memcpy(tempMatriz[i], Matriz[i],col * sizeof(int));//Copia a matriz original
        }

        int score=0;
        switch(direcao)//a depender da direção escolhida irá simular a direção
        {
            case 'w':
            case 'W':
                  movCima(tempMatriz,lin,col,&score);
                  break;
            case 's':
            case 'S':
                  movBaixo(tempMatriz,lin,col,&score);
                  break;
            case 'd':
            case 'D':
                  movDireita(tempMatriz,lin,col,&score);
                  break;
            case 'a':
            case 'A':
                  movEsquerda(tempMatriz,lin,col,&score);
                  break;
            default:
                  printf("Direção inválida");
                  return false;      
        }

        bool movimentoValido = false;
        for(int i=0;i<lin;i++)//se o resultado da matriz simulada for diferente ao da matriz origininal o movimento é possível, pois se não mudasse os números de lugar o movimento seria inválido
        {
            for(int j=0;j<col;j++)
            {
                if(tempMatriz[i][j]!= Matriz[i][j])
                {
                    movimentoValido=true;
                    break;
                }
            }
            if(movimentoValido) break;
        }

        for(int i=0;i<lin;i++)//libera matriz
        {
            free(tempMatriz[i]);
        }
        free(tempMatriz);

        return movimentoValido;
    }

    bool vitoria(int **Matriz,int lin,int col)//função para indicar vitória
    {
        for(int i=0;i<lin;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(Matriz[i][j]==2048)
                {
                    printf("Parabéns você venceu!\n");
                    return true;

                }
            }
        }
        return false;
    }

    bool derrota(int **Matriz,int lin,int col)//função para indicar derrota
    {
        if(matrizCheia(Matriz, lin,col))// se não há mais movimentações possíveis e a matriz está cheia, significa que o jogador perdeu
        {
            if(!validarMovimento(Matriz,lin,col, 'w')&&
               !validarMovimento(Matriz,lin,col, 's')&&
               !validarMovimento(Matriz,lin,col, 'd')&&
               !validarMovimento(Matriz,lin,col, 'a'))
               {
                printf("Voce perdeu, não há mais movimentaçôes possíveis");
                return true;
               }
        }
        return false;
    }

    void movimentar(int **Matriz,int lin,int col, int * score)//função para movimentar os números, verificando se é possível realizar a movimentação
    {
        printf("Digite uma tecla: W para cima- S para baixo -D para direita- A para esquerda- Q para sair: \n");
        char escolha;
        escolha =getche();
        printf("\n\n");
        fflush(stdin);

        bool movimentoValido= false;

        switch(escolha)
        {
            case 'w':
            case 'W':
              if(validarMovimento(Matriz,lin,col, 'w'))
              {
                movCima(Matriz,lin,col, score);
                movimentoValido =true;
              }
              break;
            case 's':
            case 'S':
              if(validarMovimento(Matriz,lin,col, 's'))
              {
                movBaixo(Matriz,lin,col, score);
                movimentoValido =true;
              }
              break;
            case 'd':
            case 'D':
              if(validarMovimento(Matriz,lin,col, 'd'))
              {
                movDireita(Matriz,lin,col, score);
                movimentoValido =true;
              }
              break;
            case 'a':
            case 'A':
              if(validarMovimento(Matriz,lin,col, 'a'))
              {
                movEsquerda(Matriz,lin,col, score);
                movimentoValido =true;
              }
              break;
            case 'q':
            case 'Q':
              printf("Jogo encerrado.\n");
              exit(0);
              break;
            default :
              printf("Tecla inválida.\n");
              movimentoValido=false;
        }

        if(movimentoValido)
        {
            gerarNumeros(Matriz);
        } else
        {
            printf("Movimento inválido\n");
        }
        
    }

   void regras()//regras do jogo
    {
        printf("\n==== Regras do Jogo 2048====\n");
        printf("1. O objetivo do jogo é alcançar o número 2048 somando blocos de valores iguais.\n");
        printf("2. Você pode mover os blocos para cima, baixo, esquerda ou direita, usando as teclas W/S/A/D.\n");
        printf("3. Após cada movimento, um bloco de valor 2 ou 4 será gerado numa posição aleatória no jogo.\n");
        printf("4. Se nenhum bloco poder se movimentar para a direção escolhida, aquele movimento não é válido\n");
        printf("5. Se a matriz estiver cheia e não haver mais movimentos válidos, o jogo se encerra.\n");
        printf("6. Pressione 'Q' para sair do jogo a qualquer momento.\n");
        printf("================================\n\n");
    }

   void iniciarJogo()//loop do jogo
    {
        int colunas=4;
        int linhas=4;
        int score =0;//passará com ponteiro 
        int **Matriz=(int **)malloc(sizeof(int*)*linhas);
        if(Matriz ==NULL)
        {
            printf("Erro ao alocar memoria das linhas.");
            return;
        }
        
        for(int i=0;i<linhas;i++)
        {
        Matriz[i]=(int *)malloc(sizeof(int)* colunas);
        if(Matriz[i]==NULL)
        {
            printf("Erro ao alocar memoria das colunas");
            return;
        }
        }
        
        srand(time(NULL));
        
        inicializarMatriz(Matriz,linhas,colunas);
        printf("Jogo Inicializado:\n");
        gerarNumeros(Matriz);
        gerarNumeros(Matriz);
        while(1)
        {
            system("cls");
            printf("Score:%d\n",score);
            imprimirMatriz(Matriz,linhas,colunas);
            movimentar(Matriz,linhas,colunas,& score);
            if(vitoria(Matriz,linhas, colunas))
            {
                imprimirMatriz(Matriz,linhas,colunas);
                printf("Seu score foi: %d", score);
                break;
            }
            if(derrota(Matriz,linhas,colunas))
            {
                imprimirMatriz(Matriz,linhas,colunas);
                printf("Seu score foi: %d", score);
                break;
            }
        }
        
        for (int i = 0; i < linhas; i++)
        {
            free(Matriz[i]);
        }
        free(Matriz);
    
    }

   void menu()//menu inicial do jogo
    {
        int escolha;
        while(1)
        {
            printf("Bem-vindo ao jogo 2048!\n");
            printf("Escolha uma opção:\n");
            printf("1. Iniciar jogo.\n");
            printf("2. Regras.\n");
            printf("3. Sair.\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);
            fflush(stdin);

            switch(escolha)
        {
            case 1:
                printf("\n Iniciando o jogo...\n");
                iniciarJogo();
                return;
            case 2:
                regras();
                break;
            case 3:
                printf("\nSaindo do jogo...\n");
                exit(0);
            default:
                printf("Opção inválida, tente novamente.\n\n");
                break;        
        }
        }
    }

    int main()
    {
        menu();
        return 0;
    }