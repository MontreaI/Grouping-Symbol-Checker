// gscheck.cpp -- Assignment 1

#include "char_stack.h"
#include <iostream>
#include <string>

void print_error(int error_index, std::string s_array, bool & error_detected); // outputs line where error was detected
char r(char symbol); // returns the symbol that we were "expecting" , but did not get.

int main()
{
	char_stack S;
	std::string s_array, temp_array;
	bool error_detected = 0;
	int i = 0, line = 1, error_index = 0;
	
	while(getline(std::cin, s_array) && error_detected == 0)
	{

		while((s_array[i] != '\0') && (error_detected == 0))
		{
			if ( s_array[i] == '(' || s_array[i] == '{' || s_array[i] == '[')
			{
				S.push( s_array[i]);
			}
			
		        if ( s_array[i] == ')' || s_array[i] == '}' || s_array[i] == ']' )
			{

				if ( (S.empty()) && (error_detected == 0))
				{
					std::cout << "Error on line " << line << ": Too many " << s_array[i] << std::endl;
					error_index = i;
					print_error(error_index, s_array, error_detected);
				}
				else
				{
					char l = S.pop();
					
					if( s_array[i] != ')' && l == '(' || s_array[i] != '}' && l == '{' || s_array[i] != ']' && l == '[')
					{ 
						std::cout << "Error on line " << line << ": Read " << s_array[i] << ", expected " << r(l) << std::endl;
						error_index = i;
					        print_error(error_index, s_array, error_detected);
					}
				}					
			}
			i = i+1;
		}
	  	temp_array = s_array;
		if(error_detected == 0){
			line = line + 1;
			i = 0;
			s_array = " ";
	  	}

	}
	
	if(!(S.empty()) && error_detected == 0)
	{
		char l = S.pop();
	        std::cout << "Error on line " << line-1 << ": Too many " << l << std::endl;
		std::cout << temp_array << std::endl;
		error_detected = 1;
		
	}

	
	if(error_detected == 0){
		std::cout << "No Errors Found\n";
	}

	return 0;
}

void print_error(int error_index, std::string s_array, bool & error_detected)
{
	error_detected = 1;
	for(int i = 0; i<= error_index; i++){
		std::cout << s_array[i];
	}
	std::cout << std::endl;
	for(int i = 0; i<= error_index; i++){
		if(s_array[i] == '\t'){
			std::cout << "        "; // print tabs
		}
		else{
			std::cout << " "; // print spaces
		}
	}
	while(s_array[error_index] != '\0'){
		error_index++;
		std::cout << s_array[error_index];
	}
	std::cout << std::endl;
}

char r(char symbol)
{
	if (symbol == '{'){
		return '}';
	}
	else if (symbol == '['){
	
		return ']';
	}
	else{
		return ')';
	}
}

