    /*
 String Classes and String Functions - Whenever we are using in to read data whether it is from file or screen the end of the input is determined by the first void space character it comes across whenever we want to read an entire line of data we use function getline(in, x) If we use getline the end of input is determined by a new line character.
 
 We can also create a string by sending the string as a parameter while creating string.
	string firstString(“the string”);
 
 If we want to copy a string we can use 's2 =  s1’
 or an other method s3.assign(s1);
 
 Strings are similar to arrays of characters. Anything we can do to an array we can do to a string.
 
 We can also use index to get a character or we can use at method as ‘s1.at(3)’
 
 We can also loop through a string using for loop
	for(int x = 0; x<s1.length( ); x++){
        cout << s1.at(x);
	}
 */

#include <iostream>
#include <string>  // gives us string functions
using namespace std;

int main(){
    
    /* Making string by passing in as parameter
     
    string firstString("the string");
    cout << firstString << endl;
    
     */
    
    /* normal cin
     
    string first;
    cin >> first;
    //Whenever we are using cin to read data
    cout << "The string i entered is " << first << endl;
     
     */
    
    
    /* taking string using getline method
     
    string second;
    getline(cin,second);
    cout << "Using Get line : " << second << endl;
     
     */
    
    
    /* copying strings 
     
    string s1("string s1 ");
    string s2;
    string s3;
    
    // copying string way-1
    
    s2 = s1;
    
    // copying string way-2
    
    s3.assign(s1);
    
    cout << s1 << s2 << s3 << endl;
    
    */
    
    //strings are basically arrays of characters
    
    string s11 = "string s11";
    
    cout << "Array approach " << s11[0] <<" "<< "At method " << s11.at(0) << endl;
    
    int x = 0;
    for (x=0; x< s11.length(); x++) {
        cout << s11.at(x) << endl;
    }
    
    return 0;
}