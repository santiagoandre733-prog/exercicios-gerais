#include <stdio.h>
#include "relatorio.h"
#include "aluno.h"

int main(){
    Vector *v = VectorConstruct();
    int n, i;
    scanf("%d ", &n);
    for(i = 0; i < n; i++){
        tAluno *a = CriaAluno();
        LeAluno(a);
        VectorPushBack(v, (data_type)a);
    }

    ImprimeRelatorio(v);
    VectorDestroy(v, DestroiAluno);
    return 0;
}