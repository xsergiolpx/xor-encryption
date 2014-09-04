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
void bin2char(const char* enter);

int main(){
  string c; //encrypted message
  string k; // secret key
  
  //Load ciphertext
  ifstream myfile ("c.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,c) )
    {
    }
    myfile.close();
  }
  else{ cout << "Unable to open ciphertext file\n"; return 0;}

//Load the key
  ifstream myfile2 ("key.txt");
  if (myfile2.is_open())
  {
    while ( getline (myfile2,k) )
    {
    }
    myfile2.close();
  }
else{ cout << "Unable to open key file\n"; return 0;}
  cout << "Your ciphertext is c: " << c << endl;
  
  //Decrypt text
  int K, C, suma; //
  string ctemp, ktemp, m;
    for (size_t i = 0; i < c.size(); ++i){
	  //Take only one bit of c and k
	  ctemp=c[i];
	  ktemp=k[i];
	  istringstream ( ctemp ) >> C;
	  istringstream ( ktemp ) >> K;
	  //Sum both numbers
	  suma = C+K;
	  //if 1+1, then change it with a zero
	  if(suma>1){
		  suma=0;
	  }
	  ostringstream convert;
	  convert << suma;	  
	  m+=convert.str();
  }
  const char * M = m.c_str(); //change m (string) to char to fit the function bin2char
  bin2char(M);
  cout << "\n\n******************************************\n";
  cout << "\n\n";
  return 0;
}

void bin2char(const char* enter)
{
	cout << "\n\n******************************************\n";
	cout << "   The decrypted message is:\n\n     ";
  int size=strlen(enter); //grabs length of string
  int bin[8];
  int tempChar = 0;
  char character;

  int a = 0;
  for(int b=0; b<size/8; b++)
    {
      for(int c=0; c<8; c++)
    {
      bin[c]=(int)enter[a]-48;
      a++;
    }
      int power[8];
      int count = 7;
      for(int d=0; d<8; d++)
    {
      power[d]=count;
      count--;
    }
      for(int e=0;e<8;e++)
    {
      double r=bin[e];
      double s=power[e];
      tempChar += r* pow(2,s);
    }
      character = tempChar;
      tempChar = 0;
      cout << character;
    }
}
