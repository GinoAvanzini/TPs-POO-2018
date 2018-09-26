
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;

#include <iomanip>


struct fotograma{
    
    int filas;
    int columnas;

    vector<int> matriz_lectura;
    vector<char> matriz_estrellas;
    
};


//Muestra las tablas con las lecturas y con las estrellas
void mostrar_tabla(fotograma &foto_archivo){
    
    int N, M, i, j;  //Para simplificar sintaxis
    cout << "Tabla A:\n";
    
    N = foto_archivo.filas;
    M = foto_archivo.columnas;
    
    for (i = 0; i < N; i++){
        cout << setw(3) << left << " ";
        for (j = 0; j < M; j++){
            cout << setw(4) << left << foto_archivo.matriz_lectura[i*M + j];
        }
        cout << endl;
    }
    cout << "\n";
    
    vector<char> letras = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U'};

    cout << "Tabla B:\n";
    
    cout << setw(3) << " ";
    
    for (i = 0; i < M; i++){
        cout << setw(4) << left << letras[i];
    }
    cout << endl;
    
    cout << setw(3) << " ";
    for (i = 0; i < M*4; i++){
        cout << "-";
    }
    cout << endl;
    
    for (i = 0; i < N; i++){
        
        // El if es para que quede bien la primera columna
        if (i >= 9){  
            cout << i + 1 << "|";
        } else {
            cout << " " << i + 1 << "|";
        }
        
        for (j = 0; j < M; j++){
            cout << setw(4) << foto_archivo.matriz_estrellas[i*M + j];
        }
        cout << "|" << endl;
    }
    
    
    cout << setw(3) << " ";
    for (i = 0; i < M*4; i++){
        cout << "-";
    }
    cout << endl;
}


//Analiza el fotograma para generar la matriz con estrellas
void analizar_fotograma(fotograma &foto_archivo){
    int suma, N, M;
    
    //Para simplificar la sintaxis se guardan filas y columnas en N y M 
    N = foto_archivo.filas;
    M = foto_archivo.columnas;
    
    for (int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            
            //Valores de los bordes
            if (i == 0 || i == (N - 1)){
                foto_archivo.matriz_estrellas.push_back(' ');
                continue;
            }
            if (j == 0 || j == (M - 1)){
                foto_archivo.matriz_estrellas.push_back(' ');
                continue;
            }
            
            suma = foto_archivo.matriz_lectura[i*M + j] +
                    foto_archivo.matriz_lectura[(i-1)*M + j] +
                    foto_archivo.matriz_lectura[(i+1)*M + j] +
                    foto_archivo.matriz_lectura[i*M + j - 1] +
                    foto_archivo.matriz_lectura[i*M + j + 1];
            
            if (suma > 30){
                foto_archivo.matriz_estrellas.push_back('*');
            } else {
                foto_archivo.matriz_estrellas.push_back(' ');
            }
            
        }
    }
}


// Lee el struct fotograma y lo modifica con los contenidos de la matriz
// correspondiente. Luego llama a la función analizar_fotograma.
void leer_magnitud(fotograma &foto_archivo, ifstream &foto){
    
    int N = 0;
    int len = 0;
    int M;
    string String;
    int valor;
    
    while(getline(foto, String)){
        stringstream Stream(String);
        N += 1;

        while(Stream >> valor){
            foto_archivo.matriz_lectura.push_back(valor);
            len += 1;
        }
    }
    
    foto_archivo.filas = N;
    M = len/N;
    foto_archivo.columnas = M;

    analizar_fotograma(foto_archivo);

}


void desde_aleatoria(){
    
    //Se setea la semilla
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    
    //Elección de distribución
    uniform_int_distribution<int> entero(4,20);
    normal_distribution<double> dist_normal(3, 4.5);
    
    
    fotograma foto_random;
    
    foto_random.filas = entero(generator);
    //foto_random.filas = 20;
    foto_random.columnas = entero(generator);
    //foto_random.columnas = 20;
    int N = foto_random.filas;
    int M = foto_random.columnas;
    int valor;
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            
            valor = int(dist_normal(generator));
            if ((valor < 0) || (valor > 20)){
                j--;
                continue;
            }
            
            foto_random.matriz_lectura.push_back(valor); 
            
        }
    }
    
    analizar_fotograma(foto_random);
    
    mostrar_tabla(foto_random);
    
}


void desde_archivo(){
    
    ifstream foto;
    
    foto.open("fotografia.txt");
    
    if(foto.is_open()){ //chequea si foto abrió

        fotograma foto_archivo;
        leer_magnitud(foto_archivo, foto);
        
        mostrar_tabla(foto_archivo);
        
    } else {
        cout << "Hubo un error al intentar abrir el archivo";
    }

    foto.close();
    
}



void ej_4(){
    
    
    
    cout << "Elija de dónde tomar la fotografía para analizar:\n"
            << "1) Tabla desde archivo de texto \"fotografia.txt\"\n"
            << "2) Tabla generada aleatoriamente\n";
    
    int opcion;
    cin >> opcion;
    
    switch(opcion){
        case 1:
            desde_archivo();
            break;
        case 2:
            desde_aleatoria();
            break;
        default:
            cout << "Opción incorrecta";
            break;
    }

}