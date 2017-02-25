/*
 * prog5_acd21.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: Adam C. De Leon
 *      Description: This program reads in an input file that contains
 *      home room numbers and quantities of money. The program then
 *      calculates the totals for each homeroom and displays the results as a
 *      report to an output file. The program also validates the successful
 *      opening of an input file as well as the successful creation of an
 *      output file.
 *
 *      Input file: senoirs_rule.txt
 *      Output file: prog5_out_acd21.txt
 *      Return Errors: 1 - Output file creation error.
 *      			   2 - Input file open error.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin;                    //Input file object.
    ofstream fout;                        //Output file object.

    // Variable declarations
    string HMRM_1 = "101";
    string HMRM_2 = "112";
    string HMRM_3 = "203";
    string HMRM_4 = "214";
    string HMRM_5 = "222";
    string SENTINEL = "0";        //End of data marker
    string hmrm;
    double amount;
    double sum_1;
    double sum_2;
    double sum_3;
    double sum_4;
    double sum_5;
    double total;


    // Open the input and output files.
    fin.open("seniors_rule.txt");
    fout.open("prog5_out_acd21.txt");

    // Validate the files existence and successful open.
    if (!fout) {
        cout << "The output file could not be created." << endl;
        return 1;
    }
    if (!fin) {
        cout << "Input file failed to open. Make sure it exists in the "
                "correct location." << endl;
        return 2;
    } else {
        //Initialize the sum values.
        sum_1 = 0;
        sum_2 = 0;
        sum_3 = 0;
        sum_4 = 0;
        sum_5 = 0;

        // Read in the input file and process the data until the sentinel
        // value "0" is reached.
        fin >> hmrm;
        while (hmrm != SENTINEL) {
            fin >> amount;
            fout << setprecision(2) << fixed;
            if (hmrm == HMRM_1)
                sum_1 = sum_1 + amount;
            else if (hmrm == HMRM_2)
                sum_2 = sum_2 + amount;
            else if (hmrm == HMRM_3)
                sum_3 = sum_3 + amount;
            else if (hmrm == HMRM_4)
                sum_4 = sum_4 + amount;
            else if (hmrm == HMRM_5)
                sum_5 = sum_5 + amount;
            fin >> hmrm;
        }

        // Write the information to the output file.
        total = sum_1 + sum_2 + sum_3 + sum_4 + sum_5;
        fout << "Sales raised by Shennanagans High School senior class "
                "fund raiser." << endl;
        fout << "Homeroom :" << HMRM_1 << "\t$" << sum_1 << endl;
        fout << "Homeroom :" << HMRM_2 << "\t$" << sum_2 << endl;
        fout << "Homeroom :" << HMRM_3 << "\t$" << sum_3 << endl;
        fout << "Homeroom :" << HMRM_4 << "\t$" << sum_4 << endl;
        fout << "Homeroom :" << HMRM_5 << "\t$" << sum_5 << endl;
        fout << "Total Sales :" << "\t$" << total << endl;
    }
    // Close the input and output files.
    fin.close();
    fout.close();

    return 0;
}



