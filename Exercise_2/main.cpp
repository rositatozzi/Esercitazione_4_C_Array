#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Utils.hpp"

using namespace std;

int main()
{

    string nameFileI = "data.csv";
    ifstream ifstr(nameFileI);
    if(ifstr.fail()){
        cerr<<"File error"<<endl;
    }
    string nameFileO = "result.txt";
    ofstream ofstr;
    ofstr.open(nameFileO);
    if(ofstr.fail() ){
        cerr << "File error" << endl;
    }


    ios in(NULL);
    in.copyfmt(cout);

    string line;
    getline(ifstr,line);//leggo prima riga per estrarre S
    istringstream convert = istringstream(line);
    double S ;
    char c;
    convert>>c>>c>>S;
    ofstr<<"S = "<<fixed<< setprecision(2) <<S<<", ";
    getline(ifstr,line);//leggo seconda riga per estrarre n
    convert = istringstream(line);
    int n;
    convert>>c>>c>>n;
    ofstr<<"n = "<<n<<endl;

    getline(ifstr,line);//leggo terza riga e scarto

    double * ptrW  = new double[n];
    double * ptrR  = new double[n];
    ofstr<< "w = [ ";
    ofstr.copyfmt(in);
    double w;
    double r;
    for(int i = 0; i<n; i++){
        getline(ifstr,line);
        convert = istringstream(line);
        convert>>w>>c>>r;
        ptrW[i] = w;
        ptrR[i] = r+1; //salvo direttamente r+1 perchè mi servirà per il prodotto scalare
        ofstr<< w << " ";
    }
    ofstr<< "]\n" << "r = [ " ;

    for(int i = 0; i<n; i++){
        ofstr << ptrR[i]-1 << " "; //sottraggo 1 perchè devo stampare r e non r+1
    }

    ofstr << "]" << endl;
    double V = dotProduct(ptrW,ptrR,n); //Faccio somma dei prodotti tra wi e ri+1 ==> prodotto scalare tra w e r+1
    V= V*S;
    double R = (V-S)/S;
    ofstr << "Rate of return of the portfolio: " << R <<endl;
    ofstr << "V: " <<fixed<< setprecision(2) << V << endl;

    delete [] ptrR;
    delete [] ptrW;

    ifstr.close();
    ofstr.close();
  return 0;
}

