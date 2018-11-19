#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<int> M(2048);
vector<int> S(4096);


//SE SOLICITA ASIGNAR n BYTES AL PROCESO p
void proceso(int n, int p) {
	//NOTA
	/*EL PROCESO SE CARGA COMPLETO A MEMORIA VIRTUAL EN UNA SOLICITUD AL MANEJADOR DE MEMORIA
	INCLUYENDO PAGINAS QUE CONTIENEN EL CODIGO DEL PROCESO Y OTRAS PARA SU AREA DE DATOS*/

	//asignar los marcos de pagina necesarios
	//si no hay suficientes marcos en M, swappear-out las paginas contenidas en algunos de los masrcos ya ocupados
	//Imprimir el comando de input y la lista de marcos de pagina asignados
	//Si se hizo swapping, lista de marcos de memoria real que fue necesario swappear
	//para cada uno indicar acerca de la pagina que contenia el marco

}

//ACCESAR PARA LECTURA LA DIRECCION VIRTUAL d DEL PROCESO p, m = 0 ES SOLO LEER, m = 1 ES LEER Y MODIFICAR
void acceder(int d, int p, int m) {
	//Localizar donde se enceuntra la página que contiene esa direccion
	//Imprimir comando de input, la direccion en memoria real correspondiente a la virtual d del proceso p
	//Si la pagina necesaria se enconbraba en el area de swapping, indicar dond estaba en el arreglo S, y donde en memoria real

}

//LIBERAR LAS PAGINAS DEL PROCESO p
void liberar(int p) {
	//liberar todas las paginas del proceso p, tanto en memoria real como las  que estaban en swapping
	//imprimir el input y lista de marcos de pagina que se liberaron

}


int main(int argc, char const *argv[])
{
	ifstream entrada;
	int d, p, m, n;
	string solicitud;
	string archivo;

	//solicitar archivo 
	cout << "Ingresar el nombre del archivo con las solicitudes (incluir formato)" << endl;
	cin >> archivo;
	entrada.open(archivo);
	while (!entrada.eof()) {
		entrada >> solicitud;
		//Serie de decisiones para determinar que solicitud se va a hacer
		if (solicitud == "P") {
			entrada >> n >> p;
			cout << solicitud << " " << n << " " << p << endl;
			cout << "Asignar " << n << " bytes al proceso " << p << endl;
			proceso(n, p);
		}
		else if (solicitud == "A") {
			entrada >> d >> p >> m; 
			cout << solicitud << " " << d << " " << p << " " << m << endl;
			if (m == 0)
				cout << "Acceder a la direccion virtual " << d << " del proceso " << p << " para lectura" << endl;
			else 
				cout << "Acceder a la direccion virtual " << d << " del proceso " << p << " para lectura y modifcacion" << endl;
			acceder(d, p, m);
		}
		else if (solicitud == "L") {
			entrada >> p;
			cout << solicitud << " " << p << endl;
			cout << "Liberar todas las paginas del proceso " << p << endl;
			liberar(p);
		}

		else if (solicitud == "C") {
			cout << "Comenzamos" << endl;
		}

		else if (solicitud == "F") {
			cout << "Fin. Reporte de salida:" << endl;
			//FAlta agregar el desempeño
		}

		else if (solicitud == "E") {
			cout << "Exit. Ultima linea del archivo" << endl;
		}

		else {
			cout << "Solicitud ingresada no disponible" << endl;
		}
	}
	entrada.close();

	return 0;
}