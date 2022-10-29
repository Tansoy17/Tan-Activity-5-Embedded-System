//Marl Kenneth Tan
//BSCPE 4A
#include <bits/stdc++.h>

using namespace std;
//string data
string Ones_complement(string data)
//data length
{
for (int a = 0; a < data.length(); a++) {
if (data[a] == '0')
data[a] = '1';
else
data[a] = '0';
} 
return data;
}
//checksum 


string checksum(string data, int block_size)
{
    
    
int b = data.length();
if (b % block_size != 0) {
int pad_size = block_size - (b % block_size);
for (int a = 0; a < pad_size; a++) {
data = '0' + data;
            
}
}
    
//result
string result = "";
for (int a = 0; a < block_size; a++) {
result += data[a];
}



for (int a = block_size; a < b; a += block_size) {
        string next_block = "";
 for (int c = a; c < a + block_size; c++) {
        next_block += data[c];
        }
        
        
        
string additions = "";
int sum = 0, carry = 0;
for (int d = block_size - 1; d >= 0; d--) {
sum += (next_block[d] - '0')
                   + (result[d] - '0');
carry = sum / 2;
            
            
if (sum == 0) {
additions = '0' + additions;
sum = carry;
}
            
else if (sum == 1) {
additions = '1' + additions;
sum = carry;
}
            
else if (sum == 2) {
additions = '0' + additions;
sum = carry;
}
else {
                
additions = '1' + additions;
sum = carry;
}
}
 
string final = "";
 
if (carry == 1) {
for (int e = additions.length() - 1; e >= 0;
                 e--) {
                if (carry == 0) {
                    final = additions[e] + final;
                }
                else if (((additions[e] - '0') + carry) % 2
                         == 0) {
                    final = "0" + final;
                    carry = 1;
                }
                else {
                    final = "1" + final;
                    carry = 0;
                }
            }
 
            result = final;
        }
        else {
            result = additions;
        }
    }
 
    return Ones_complement(result);
}
 
bool checker(string sent_message, string rec_message, int block_size)
{
    string sender_checksum = checksum(sent_message, block_size);
    string receiver_checksum = checksum(rec_message + sender_checksum, block_size);
 
    if (count(receiver_checksum.begin(), receiver_checksum.end(), '0') == block_size) {
return true;
}
else {
return false;
}
}

int main()
{
string sent_f;
string receive_f;
int block_size = 8;
 
cout<< "Please enter sent message:  ";
cin>> sent_f;
cout<< "Please enter receive message:  ";
cin>> receive_f; 
	
if (checker(sent_f, receive_f, block_size)) {
cout << "No Error";
}
else {
cout << "Error";
}
 
return 0;
}
