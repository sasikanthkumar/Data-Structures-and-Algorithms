/*
 A string is a sequence of characters. An instance of a string is called string literal.
 There are two types of strings in C++
    1. C-Style string
    2. String class type
 1. C-style strings are one dimensional array of characters. They end with a null character '\0' to signify the end of the string. If a C-style string has 5 characters the size of the string is 6 becoz the null character is on the end of the string. The null character is added by the compiler automatically as long as the size of array is atleast one larger than the size of the string.It is not mandatory that the string array size be exactly one more than the size of the string it can be more than the value one more than the size of the string. If the size is lesser than that we will get a compilation error saying 'string for char aray is too long'
 2. In C++ string class type one need not bother about the dimensions of the array or the null character. Even though C++ strings are seperate class type their characters can still be referenced as 0 based indexing just like C strings.
    Declaration is done as follows 
        string str;
    Initialization is done as follows 
        string str = "Hello";
 Let us now consider some functions which can be performed on strings. In C there are some predefined functions that helps us to do some common operations like copy, concatenation, comparision and finding the length of the string. All these functions can also be applied to C++ strings but the syntax differs.
 */
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


int main(){
    char c_style_a[15] = "C style String";
    // To take C-style string as input we can simply use scanf with '%s' or we can also use cin. It will take input until we press enter or space.
    cout << c_style_a << endl;
    
    string cpp_style_string = "Cpp style String";
    
    cout << cpp_style_string << endl;
    
    // copy one string to other C-style
    char s1_c[10] = "string1_c";
    char s2_c[10];
    
    // we give the destination first and source second
    strcpy(s2_c,s1_c);
    
    cout << "s1_c = " << s1_c << "\n"<< "s2_c = " << s2_c << endl;
    
    
    // copy Cpp style
    
    string s1_cpp = "string1_cpp";
    
    string s2_cpp;
    
    s2_cpp = s1_cpp;
    
    // if we cange s1_cpp now it will not reflect s2_cpp
    cout << "s1_cpp = " << s1_cpp << "\n" << "s2_cpp = " << s2_cpp << endl;
    
    // Finding Length of strings
    
    // C-style function strlen(s1)
    
    cout << "Finding length of string C style string s1_c length = " << strlen(s1_c) << endl;
    
    // C++ style string length function s1.size()
    
    cout << "String Length C++ style s1_cpp length = " << s1_cpp.size() << endl;
    
    // Concatenate C-Function strcat(s1,s2);
    
    cout << "concatenate c Function strcat(s1,s2) = " << strcat(s1_c,s2_c) << endl;
    
    // Concatenate C++ function s1 += s2
    
    s1_cpp += s2_cpp;
    
    cout << "concatenate C++ s1 += s2  " << s1_cpp << endl;
    
    // compare two strings c strcmp(s1,s2)
    /* strcmp   returns value<0 if str1 is less than str2
                returns value>0 indicates str2 is less than str1
                returns value = 0 indicates str1 is equal to str2
     */
    cout << "compare two strings c strcmp(s1,s2) = " << strcmp("s1_c","s1_c") << endl;

    // compare two strings cpp s1 == s2
    

    if (s1_cpp == s2_cpp) {
        cout << "Equal" << endl;
    }else{
        cout << "Not Equal" << endl;
    }
    
    // We cannot print the string data type with the printf() directly. We can use cout or convert string datatype into the C-style using c_str() function
    
    printf("%s\n",s1_cpp.c_str());
    
    
    return 0;
}