#include <iostream>

using namespace std;


/* Definindo valores constantes para criacao da matriz */
const int num_de_times=20;

const int num_de_partida=38;

struct times
{
    string time;
    int total_pontos;
};

/* Definindo as funcoes principais do codigo */
void atribuindo_times(times tabela[],int num_de_times){
    for (int time = 0; time < num_de_times; time++)
    {
        cout<<"digite o nome do "<<time+1<<"° time: ";
        cin>>tabela[time].time;
    }
    cout<<endl;
}

void pontuacao_times_por_partida(times tabela[],int tabela_de_pontos[num_de_times][num_de_partida],int num_de_times,int num_de_partida){

    int pontos=0;
    char pergunta;
    while (pontos<num_de_times){   
        int partida=0;
        while (partida<num_de_partida){

            // Usado While para contemplar todos os casos, incluindo os que o usuario erra o valor, atribuindo os valores das devidas pontuacoes diretamente na matriz | v = 3 , e = 1 , p = 0
               cout<<"se o time "<<tabela[pontos].time<<" ganhou o jogo digite V\nse o time "<<tabela[pontos].time<<" empatou o jogo digite E\nse o time "<<tabela[pontos].time<<" perdeu o jogo digite P\n\ndigite qual foi a situação do o time "<<tabela[pontos].time<<" fez na partida "<<partida+1<<"° do brasileirao: ";

            cin>>pergunta;
            cout<<endl;
            if (pergunta=='v'||pergunta=='V'||pergunta=='e'||pergunta=='E'||pergunta=='p'||pergunta=='P')
            {
                if (pergunta=='v'||pergunta=='V')
                {
                    tabela_de_pontos[pontos][partida]=3;
                }
                else if (pergunta=='e'||pergunta=='E')
                {
                    tabela_de_pontos[pontos][partida]=1;
                }
                else{
                    tabela_de_pontos[pontos][partida]=0;
                }
                partida++;

                system("Cls");
            }
            else{
                cout<<"codigo não cadastrado por favor insira um dos codigos cadastrados";
                cout<<endl;
            }
        }
        pontos++;
    }
}

void somatorio(times tabela[],int tabela_de_pontos[num_de_times][num_de_partida],int num_de_times,int num_de_partias){

    for (int time = 0; time < num_de_times; time++){
    
        tabela[time].total_pontos=0;
        for (int partida = 0; partida < num_de_partias; partida++){

            tabela[time].total_pontos += tabela_de_pontos[time][partida];

        }
    }
}

void ordenar(times tabela[],int num_de_times){
    int aux1;
    string aux2;
    for (int time = 0; time < num_de_times; time++)
    {
        for (int partida = 0; partida < num_de_partida; partida++)
        {
            if (tabela[time].total_pontos>tabela[partida].total_pontos)
            {
            // Ordenando prioritariamente o valor para realizar o ajuste do time com maior pontuacao na matriz    
                aux1=tabela[partida].total_pontos;
                tabela[partida].total_pontos=tabela[time].total_pontos;
                tabela[time].total_pontos=aux1;
        
                aux2=tabela[partida].time;
                tabela[partida].time=tabela[time].time;
                tabela[time].time=aux2;
            }
        }
    }
}

void mostrar(times tabela[],int num_de_times){
    for (int time = 0; time < num_de_times; time++)
    {
        cout<<"o time "<<tabela[time].time<<" ficou em "<<time+1<<"° com um total de "<<tabela[time].total_pontos<<" pontos"<<endl;
    }
}

int main(){

    times tabela[num_de_times];

    int tabela_de_pontos[num_de_times][num_de_partida];

    atribuindo_times(tabela,num_de_times);
    pontuacao_times_por_partida(tabela,tabela_de_pontos,num_de_times,num_de_partida);
    somatorio(tabela,tabela_de_pontos,num_de_times,num_de_partida);
    ordenar(tabela,num_de_times);
    mostrar(tabela,num_de_times);

    return 0;
}