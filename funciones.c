#include "funciones.h"

int aleatorioEntre(int mini, int maxi)
{
    return mini + rand()%(maxi-mini+1);
}

void cargarVectorConAleatorios(int v[], int tam, int mini, int maxi)
{
    int aleatorio = 0;

    for (int i = 0; i < tam; i++)
    {
        aleatorio = aleatorioEntre(mini, maxi);
        v[i] = aleatorio;
    }
}

void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi)
{
    int aleatorio = 0;

    for (int i = 0; i < tam; i++)
    {//antes de asignar el numero aleatorio pasamos por los numeros ya generados para comprobar que no se repitan
        aleatorio = aleatorioEntre(mini, maxi);

        for(int j = 0; j < i; j++)
        {

            if (v[j] == aleatorio)
            {//si se encontro un numero repetido volvemos a generar un numero aleatorio y volvemos a comprobar el vector
                aleatorio = aleatorioEntre(mini, maxi);
                j = 0;
            }
        }

        v[i] = aleatorio;
    }
}
//----------------carga de carton y muestra del mismo----------------------------------
void asignarCartones(int v[MAXCARTONES][FILAS][COLUMNAS], int cant)
{

    for (int i = 0; i < cant; i++)
    {
        int tempvector[FILAS*COLUMNAS];
        cargarVectorConAleatoriosSinRepetir(tempvector,FILAS*COLUMNAS,1,BOLITAS);

        for(int j = 0; j < FILAS; j++)
        {
            for (int k = 0; k < COLUMNAS; k++)
            {
                v[i][j][k] = tempvector[j*COLUMNAS + k];
            }

        }
    }
}

void dibujarCartones(int v[MAXCARTONES][FILAS][COLUMNAS], int cant)
{
    for (int i = 0; i< cant; i++)
    {
        dibujarCarton(v,i);
    }
}

void dibujarCarton(int v[MAXCARTONES][FILAS][COLUMNAS], int num)
{
    printf("------------------\n");
    printf("|    CARTON %d    |\n", num + 1);
    printf("------------------\n");

    for(int i = 0; i < FILAS; i++)
    {
        printf("| ");

        for (int j = 0; j < COLUMNAS; j++)
        {
            if (v[num][i][j] < 10)//si es menor a 10 dibujamos un 0 para que todos los numeros tengan 2 cifras
            {
                printf("0");
            }
            printf("%d ", v[num][i][j]);
        }
        printf("|\n");
    }
    printf("------------------\n");
}

//---------------------------bolitas------------------------------------------------
void generarBolitas(int v[]){
    for(int i = 0; i < BOLITAS; i++){
        cargarVectorConAleatoriosSinRepetir(v,BOLITAS,1,BOLITAS);
    }
}

void mostrarBolitas(int v[])
{
    for(int i = 0; i < BOLITAS; i++)
    {
        printf("     ___________        \n");
        printf("    |           |       \n");
        printf("    |           |       \n");

        printf("    |     ");
        if (v[i]< 10) printf("0");
        printf("%d    |       \n",v[i]);

        printf("    |           |       \n");
        printf("    |___________|       \n");
    }
    printf("\n\n\n");
    }

//-----------------------busqueda y marca de numeros---------------------------------

int busquedaDeNumero(int mat[][FILAS][COLUMNAS],int n, int num)
{
    int posReglon = -1, posFila = -1, rpt = 0;

    for(int i=0; i < FILAS; i++)
    {
        for(int j=0;j<COLUMNAS;j++)
        {
            if(mat[n][i][j] == num)
            {
                posReglon = i;
                posFila = j;
            }
        }
    }
    rpt = posFila*10 + posReglon;
    return rpt;
}

//------------------------------------struct-----------------------------------------
struct Jugador IngresarJugadorPorTeclado(struct Jugador j1){

    struct Carton Jcarton;
    char aux[50]=" ";

    printf("\nIngresa tu nombre y tu apellido\n");
    fflush(stdin);
    gets(aux);
    strcpy(j1.nombreyApellido, aux);

    printf("\nIngresa tu DNI\n");
    scanf("%lf",&j1.dni);

    j1.puntaje=0;

    FILE * punteroArchivoJugador;
    punteroArchivoJugador = fopen("ArchivoJugador", "a");

    fprintf(punteroArchivoJugador, "j1");

    fclose(punteroArchivoJugador);

    return j1;
};



struct Carton formadorDeCartonesEnEstruct(int cartonGuardado[MAXCARTONES][FILAS][COLUMNAS],int CaCarton){

    struct Carton c1;

           asignarCartones(c1.Cartones,CaCarton);
            dibujarCartones(c1.Cartones,CaCarton);

            return c1;
};

