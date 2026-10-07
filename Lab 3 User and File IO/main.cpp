#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

/*******************************
Nikolas Praseutsinh
Computer Science Fall 2026
Due: September 29, 2026
Lab 3: User and File I/O
Demo of file and user input and output
*********************************/


//Prototypes
float CalculateMean(std::string file);
float CalculateStandardDeviation(std::string file, float mean);

int main() {
    std::string fileName;

    //Enter file name from user
    std::cout << "Enter file name: ";
    std::cin >> fileName;
    float userInput;

    std::cout << "Enter 4 numbers: ";

    std::ofstream UserFile("UserInput");

	//Ask user for 4 numbers and write them to the file
    for (int i = 0; i < 4; i++) {
        std::cin >> userInput;
        UserFile << userInput << std::endl;
    }

	//Calculate the mean and standard deviation for the user input
    float userMean = CalculateMean("UserInput");
    float userStddev = CalculateStandardDeviation("UserInput", userMean);
	//Calculate the mean and standard deviation for the file input
    float mean = CalculateMean(fileName);
    float stddev = CalculateStandardDeviation(fileName, mean);

    //Create output file and write the mean and std
    std::ofstream NewFile("outMeanStd.dat");

    // Write the mean and standard deviation to the output file
    NewFile << "Mean: " << mean << std::endl;
    NewFile << "Standard Deviation: " << stddev;

    //output for the file
    std::cout << "User Mean: " << userMean << std::endl;
    std::cout << "User Standard Deviation: " << userStddev;

    return 0;
}

float CalculateMean(std::string file) {
    float mean = 0;
    float num = 0;

    //Open the file and read the numbers
    std::ifstream MyFile(file);

    // Read 4 numbers from the file and calculate the mean
    for (int i = 0; i < 4; i++) {
        //Reads next number from the file
        MyFile >> num;
        //Then adds it to the mean
        mean += num;
    }
    //Devide the sum by 4 cause there are 4 numbers
    mean /= 4;

    //Lastly we return the mean and is going to be writen in a file in the main function
    return mean;
}

float CalculateStandardDeviation(std::string file, float mean) {
    float std = 0;
    float num = 0;

    //Open the file and read the numbers
    std::ifstream MyFile(file);

    //Iterates 4 times cause there are 4 numbers
    for (int i = 0; i < 4; i++) {
        //Reads next number from the file
        MyFile >> num;
        //Then powers (num - mean) and adds it to std
        std += (num - mean) * (num - mean);
    }
    //Devide the sum by 4 cause there are 4 numbers and then take the square root
    std = sqrt(std / 4);

    //Obvisouly I have to return a float cause the function is a float function
    //The final answer is going to be writen in a file in the main function
    return std;
}

//code could be better did not consider the user input til the end