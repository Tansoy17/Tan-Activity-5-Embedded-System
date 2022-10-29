//Marl Kenneth Tan
//BSCPE 4A
#include <iostream>
using namespace std;


int main(){
string crc, decoded;

cout << "Please enter the message: ";
getline(cin, decoded);


cout << "Please enter the divisor: ";
getline(cin, crc);


for(int a=0; a <= decoded.length() - crc.length(); ){
for(int b=0; b < crc.length(); b++)
decoded[a+b] = decoded[a+b] == crc[b] ? '0':'1';
for(; a < decoded.length() && decoded[a] != '1'; a++);
}


for (char a : decoded.substr(decoded.length() - crc.length() ) )
if(a != '0'){
cout <<"Status: Error in communication ....";
return 0;


}

cout <<"Status: Ther is no error!";
return 0;
}
