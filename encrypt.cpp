#include <string>
#include <bitset>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
string textoabinario(string text); // text 2 binary

int main(){
  //Write down your message
  string mensaje;
  cout << "Write down your message to encrypt: ";
  getline(cin,mensaje);
  string ktexto; //ascii key
  cout << "Make up a strong secret key: ";
  getline(cin,ktexto);
  string m; // message in binary
  string k; //key in binary
  m=textoabinario(mensaje); // message to binary
  k=textoabinario(ktexto); // key to binary
  string mtemp; // temporal variable to split each bit of m into an only and separated variable
  string ktemp; // same with k (secret key)
  int M; //Used to convert each bit of mto int: m (string) --> mtemp (string-1bit) --> M (int)  
  int K; //same with k
  int suma;
  string c;
  for (size_t i = 0; i < m.size(); ++i){
	  //Take only one bit of m and k
	  mtemp=m[i];
	  ktemp=k[i];
	  istringstream ( mtemp ) >> M;
	  istringstream ( ktemp ) >> K;
	  //Sum both numbers
	  suma = M+K;
	  //if 1+1, then change it with a zero
	  if(suma>1){
		  suma=0;
	  }
	  //Convert int to string
	  ostringstream convert;
	  convert << suma;	  
	  c+=convert.str(); //c is the encrypted message
  }
  cout << "Your encrypted message: " << c;
  cout << endl;
  
  //Save the secret key
  ofstream myfile;
  myfile.open ("key.txt");
  myfile << k;
  myfile.close();
  cout << "\n -Secret key saved with the name key.txt";

  //Save the encrypted message
  ofstream myfile2;
  myfile2.open ("c.txt");
  myfile2 << c;
  myfile2.close();
  cout << "\n -Encrypted text saved with the name c.txt\n\n";
  return 0;
}

string textoabinario(string text){
	string mensajebinario; //this is the input string but in binary
	for (size_t i = 0; i < text.size(); ++i){
		bitset<8> b(text.c_str()[i]);
		mensajebinario+= b.to_string();
	}
	return mensajebinario;
}

/*

Note: there is an operator to do this ^ so the trivial solution would be

#include <iostream>
using namespace std;
int main()
{
  char string[11]="A nice cat";
  char key[11]="ABCDEFGHIJ";
  for(int x=0; x<10; x++)
  {
    string[x]=string[x]^key[x];
    cout<<string[x];
  }
  cout << "\n\n";
  return 0;
}

//http://www.cprogramming.com/tutorial/xor.html

*/
