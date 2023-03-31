#include<iostream>
using namespace std;
const char *nombre_archivo = "archivo.dat2";
struct Estudiante{
	int codigo;
	char nombre[100];
	int nota[4];
	int promedio;
	string resultado;
};
void crear();
void leer();
int main(){
	crear();
	
	
	system("pause");
}

void crear(){
	FILE* archivo = fopen(nombre_archivo, "a+b");
	char res;
	Estudiante estudiante;
	
	do{
		fflush(stdin);
		
		cout<<"ingrese Codigo"<<endl;
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"ingrese el nombre"<<endl;
		cin.getline(estudiante.nombre,50);
		
		for(int i=0; i<4; i++){
			cout<<"ingrese la nota "<<i<<endl;
			cin>>estudiante.nota[i];
		}
		estudiante.promedio = (estudiante.nota[0] + estudiante.nota[1] + estudiante.nota[2] + estudiante.nota[3]) / 4;
		
		cout<<"el promedio es de "<<estudiante.promedio<<endl;
		estudiante.promedio >= 60 ? estudiante.resultado = "aprobado" : estudiante.resultado = "reprobado";
		
		fwrite(&estudiante,sizeof(estudiante),1,archivo);
		cout<<"desea ingresar un nuevo estudiante(s/n)"<<endl;
		cin>>res;
	}while(res=='s'||res=='S');
	
	fclose(archivo);
	leer();
}
void leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo, "rb");
	if(!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id=0;
	fread(&estudiante,sizeof(estudiante),1,archivo);
	cout<<"____________________________________________"<<endl;
	cout<<"ID | Codigo | Nombres completos "<<endl;
	do{
		cout<<"ID"<<"|"<<estudiante.codigo<<"|"<<estudiante.nombre<<"|"<<endl;
		for(int i=0; i<4; i++){
			cout<<"nota "<<i<<" "<<estudiante.nota[i]<<" || ";
		}
		cout<<estudiante.promedio<<"||"<<estudiante.resultado<<endl;
		fread(&estudiante,sizeof(estudiante),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
}
