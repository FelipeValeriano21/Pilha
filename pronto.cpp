#include <iostream>
#include "cstdlib"
#define max 8

using namespace std;


typedef struct lifo reg;


struct lifo
{ 
  int topo_nome;
  int topo_idade;
  int topo_salario;
  string nome [ max ];
  int idade [ max ]; 
  double salario [ max ]; 
};


string lerNome()
{
  string nome;
  cout << "\nDigite qual o nome do usuario\n";
  cin >> nome; return nome; 
}


int lerIdade()
{
  int idade;
  cout << "\nDigite qual a idade do usuario\n";
  cin >> idade; return idade; 
}


double lerSalario()
{
  double salario;
  cout << "\nDigite qual o salario do usuario\n";
  cin >> salario; return salario; 
}


bool pilhaCheia ( reg * p )
{
    if ( p->topo_nome == max - 1 ) 
          return true;
    
         return false;
}


bool pilhaVazia ( reg * p )
{
    if ( p->topo_nome == -1 )
       return true; 
       
       return false; 
}


void push (string nome, int idade, double salario, reg * p ) 
{
  if ( pilhaCheia ( p ) == true ) 
  {
       cout << "\nPilha Cheia" << endl;
       system("sleep 3");
        return;
  }
  
p->topo_nome ++;
p->nome[ p->topo_nome ] = nome;
cout << "\nO nome empilhado foi " << nome << endl;
system("sleep 3");

p->topo_idade ++;
p->idade[ p->topo_idade ] = idade;
cout << "\nA idade empilhada foi " << idade << endl;
system("sleep 3");

p->topo_salario ++;
p->salario[ p->topo_salario ] = salario;
cout << "\nO salario empilhado foi " << salario << endl;
system("sleep 3");





}


void pop (reg * p ) 
{
   if ( pilhaVazia ( p ) == true)
    { cout << "\nA pilha já está vazia!" << endl;
    system("sleep 3"); return; }
    

cout << "\nO valor desempilhado será:" << p->nome [p->topo_nome] << endl;
system("sleep 3");
p->nome [ p->topo_nome ]  = '\0';
p->topo_nome --; 

cout << "\nO valor desempilhado será:" << p->idade [p->topo_idade] << endl;
system("sleep 3");
p->idade [ p->topo_idade ]  = '\0';
p->topo_idade --; 

cout << "\nO valor desempilhado será:" << p->salario [p->topo_salario] << endl;
system("sleep 3");
p->salario [ p->topo_salario ]  = '\0';
p->topo_salario --; 


 
}


void mostrarPilha (reg * p) {
if ( pilhaVazia ( p ) == true)
{
cout << "\nA pilha está vazia!" << endl;
system("sleep 3"); return; }

cout << "OS REGISTROS SÂO\n" << endl; 

cout << "NOME | IDADE | SALARIO" << endl; 

for (int i=p->topo_nome; i>=0; i--)
    

    cout << p -> nome [ i ] << " | "  << p->idade [i]  << " | " << p -> salario [ i ] <<  endl; system("sleep 3");


}




int tela() 
{
   int tecla;
   system("clear");
    cout << "\nMenu de Registros\n1 Push (Inserir)\n2 Pop (Deletar)\n3 Mostrarpilha (Mostrar Registros)\n4 Sair\nEscolha um Item:";
   cin >> tecla;
return tecla; 
    
}


void controlarRegistro (){
int tecla, idade;
double salario; 
string nome; 
reg p1;


reg *ptpilha;
ptpilha = &p1;




ptpilha->topo_nome = 0;


do {
    tecla = tela();
    switch ( tecla ) 
    {
    case 1: nome = lerNome();
            idade = lerIdade();
            salario = lerSalario(); 
            push (nome, idade, salario, &p1);
            break;
            
    case 2: pop (&p1); 
            break;
    case 3: mostrarPilha ( &p1 );
            break;
    }
    
} while ( tecla != 4 );



cout << "\nPrograma Finalizado...!\n"; 
    
    
}

int main(int argc, char** argv) {
	
	controlarRegistro(); 
	
	return 0;
}