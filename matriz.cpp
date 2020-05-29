#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Matriz.h"

using namespace std;

Matriz::Matriz(int l, int c)
{
    nl=l;
    nc=c;
    mat=new float*[nl*nc];
    copia=new float*[nl*nc];
    linear=new float[l*c];
    for(int i = 0; i < nl; i++)
    {
        mat[i] = new float[nc];
        copia[i] = new float[nc];                                  //Aloca nc valores para cada linha da matriz!
        //cout << "Mat["<<i<<"]["<<nc<<"]=Alocou!" << endl;      //Mostra quantos valores foram alocados nessa linha da matriz!
    }
}

float Matriz::getoriginal(int i, int j)
{
    return mat[i][j];
}

float Matriz::getcopia(int i, int j)
{
    return mat[i][j];
}

void Matriz::set(int i, int j, float valor)
{
    mat[i][j]=valor;
    //cout << "mat[" << i << "][" << j << "]=" << mat[i][j] << endl;
}

void Matriz::copiadora()
{
    for(int i=0; i<nl; i++)
    {
        for(int j=0; j<nc; j++)
        {
            copia[i][j]=mat[i][j];
        }
    }
}

void Matriz::transposta()
{
    int i,j,k;
    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
        {
            k=i*nc+j;
            copia[i][j]=mat[j][i];
            linear[k]=mat[j][i];
        }
    }
}

void Matriz::diagonalizadora()
{
    int i,j,k;
    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
        {
            k=i*nc+j;
            if(i==j)
            {
                copia[i][j]=mat[i][j];
                linear[k]=mat[i][j];
            }
            else
            {
                copia[i][j]=0;
                linear[k]=0;
            }
        }
    }
}

void Matriz::trianSup()
{
    int i,j,k;
    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
        {
            k=i*nc+j;
            if(i<=j)
            {
                copia[i][j]=mat[i][j];
                linear[k]=mat[i][j];
            }
            else
            {
                copia[i][j]=0;
                linear[k]=0;
            }
        }
    }
}

void Matriz::verificasimetria()
{
    int i,j,k;
    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
        {
            if(i!=j)
            {
                k=i*nc+j;
                if(mat[i][j]==mat[j][i])
                {
                    copia[i][j]=mat[i][j];
                    linear[k]=mat[i][j];
                }
                else
                {
                    copia[i][j]=0;
                    linear[k]=0;
                }
            }
        }
    }
}

void Matriz::antisimetrica()
{
    int i,j,k;
    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
        {
            if(i!=j)
            {
                k=i*nc+j;
                if(mat[i][j]==-mat[j][i])
                {
                    copia[i][j]=mat[i][j];
                    linear[k]=mat[i][j];
                }
                else
                {
                    copia[i][j]=0;
                    linear[k]=0;
                }
            }
            else
                copia[i][j]=0;
        }
    }
}

void Matriz::tridiagonal()
{
    int i,j,k;
    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
        {
            k=i*nc+j;
            if(i==j || i-j==-1 || i-j==1)
            {
                copia[i][j]=mat[i][j];
                linear[k]=mat[i][j];
            }
            else
            {
                copia[i][j]=0;
                linear[k]=0;
            }
        }
    }
}

void Matriz::operadora(float n)
{
    int i,j,k;
    for(i=0; i<nl; i++)
    {
        for(j=0; j<nc; j++)
        {
            k=i*nc+j;
            copia[i][j]=n*mat[i][j];
            linear[k]=n*mat[i][j];
        }
    }
}

void Matriz::mediadora()
{
    int i,j,k;
    float media,soma=0;
    for(i=0; i<nl; i++)
    {
        for(k=0; k<nc; k++)
        {
            soma+=mat[i][k];
        }
        media=soma/nc;

        for(j=0; j<nc; j++)
        {
            k=i*nc+j;
            if (i==j)
            {
                copia[i][j]=media;
                linear[k]=media;
            }
            else
            {
                copia[i][j]=0;
                linear[k]=0;
            }
        }
    }
}

void Matriz::maiorMenor()
{
    int i,j,k,maior,menor;
    for(i=0; i<nl; i++)
    {
        if (i%2==0)
        {
            maior=mat[i][0];
            for(j=0; j<nc; j++)
            {

                if (maior<mat[i][j])
                    maior=mat[i][j];
            }
            for(j=0; j<nc; j++)
            {
                k=i*nc+j;
                copia[i][j]=maior;
                linear[k]=maior;
            }
        }
        else
        {
            menor=mat[i][0];
            for(j=0; j<nc; j++)
            {
                if (menor>mat[i][j])
                    menor=mat[i][j];
            }
            for(j=0; j<nc; j++)
            {
                k=i*nc+j;
                copia[i][j]=menor;
                linear[k]=menor;
            }
        }
    }
}

void Matriz::acimaMedia()
{
    int i,j,k;
    float soma=0, media;
    for(i=0; i<nl; i++)
    {
        for(k=0; k<nc; k++)
        {
            soma+=mat[i][k];
        }
        media=soma/nc;

        for(j=0; j<nc; j++)
        {
            k=i*nc+j;
            if (mat[i][j]>=media)
            {
                copia[i][j]=mat[i][j];
                linear[k]=mat[i][j];
            }
            else
            {
                copia[i][j]=0;
                linear[k]=0;
            }
        }
    }
}

void Matriz::ordenadora ()
{
    int i, j, l, c, aux, k;
    for (i = 0; i < nl; i++)
    {
        for (j = 0; j < nc; j++)
        {
            for (l = 0; l < nl; l++)
            {
                for (c = 0; c < nc; c++)
                {
                    if (copia[i][j] < copia[l][c])
                    {
                        aux = copia[i][j];
                        copia[i][j] = copia[l][c];
                        copia[l][c] = aux;
                    }
                }
            }
        }
    }
    for (i = 0; i < nl; i++)
    {
        for (j = 0; j < nc; j++)
        {
            k=i*nc+j;
            linear[k]=copia[i][j];
        }
    }
}

void Matriz::imprimeoriginal()
{
    cout << endl;
    for(int i=0; i<nl; i++)
    {
        for(int j=0; j<nc; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Matriz::imprimecopia()
{
    cout << endl;
    for(int i=0; i<nl; i++)
    {
        for(int j=0; j<nc; j++)
        {
            cout << copia[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void Matriz::imprimelinear()
{
    cout << endl;
    for(int i=0; i<nc*nl; i++)
    {
        cout << linear[i];
        if (i<nc*nl-1)
            cout << ", ";
    }
    cout << endl;
}
void Matriz::apagadora()
{
    int opcao;
    cout << endl << endl << "Digite qualquer valor para voltar ao menu!" << endl;
    cin >> opcao;
    system("cls");
}


Matriz::~Matriz()
{
// desaloca a memoria alocada no construtor
    for(int i = 0; i < nl; i++)
        delete [] mat[i];
    delete [] mat;
}
