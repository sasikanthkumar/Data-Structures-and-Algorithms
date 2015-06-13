/*
 String substrings swapping Findings - We also have a function substring which gives a part of the string The substring Function takes two parameters the beginning index or the beginning character The second parameter is how many characters do we want to go till like as shown below
	s1.substr(2,5);
 We also have a swap function it takes one string and swaps with other string
	s1.swap(s2);
 Swap is very useful in sorting.
 
 Find Function - Whenever we are finding a substring it gives starting index of the string.
	s1.find(“substring”);
 It Gives the starting location of first found occurrence.
 
 But what if we want index of last occurrence.
 
	s1.rfind(“substring”);
 
 It works in a reverse order.
 
 String Erase - There is an erase function It takes one parameter at which character we want to start erasing
	s1.erase(5);
 
 Replace Function - Takes Three parameters first parameter is what character do we want to start replacing at the next parameter takes how many character we want to replace. The next parameter takes with which string we want to replace. No need to replace exactly same number of characters we can replace less or more.
 
 Insert Function - If we don’t want to replace string but insert in the middle of a string a new substring we use this function It takes two parameters first one is where we want to start inserting at and second parameter is the string we want to insert.
	s1.insert(5,”sub string”);
 
 Usually we use replace and find in conjunction.
 */
#include <iostream>
#include <string>
using namespace std;

int main(){
    
    string s1("strings and sub-strings");
    
    cout << s1.substr(2,7) << endl;
    
    string one = "string one";
    string two = "string two";
    
    cout << "one = " << one <<endl;
    cout <<"two = " << two << endl;

    one.swap(two);
    
    cout << "one = " << one <<endl;
    cout <<"two = " << two << endl;

    cout << s1.find("ring") << endl;
    
    cout << s1.rfind("ring") << endl;
    
    string stringOne = "Iam a string named stringOne";
    
    stringOne.erase(5);
    
    cout << stringOne << endl;
    
    stringOne = "Iam a string named stringOne";
    
    cout << stringOne << endl;
    
    stringOne.replace(5,5,"fivehveh");
    
    cout << stringOne << endl;
    
    stringOne.insert(0,"insert fn ");
    
    cout << stringOne << endl;
    
    return 0;
}