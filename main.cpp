#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Matriz.h"

using namespace std;

//1 - Desenvolver um TAD para matrizes diagonais.
//Gerar valores aleatorios: RAND rand()%(maior-menor+1) + menor;
//Apagar tela: system("cls");
//2 - Desenvolver um TAD para matrizes triangulares superiores
//3 - Desenvolver um TAD para matrizes simetricas (Os valores opostos a diagonal principal são iguais).
//4 - Desenvolver um TAD para matrizes anti-simetricas.
//5 - Desenvolver um TAD para matrizes tridiagonais.

int main()
{
    int i, j, x, nl=5, nc=5;
    float n;
    Matriz c(nl,nc);
    srand( (unsigned)time(NULL) );
    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
        {
            c.set(i,j,rand()%(100-(-100)+1) + (-100));
        }
    }
    for(i=0; i<12; i++)
    {
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "\tMENU:" << endl;
        cout << "1 = Matriz Transposta" << endl;
        cout << "2 = Diagonal Principal" << endl;
        cout << "3 = Triangular superior" << endl;
        cout << "4 = Simetrica" << endl;
        cout << "5 = Anti-Simetrica" << endl;
        cout << "6 = Tridiagonal" << endl;
        cout << "7 = N* a Matriz" << endl;
        cout << "8 = Media das linhas da Matriz" << endl;
        cout << "9 = Maior Nas linhas pares e Menor nas impares" << endl;
        cout << "10 = Valores Acima da media em cada linha" << endl;
        cout << "11 = Ordenacao" << endl;
        cout << "0 = SAIR" << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
        cout << "Digite a opcao desejada:   ";
        cin >> x;

        switch (x)
        {
        case 0:
            system("cls");
            return 0;
        case 1:
            system("cls");
            cout << "Matriz Original: " << endl;
            c.imprimeoriginal();
            c.copiadora();
            cout << "Matriz Transposta: " << endl;
            c.transposta();
            c.imprimecopia();
            cout << "Representacao Linear: " << endl;
            c.imprimelinear();
            c.apagadora();
            break;
        case 2:
            system("cls");
            cout << "Matriz Original: " << endl;
            c.imprimeoriginal();
            c.copiadora();
            cout << "Matriz Diagonal: " << endl;
            c.diagonalizadora();
            c.imprimecopia();
            cout << "Representacao Linear: " << endl;
            c.imprimelinear();
            c.apagadora();
            break;
        case 3:
            system("cls");
            cout << "Matriz Original: " << endl;
            c.imprimeoriginal();
            c.copiadora();
            cout << "Matriz Triangular superior: " << endl;
            c.trianSup();
            c.imprimecopia();
            cout << "Representacao Linear: " << endl;
            c.imprimelinear();
            c.apagadora();
            break;
        case 4:
            system("cls");
            cout << "Matriz Original: " << endl;
            c.imprimeoriginal();
            c.copiadora();
            cout << "Matriz Simetrica: " << endl;
            c.verificasimetria();
            c.imprimecopia();
            cout << "Representacao Linear: " << endl;
            c.imprimelinear();
            c.apagadora();
            break;
        case 5:
            system("cls");
            cout << "Matriz Original: " << endl;
            c.imprimeoriginal();
            c.copiadora();
            cout << "Matriz Anti-Simetrica: " << endl;
            c.antisimetrica();
            c.imprimecopia();
            cout << "Representacao Linear: " << endl;
            c.imprimelinear();
            c.apagadora();
            break;
        case 6:
            system("cls");
            cout << "Matriz Original: " << endl;
            c.imprimeoriginal();
            c.copiadora();
            cout << "Matriz Tridiagonal: " << endl;
            c.tridiagonal();
            c.imprimecopia();
            cout << "Representacao Linear: " << endl;
            c.imprimelinear();
            c.apagadora();
            break;
        case 7:
            system("cls");
            cout << "Digite um valor para n:";
            cin >> n;
            system("cls");
            cout << "Matriz Original: " << endl;
            c.imprimeoriginal();
            c.copiadora();
            cout << n << " * Matriz Original:" << endl;
            c.operadora(n);
            c.imprimecopia();
            cout << "Representacao Linear: " << endl;
            c.imprimelinear();
            c.apagadora();
            break;
        case 8:
            system("cls");
            cout << "Matriz Original: " << endl;
            c.imprimeoriginal();
            c.copiadora();
            cout << "Media de cada linha da matriz:" << endl;
            c.mediadora();
            c.imprimecopia();
            cout << "Representacao Linear: " << endl;
            c.imprimelinear();
            c.apagadora();
            break;
        case 9:
            system("cls");
            cout << "Matriz Original: " << endl;
            c.imprimeoriginal();
            c.copiadora();
            cout << "Maior Nas linhas pares e Menor nas impares:" << endl;
            c.maiorMenor();
            c.imprimecopia();
            cout << "Representacao Linear: " << endl;
            c.imprimelinear();
            c.apagadora();
            break;
        case 10:
            system("cls");
            cout << "Matriz Original: " << endl;
            c.imprimeoriginal();
            c.copiadora();
            cout << "Valores acima da media de cada linha:" << endl;
            c.acimaMedia();
            c.imprimecopia();
            cout << "Representacao Linear: " << endl;
            c.imprimelinear();
            c.apagadora();
            break;
        case 11:
            system("cls");
            cout << "Matriz Original: " << endl;
            c.imprimeoriginal();
            c.copiadora();
            cout << "Matriz Ordenada:" << endl;
            c.ordenadora();
            c.imprimecopia();
            cout << "Representacao Linear: " << endl;
            c.imprimelinear();
            c.apagadora();
            break;
        default:
            cout << "Codigo invalido! Tente Novamente!!!!!" << endl << endl << endl;
            break;
        }

    }
    return 0;
}
