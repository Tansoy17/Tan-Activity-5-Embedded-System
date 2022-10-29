//Marl Kenneth Tan
//BSCPE 4A
#include <iostream>
using namespace std;


int main(){ 
string message,crc,encoded="";


cout <<"Please enter the message: ";
getline(cin,message);


cout <<"Please enter the divisor: ";
getline(cin,crc);


int c=message.length(),n=crc.length();
encoded+=message;


for(int a=1;a<=n-1;a++)
encoded+='0';
for(int a=0;a<=encoded.length()-n; ){
for(int b=0;b<n; b ++)
encoded [a+b] = encoded[a+b] == crc[b]? '0':'1';
for(;a<encoded.length() && encoded[a]!='1';a++); 
}
cout << "Final Encoded CRC:" << message+encoded.substr(encoded.length()-n+1);
    return 0;
}
