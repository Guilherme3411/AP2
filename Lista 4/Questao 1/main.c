#include <stdio.h>
#include <stdlib.h>
int main()
{
    typedef struct
    {
        char texto[500];
        int contador;
    } Texto;

    Texto t1;
    FILE*arquivo;
    if(arquivo==NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    arquivo=fopen("saida.txt","w");
    fprintf(arquivo,"Papai deixou uma heranca bem gorda pra mim\nTem terra pra plantar e pra criar uns gadin\nMas eu me dei conta que isso nao e pra mim\nPrefiro pe na areia do que pe no capim\nDe tanque cheio a Bodona\nO Cowboy 'ta sem vergonha\nHoje eu saio da zona rural\nEu 'to bicho solto no pique lobo mau\nMeu ano so comeca depois do carnaval\nNos vai descer, vai descer\nDescer la pra BC no finalzin' do ano\nOs bombonzin' 'tao brozeando pra eu chegar e morder\nNos vai descer, vai descer\nDescer la pra BC no finalzin' do ano\nOs Cowboy vai litorando e vai torar voce\nNos vai descer, vai descer\nDescer la pra BC no finalzin' do ano\nOs bombonzin' 'tao brozeando pra eu chegar e morder\nNos vai descer, vai descer\nDescer la pra BC no finalzin' do ano\nOs Cowboy vai litorando e vai torar voce, eh eh\n");
    fclose(arquivo);

    arquivo=fopen("saida.txt","r");
    while (fgets(t1.texto, sizeof(t1.texto),arquivo) !=NULL)
    {
        printf("%s",t1.texto);
    }
    fclose(arquivo);
    if(arquivo==NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    arquivo=fopen("saida.txt","a");
    fprintf(arquivo,"\nE Brenno & Matheus\nE DJ Ari SL (eu disse DJ Ari SL)\nDe tanque cheio a Bodona\nO Cowboy 'ta sem vergonha\nHoje eu saio da zona rural\nEu 'to bicho solto no pique lobo mau\nMeu ano so comeca depois do carnaval\nNos vai descer, vai descer\nDescer la pra BC no finalzin' do ano\nOs bombonzin' 'tao brozeando pra eu chegar e morder\nNos vai descer, vai descer\nDescer la pra BC no finalzin' do ano\nOs Cowboy vai litorando e vai torar voce\nNos vai descer, vai descer\nDescer la pra BC no finalzin' do ano\nOs bombonzin' 'tao brozeando pra eu chegar e morder\nNos vai descer, vai descer\nDescer la pra BC no finalzin' do ano\nOs Cowboy vai litorando e vai torar voce, eh eh\n");
    fclose(arquivo);

    arquivo=fopen("saida.txt","r");
    while (fgets(t1.texto, sizeof(t1.texto),arquivo) !=NULL)
    {
        printf("%s",t1.texto);
    }
    fclose(arquivo);
    arquivo=fopen("saida.txt","r");
    while (fgets(t1.texto, sizeof(t1.texto),arquivo) !=NULL)
    {
        t1.contador += strlen(t1.texto);
    }
    printf("\nNumero de caraquiteres e %d \n",t1.contador);
    fclose(arquivo);

}

