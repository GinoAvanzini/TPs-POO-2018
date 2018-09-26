

/*Se ingresa el orden de una matriz cuadrada y el máximo valor que pueden tomar  
 * los números aleatorios que genera el programa y guarda en dicha matriz. Se 
 * generan dos vectores conteniendo los valores de las diagonales principal y 
 * secundaria. Se imprime todo por pantalla.
 */


#include <iostream>
//using namespace std;

#include <random>
//using namespace std;

#include <chrono>
using namespace std;


//Imprime por pantalla un vector
void impr_array(int vector[], int len){
    for (int i = 0; i<len; i++){
        cout << vector[i] << "\t";
    }
    cout << endl;
}


void ej_2(){
    
    //Semilla y generador de numeros aleatorios
    //http://www.cplusplus.com/reference/random/uniform_int_distribution/operator()/
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
 
    int orden, Max;
    
    do{
        cout << "Ingrese el orden de la matriz, entre 3 y 10:" << endl;
        cin >> orden;
    }while(orden < 3 || orden > 10);
    
    
    cout << "Ingrese Max:" << endl;
    cin >> Max;
    cout << endl;
    
    //Distribucion y rango de los numeros aleatorios
    uniform_int_distribution<int> entero(1,Max);
    
    //Declaracion matriz y vectores diagonal
    int matriz[orden][orden], diag_ppal[orden], diag_sec[orden];
    
    int i, j;
    for (i = 0; i<orden; i++){
        for (int j = 0; j<orden;j++){
            matriz[i][j] = entero(generator);
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    
    for (i = 0; i<orden; i++){
        diag_ppal[i] = matriz[i][i];
        diag_sec[i] = matriz[i][orden - 1 - i]; //
    }
    
    cout << endl << "\nDiagonal principal:\n";
    impr_array(diag_ppal, orden);
    cout << endl << "\nDiagonal secundaria:\n";
    impr_array(diag_sec, orden);
}
