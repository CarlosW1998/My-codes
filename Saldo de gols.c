#include<stdio.h>

int main ()
{
    int p, gf, gs;
    int a, b, c, d, k;
    int sdg, cont, auxi;
    int i, f;
    k = 0;

    scanf("%d", &p);

    while(p != 0)
    {
        i = -1;
        sdg = 0;
        cont = 0;
        f = 0;
        auxi = 1;

        for(a = 0; a < p; a++)
        {
            scanf("%d%d", &gf, &gs);

            cont += (gf-gs);

           // printf("%d %d %d %d\n", f, auxi, f, i);
            if(cont < 0)
            {
                auxi = a+2;
                cont = 0;
            }
            else if(cont > 0 && (cont > sdg || (sdg == cont && (a+1)-auxi >= f-i)))
            {
                sdg = cont;
                i = auxi;
                f = a+1;
            }
        }
        k++;
        printf("Teste %d\n", k);
        if(f != 0)
        {
            printf("%d %d\n", i, f);
        }
        else
        {
            printf("nenhum\n");
        }
        printf("\n");

        scanf("%d", &p);
    }

    return 0;
}
