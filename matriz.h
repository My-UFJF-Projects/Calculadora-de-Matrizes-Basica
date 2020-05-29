class Matriz
{
public:
    Matriz(int l, int c);
    ~Matriz();

    float getoriginal(int i, int j);
    float getcopia(int i, int j);
    void set(int i, int j, float valor);

    void copiadora();
    void transposta();
    void diagonalizadora();
    void trianSup();
    void verificasimetria();
    void antisimetrica();
    void tridiagonal();
    void operadora(float n);
    void mediadora();
    void maiorMenor();
    void acimaMedia();
    void ordenadora();

    void imprimeoriginal();
    void imprimecopia();
    void imprimelinear();

    void apagadora();

private:
    int nl,nc;
    float **mat;
    float **copia;
    float *linear;
};

