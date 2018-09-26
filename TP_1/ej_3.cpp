

/*Implementar un programa capaz de generar una matriz de orden N x M (siendo 
 * 5 ≤ N, M ≤ 14) con valores float generados al azar, en el rango de 1 a 100, 
 * y presentar al operador un menú con los siguientes servicios:
 * a. Realizar el recorrido de la matriz desde la primera celda siguiendo una 
 * secuencia en espiral horaria, hasta la última celda ubicada en el “centro”.
 * b. Listar los valores que sin componente decimal y la cantidad de ellos.
 * c. Hallar los valores de recorrido, la media aritmética, desviación media
 *  y la desviación estándar para el conjunto de datos almacenado en la matriz
 */


/*
 * ------------------------------------------------------------------------
 * IMPORTANTE:
 * ------------------------------------------------------------------------
 *  
 * En este programa la memoria para la matriz que contiene los números se ha 
 * reservado en un solo espacio contiguo de memoria (un array) y no utilizando 
 * la declaración int matriz[i][j] ni reservando dinámicamente memoria para cada
 * fila de la matriz. De esta forma se reduce el tiempo de ejecución y la 
 * memoria necesaria para correr el programa. La desventaja es que no se puede
 * utilizar la notación matriz[i][j] sino que se utilizará de forma 
 * _equivalente_ la notación [i*M + j] para acceder a la posición [i][j], siendo
 * M el ancho (cantidad de columnas) de la matriz.
 * 
 * 
 * tl;dr: matriz[i*M + j] equivale a matriz[i][j]
 * 
 */


#include <iostream>
using namespace std;

#include <random>
using namespace std;

#include <chrono>
using namespace std;

#include <vector>
using namespace std;

#include <cmath>
using namespace std;


void recorrido_espiral(float* matriz, int N, int M){
    
    int i,j;
    int len = N*M;
    float espiral[len];
    int n = 0;
    int izq = 0;
    int arriba = 0;
    int abajo = N;
    int derecha = M;
    
    while(1){
        
        //Hacia la derecha
        for (j = izq; j < derecha; j++){
            espiral[n] = matriz[arriba*M + j];
            n++;
            if(n==(len)){
                goto flag;
            }
            
        }
        arriba++;
        
        //Hacia abajo
        for (i = (arriba); i < abajo; i++){
            espiral[n] = matriz[i*M + (derecha-1)];
            n++;
            if(n==(len)){
                goto flag;
            }
        }
        derecha--;
        
        //Hacia la izquierda
        for (j = (derecha-1); j > (izq-1); j--){
            espiral[n] = matriz[(abajo-1)*M + j];
            n++;
            if(n==(len)){
                goto flag;
            }
        }
        abajo--;
        
        //Hacia arriba
        for (i = (abajo-1); i > (arriba-1); i--){
            espiral[n] = matriz[i*M + (izq)];
            n++;
            if(n==(len)){
                goto flag;
            }

        }
        izq++;
        
    }
    
    // Bandera para el goto que termina bucles anidados
    flag:
    
    for (i = 0; i < len; i++){
        cout << espiral[i] << "\t";
        cout << endl;
    }
    
}


// Valores sin componente Decimal en la Matriz
void sin_decimal(float* matriz, int N, int M){

    //Declaracion del vector que contendrá los int de la matriz
    vector<int> vec_entero;
    int len_vec = 0;


    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (matriz[i*M + j] == int(matriz[i*M + j])){
                vec_entero.push_back(int(matriz[i*M + j]));
                len_vec += 1;
            }
        }
    }

    if (len_vec == 0){
        cout << "\nNo se encontraron valores enteros en la matriz";
    }else{
        cout << "La cantidad de valores encontrados y el vector son:"
                << endl << "Cantidad= " << len_vec << endl <<
                "El arreglo con dichos valores es:" << endl;
        for (int i = 0; i < len_vec; i++){
            cout << vec_entero[i] << "\t";
        }
    }    
}


// Rango, Media Aritmética, Desviación Estándar, Desviación Media
void medidas_estadisticas(float* matriz, int N, int M){
    
    int i, j;
    int len = N*M; //longitud vector
    float suma = 0;
    float min = matriz[0];
    float max = matriz[0];

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){

            suma = suma + matriz[i*M + j]; //Suma total, para media

            //Para determinar el rango
            if (matriz[i*M + j] < min){
                min = matriz[i*M + j];
            }else if (matriz[i*M + j] > max){
                max = (matriz[i*M + j]);
            }
        }
    }

    float media_arit = suma/(len);
    float recorrido = (max - min); 

    int k = 0;
    float suma_vec = 0;
    float suma_cuad = 0;

    float vec_dif[len];
    float desv_med, desv_std;

    // Vector con (x - x_mas_probable)
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            vec_dif[k] = fabs(matriz[i*M + j] - media_arit);
            k++;
        }
    }
    
    // Suma de los valores y los cuadrados de los valores del vector
    for (i = 0; i < (len); i++){
        suma_vec = suma_vec + vec_dif[i];
        suma_cuad = suma_cuad + pow(vec_dif[i], 2);
    }

    desv_med = suma_vec/(len);

    desv_std = sqrt(suma_cuad/(len-1));

    cout << "\nLos valores son:\n\n" << "Media Aritmética:\t" << 
            media_arit << endl << "Rango:\t\t\t" << recorrido << endl
            << "Desviación Media:\t" << desv_med << endl <<
            "Desviación Estándar:\t" << desv_std << endl;

} 


// Comienzo de Ejercicio 3
void ej_3(){
        
    /*
     * -----------------------------------------------------------------------
     * GENERACIÓN DE LA MATRIZ
     *------------------------------------------------------------------------
     */
    
    //Se setea la semilla
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    
    //Elección de distribución

    uniform_real_distribution<float> flotante(1,100);
    
    int N, M, i, j;
    
    do{
        cout << "Ingrese N:" << endl;
        cin >> N;
    }while(N > 5);
    
    do{
        cout << "Ingrese M:" << endl;
        cin >> M;
    }while(M > 14);
    
    
    //float matriz[N][M];
    
    // Declaración dinámica de _un_ arreglo para contener los valores de la
    //matriz
    float *matriz = new float[N*M];
    
    
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            matriz[i*M + j] = flotante(generator);
            cout << matriz[i*M + j] << "\t"; 
        }
        cout << endl;
    }
    
    /*
     * -----------------------------------------------------------------------
     * OPCIONES AL USUARIO
     *------------------------------------------------------------------------
     */

    cout << "\nQue servicio quiere realizar? Ingrese la letra correspondiente" << 
            endl << "A) Recorrido siguiendo secuencia en espiral horaria" <<
            endl << "B) Listar valores sin componente decimal y su cantidad" <<
            endl << "C) Recorrido, desviación media, desviación estándar y "
            "media aritmética para los datos en la matriz" << endl;
    
    char opcion;
    cin >> opcion;
    
    switch(opcion){
        
        //RECORRIDO EN ESPIRAL
        case 'A':
        case 'a':
        {
            //cout << "1";
            
            recorrido_espiral(matriz, N, M);
            break;
        }

        //VALORES SIN COMPONENTE DECIMAL
        case 'B':
        case 'b':
        {
            sin_decimal(matriz, N, M);
            break;
        }
        
        //RECORRIDO, MEDIA ARITMÉTICA, DESVIACIÓN ESTÁNDAR, DESVIACION MEDIA.
        case 'C':
        case 'c':
        {
            medidas_estadisticas(matriz, N, M);
            break;
        }
        
        default:
            cout << "Opcion no valida";
            break;
    } 
    
    delete[] matriz;

}
