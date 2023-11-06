#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

void printInput(int numP, int numR, std::vector<int> ru, std::vector< std::vector<int> > adjM){
    std::cout << "Num processes: " << numP << "\n";
    std::cout << "Num resources: " << numR << "\n";
    std::cout << "Resources: ";
    for(int i=0; i<ru.size(); i++){
        std::cout << ru[i] << ",";
    }
    std::cout << "\n" << "ADJ matrix: \n";
    for(int i = 0; i<adjM.size(); i++){
        for(int j=0; j<adjM[i].size(); j++){
            std::cout << adjM[i][j] << ",";
        }
        std::cout << "\n";
    }
    
}

int main(){
    
    int num_processes, num_resources;
    std::vector<int> resource_units;
    std::vector< std::vector<int> > adj_matrix;
    std::ifstream fin ("input.txt");
    std::string line;
    int lineCount = 0;
    if(!fin.is_open()){
     //error opening file
        return 1;
    }
    
    while(getline(fin, line)){
        //skips line if not letter or number
        if(isalnum(line[0])){
            lineCount++;
            //number is located at index 14 in lines 1 and 2
            if(lineCount == 1){
                num_processes = std::stoi(line.substr(14));
            }
            if(lineCount == 2){
                num_resources = std::stoi(line.substr(14));
            }
            //resource units parsed by commas
            if(lineCount == 3){
                std::stringstream ss(line);
                while(ss.good()){
                    std::string sub;
                    getline(ss, sub, ',');
                    int x = std::stoi(sub);
                    resource_units.push_back(x);
                }   
            }
            //input adjacency matrix into 2d vector
            if(lineCount>3 && lineCount<=(num_resources+num_processes+3)){
                std::stringstream ss(line);
                std::vector<int> row;
                while(ss.good()){
                    std::string sub;
                    getline(ss, sub, ',');
                    int x = std::stoi(sub);
                    row.push_back(x);
                }
                adj_matrix.push_back(row);   
            }       
        }        
    }
    
    printInput(num_processes, num_resources, resource_units, adj_matrix);
    
    
        
    
    
    return 0;
}