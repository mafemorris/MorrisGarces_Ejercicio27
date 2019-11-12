#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

float derivada(float y,float w);

void euler(float* solucionEuler,float deltat, int pasos, float w);

void implicit(float* solucionImplicita,float deltat, int pasos, float w);

template <class T>
void escribe(string archivo, T* datos, int n_dat){
  ofstream outfile;
  //abre el archivo.
  outfile.open(archivo);

  for (int i=0; i < n_dat; i++){
    outfile << datos[i] << endl;
  }
  //cierra el archivo.
  outfile.close(); 
}

int main(){
    float w=0.1;
    float ti=0;
    float tf=4/w;
    int pasos;

    int num = 3;
    float deltat[3] = {0.1, 0.01, 1};
    string eulernombres[3] = {"euler01.txt", "euler001.txt", "euler1.txt"};
    string implicitanombres[3] = {"imp01.txt", "imp001.txt", "imp1.txt"};

    for(int i = 0; i<3; i++){
        pasos = (tf-ti)/deltat[i];

        float* solucionEuler = new float[pasos];
        float* solucionImplicita = new float[pasos];

        euler(solucionEuler, deltat[i], pasos, w);
        escribe(eulernombres[i], solucionEuler, pasos);

        implicit(solucionImplicita,deltat[i],pasos, w);
        escribe(implicitanombres[i], solucionImplicita, pasos);

        delete[] solucionEuler;
        delete[] solucionImplicita;
    }
    
    return 0;
}

float derivada(float y, float w){
    return -w*y;
}

void euler(float* solucionEuler,float deltat, int pasos, float w){
    solucionEuler[0]= 1;
    //cout << endl << "***** Euler *****" << endl << endl;
    for(int i=1; i<pasos; i++){
        solucionEuler[i] = solucionEuler[i-1] + deltat*derivada(solucionEuler[i-1], w); 
        //cout << solucionEuler[i] << endl;
    }
}

void implicit(float* solucionImplicita,float deltat, int pasos, float w){
    solucionImplicita[0]= 1;
    //cout << endl << "***** Implicita *****" << endl << endl;
    for(int i=1; i<pasos; i++){
        solucionImplicita[i] = solucionImplicita[i-1]/ (deltat*w + 1); 
        //cout << solucionImplicita[i] << endl;
    }
}
