#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class Operacoes {
    private:
    int vetor[3], calc,dificuldade,max = 10;

    public:
    int times;
//Generation of random numbers
    void aleatorio(int qtd){
     for (int i = 0; i < qtd; i++) {
     vetor[i] = rand() % max;}};
//Number of rounds
     int rodadas(){
         cout<<"\tHow many times do you want to play this option? ";
         cin>>times;
         return times;
     }
//Define the level of difficulty
    void definirdificuldade(){
        cout<<"\n\tChoose a level\n";
        cout<<"\t0 - Super easy\n";
        cout<<"\t1 - Easy\n";
        cout<<"\t2 - Average\n";
        cout<<"\t3 - Hard\n";
        cout<<"\tLevel: ";
        cin>>dificuldade;
     //How the levels work
        switch (dificuldade) {
            case 0: max = 10; break;
            case 1: max = 50; break;
            case 2: max = 100; break;
            case 3: max = 500; break;
            default:
                cout << "\tInvalid level! Defaulting to 'Super Easy'.\n"; max = 10; break; }}
//Perform operation addition
    int sum(){
         aleatorio(3);
         cout << "\tResult = " << vetor[0] << "+" << vetor[1] << "+" << vetor[2] << " = ? ";
         return calc = vetor[0] + vetor[1] + vetor[2];
     }
//Perform operation subtraction
    int sub(){
     aleatorio(2);
     cout << "\tResult = " << vetor[0] << " - " << vetor[1] << " = ? ";
     return calc = vetor[0] - vetor[1];
}
//Perform operation multiplication
    int mult(){
     aleatorio(2);
     cout << "\tResult = " << vetor[0] << " * " << vetor[1] << " = ? ";
     return calc = vetor[0] * vetor[1];
}
//Perform operation division
    int divi(){
    //Avoid division by zero
     do{aleatorio(2);} while(vetor[1]==0);
     cout << "\tResult (integer part only) = " << vetor[0] << " / " << vetor[1] << " = ? ";
     return calc = vetor[0]/vetor[1];}
  };

int main(){
    //Iniatilize random number generator
    srand(time(0));

    int N, resposta, resultado;
    Operacoes jogos;

    // Ask the user to choose a mathematical operation
    cout<<"\t\tDo you want to test your mathematical skills?\n\n";

    cout << "\t0 - Exit game\n";
    cout << "\t1 - Addition\n";
    cout << "\t2 - Subtraction\n";
    cout << "\t3 - Multiplication\n";
    cout << "\t4 - Division\n";

    // Repeat the game loop until the user chooses to exit
     do {
    cout << "\n\tChoose one of the options above (from 0 to 4): ";
    cin >> N;

    //Handle invalid inputs
    if (N == 0) break;
    if (N < 1 || N > 4) {cout << "\tInvalid option! Try again.\n";continue;}

     // Ask the user for the number of rounds
    jogos.rodadas();
     // Ask the user to set the difficulty level
    jogos.definirdificuldade();

     // Execute the chosen operation for the specified number of rounds
    for(int i=0; i<jogos.times; i++){
        switch(N){
                    case 1:resultado = jogos.sum();break;
                    case 2: resultado = jogos.sub(); break;
                    case 3: resultado = jogos.mult(); break;
                    case 4: resultado = jogos.divi(); break;}
  // Ask the user to input their answer and verify it
        do {
    cin >> resposta;
        if (resposta == resultado) {cout << "\tWell done!\n";break;}
        else {cout << "\tWrong answer. Try again: ";}}while(N!=0);}


 }while (true);
         return 0;
    }
