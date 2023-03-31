#include<iostream>
using namespace std;

int main(){
	int estudiante;

	cout<<"ingrese la cantidad de estudiantes "<<endl;
	cin>>estudiante;
	
	int id[estudiante];
	string nombre[estudiante];
	int notas[estudiante][4], res[estudiante];
	
	for(int i=0; i<estudiante; i++){
		cout<<"codigo :"<<endl;
		cin>>id[i];
		cout<<"nombre completo: "<<endl;
		cin>>nombre[i];
	}
	for(int i=0; i<estudiante;i++){
		cout<<id[i]<<"||"<<nombre[i]<<endl;	
		for(int j=0; j<4; j++){
			cout<<"ingrese la nota "<<j<<endl;
			cin>>notas[i][j];
			res[i]+= notas[i][j];
		}
	}
	for(int i=0; i<estudiante; i++){
	if((res[i]/4)>=60){
		cout<<id[i]<<"||"<<nombre[i]<<"aprobado"<<endl;
	}else{
		cout<<id[i]<<"||"<<nombre[i]<<"reprobado"<<endl;
	}
	}
	
	system("pause");
}
