/*
Minimum distance between 1s

https://www.codechef.com/problems/MINDIST1?tab=statement

Chef has a binary string S of size N. Chef can perform the following operation on the string:
Select any substring of size 3 and reverse it.
Find the minimum distance between any two 1s Chef can achieve, by applying the above operation any (possibly zero) number of times.

Note:

The distance between two characters Si and Sj is defined as abs(i-j).
It is guaranteed that the string contains at least two occurrences of 1.
A substring is obtained by deleting some (possibly zero) elements from the beginning and some (possibly zero) elements from the end of the string.

*/

#include <iostream>
#include <string>
using namespace std;

int minDist1() {
	// your code goes here
	int T, N;
	cin>>T;
	string A = "";
	while(T > 0){
	    cin>>N;
	    cin>>A;
	    
        int d = 0;
        
        if( A.find("11") != string::npos ){ // case where two 1s are already consecutive
            cout<<1<<endl;
        }
        else {//if(A.find("101") != string::npos){
            //d = 2;
        
            for(int i = 0; i <= N-3; i++){
                string sA = A.substr(i, 3); // find ths substring
                if( sA == "110" or sA == "011" or sA == "111"){ // found two consecutive 1s
                    d = 1;
                    break;
                }
                else if(sA == "101"){ // no need to reverse, just move to the next 1
                    d = 2;
                    i++;
                }
                else if(sA == "100") { // reverse it to move the 1 to the right corner
                    A.replace(i, 3, "001"); // reversing
                }
                else if(sA == "000"){ // no need to reverse, just skip this sequence
                    i+=2;
                }
                else if(sA == "001"){ // no need to reverse, move to the next 1
                    i++;
                }
            }
            
            cout<<d<<endl;
        }
        
	    T--;
	}
	return 0;
}
