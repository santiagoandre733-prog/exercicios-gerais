#include <stdio.h>
#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"

int main(){
    int n;
    printf("Digite o numero de tarefas: ");
    scanf("%d ", &n);
    tAgendaTarefas *tarefas = CriaAgendaDeTarefas(n);
    int i;
    for(i = 0; i < n; i++){
        int prio;
        char c;
        scanf("%d %c ", &prio, &c);
        if(c == 'I'){
            char msg[50];
            scanf("%[^\n]\n", msg);
            tImpr* tarefa = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(tarefas, prio, (void*)tarefa, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        }
        else if(c == 'S'){
            float n1, n2;
            scanf("%f %f ", &n1, &n2);
            tSoma* tarefa = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(tarefas, prio, (void*)tarefa, ExecutaTarefaSoma, DestroiTarefaSoma);
        }
        else if(c == 'M'){
            float n1, n2;
            scanf("%f %f ", &n1, &n2);
            tMult* tarefa = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(tarefas, prio, (void*)tarefa, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        }
        else {
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            scanf("%*[^\n]\n");
            i--;
        }
    }

    ExecutarTarefasDaAgenda(tarefas);
    DestroiAgendaDeTarefas(tarefas);

    return 0;
}