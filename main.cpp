/**Author : Mo
Problem : Edit longest string 
Problem: given two strings str1 and str2, min number of edits to change str1 to str2
such that n is length of str1 and m is length of str2
DAG? **/

#include <string>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm> // for min
//helper functions, min of 3 numbers

int min(int x, int y, int z) 
{ 
    return std::min(std::min(x, y), z); 
} 


int ELS(std::string str1, std::string str2, int m , int n){
	// edge cases
	if (m == 0 ){
		return 0;
	}
	if (n == 0){
		return 0;
	}
	// if the last char if str1 == str2, then recursively call fun with/ pointers to prev char..
	if (str1[m-1] == str2[n-1]){
		return ELS(str1, str2, m - 1, n - 1); 
	}
	// last case, if there are not the same
	return 1 + min(ELS(str1, str2, m, n - 1), // Insert 
                   ELS(str1, str2, m - 1, n), // Remove 
                   ELS(str1, str2, m - 1, n - 1) // Replace 
                   );


}


void testing(){
	std::string s1 = "Hello World";
	std::string s2 = "Hello Dixie";
	std::string s3 = "Twitter";
	std::string s4 = "Twitch";
	if(ELS(s1,s2,s1.length(), s2.length()) != 5){
		std::cout << "case 1 failed" << std::endl;
		std::cout << "ELS VALUE " << ELS(s1,s1,s1.length(), s2.length());
	}
	else if(ELS(s3,s4,s3.length(), s4.length()) != 3 ){
		std::cout << "case 2 failed" << std::endl;
		std::cout << "ELS VALUE " << ELS(s3,s4,s3.length(), s4.length());
	}
	else if(ELS(s3,s3,s3.length(), s3.length()) != 0 ){
		std::cout << "case 3 failed" << std::endl;
		std::cout << "ELS VALUE " << ELS(s3,s4,s3.length(), s3.length());
	}else{
		std::cout << "Tests Passed!" << std::endl;
	}// recusrsively tested edge cases! 


}
/*** Reading from a file with the following format
ABGD ACGA
ADDC DEFE
BBFE BCEG
FBBE FBBF
DFEE CDEF
BAAC GCGF
DBGC GBGG
  ***/
int main(int argc, char **argv){
    std::string arg(argv[0]);
    std::stringstream ss(arg);
    std::string myText = argv[1]; 
    //std::cout << "open file "  << argv[1] << myText <<std::endl;
    std::ifstream myfile;
    myfile.open (myText);
    std::string str1, str2;
    clock_t start_ELS, end_ELS;
    
    
    double count = 0.0;
    double time_taken_ELS = 0.0;
    int sum = 0;
    while (myfile >> str1 >> str2)
    {
	   start_ELS = clock();
       sum = sum + ELS(str1,str2, str1.length(), str2.length());
        //std::cout << "str1" << " -> " << str1 << " str2 " << str2 << " " <<std::endl;
	   count++;
	   end_ELS = clock(); 
       time_taken_ELS = time_taken_ELS + (double(end_ELS - start_ELS) / double(CLOCKS_PER_SEC)) ;	
    }

	//testing();
	double aver_time = time_taken_ELS / count;
	std::ofstream outputfile;
	outputfile.open ("output.csv" , std::ios_base::app);
    outputfile << myText << "," << sum  << "," << aver_time << "\n"; 
	return 0;
}