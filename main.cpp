#include <iostream>
#include <stdlib.h>
using namespace std;

void InicializarMatriz(float matriz[3][7])
{

    for(int i=0; i < 3; i++)
    {
        for (int j=0; j<7; j++)
        {
            matriz[i][j]=10;
        }
    }

}

void Despachar(float matriz[3][7], int tipo, float cantidad)
{
    float disponibilidad=matriz[0][tipo];
    if(disponibilidad> cantidad)
    {
        matriz[0][tipo] -= cantidad;
    }
    else
    {
        float valor= matriz[0][tipo];
        matriz[0][tipo]=0;
        cout << "La cantidad pedida supera la cantidad del barril. Se despachara " << valor << "Lts." << endl;
    }



}

void MostrarxTipo( float matriz[3][7])
{
    int cerveza;
    cout << "Ingrese el tipo de cerveza que desea ver su cantidad disponible: ";
    cin >> cerveza;
    float disponibilidad = matriz[0][cerveza];
    cout << "Cantidad disponible de cerveza [tipo "<< cerveza <<"]:  " << disponibilidad <<"Lts." << endl;

}

void AscenderBarril(float matriz[3][7], int tipo)
{
    if(matriz[0][tipo]==0)
    {
        float aux=matriz[0][tipo];
        matriz[0][tipo]=matriz[1][tipo];
        matriz[1][tipo]=matriz[2][tipo];
        matriz[2][tipo]=aux;

    }
    else
    {
        cout << "El barril de cerveza [tipo "<< tipo<<"] todavia no esta vacio"<<endl;
    }
}

void MostrarBarriles(float matriz[3][7])
{
    cout << " -----------------------------     BARRILES DE CERVEZA    ------------------------------"<<endl;
    for(int k=0; k<7;k++){
        cout<< "    "<<k<< "      ";
    }
    cout << endl;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<7; j++)
        {   cout <<" ";
            cout << matriz[i][j]<<" Lts. ";
            cout<<"  ";

        }
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------------------"<<endl;
}
int main()
{
    //Inicializacion de matriz.
    float Cervezas[3][7];
    InicializarMatriz(Cervezas);


    //Menu
    int op;
    int tipo;
    float cantidad;

    do
    {
        cout << "------- Menu principal -------" << endl;
        cout <<"1. Despachar litros de un tipo de cerveza (0-6)" << endl << "2. Mostrar cantidad por tipo de cerveza" <<
             endl << "3. Ascender barril" << endl << "4. Mostrar Estado de Barriles" << endl << "0. SALIR" << endl;
        cin >> op;



        switch(op)
        {

        case 1:
            system("cls");
            cout << "OPERACION: 1 - DESPACHAR CERVEZA" << endl;
            cout << "CERVEZAS" << endl << "0. Lager" << endl << "1. Ipa" << endl << "2. Trigo" << endl << "3. Dark Lager" << endl << "4. Stout" << endl<< "5. Amber" << endl <<"6. Pilsner" << endl;
            cout << "Ingrese el tipo de cerveza que desea despachar:  ";
            cin >> tipo;

            cout << "Ingrese la cantidad de cerveza a despachar: ";
            cin >> cantidad;
            Despachar(Cervezas, tipo, cantidad);

            MostrarBarriles(Cervezas);
            break;

        case 2:
            system("cls");
            cout << "OPERACION: 2 - MOSTRAR CANTIDAD DE CERVEZA X TIPO SELECCIONADO" << endl;
            MostrarxTipo(Cervezas);
            break;

        case 3:
            system("cls");
            int cerveza;
            cout << "OPERACION: 3 - ASCENDER BARRIL" << endl;
            cout << "Ingrese el tipo de cerveza [0-6] para ascender su barril: ";
            cin >> cerveza;
            AscenderBarril(Cervezas, cerveza);
            MostrarBarriles(Cervezas);

            break;
        case 4:
            MostrarBarriles(Cervezas);
            break;
        default:
            break;


        }
    }
    while(op !=0);
    cout << "Saliendo del programa!";

}
