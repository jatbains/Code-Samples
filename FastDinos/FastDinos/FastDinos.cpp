// FastDinos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
# You will be supplied with two data files in CSV format.The first file contains statistics about various dinosaurs.The second file contains additional data.
# Given the following formula,
# speed = ((STRIDE_LENGTH / LEG_LENGTH) - 1) * SQRT(LEG_LENGTH * g)
# Where g = 9.8 m / s ^ 2 (gravitational constant)

# Write a program to read in the data files from disk, it must then print the names of only the bipedal dinosaurs from fastest to slowest.Do not print any other information.

# $ cat dataset1.csv
# NAME, LEG_LENGTH, DIET
# Hadrosaurus, 1.2, herbivore
# Struthiomimus, 0.92, omnivore
# Velociraptor, 1.0, carnivore
# Triceratops, 0.87, herbivore
# Euoplocephalus, 1.6, herbivore
# Stegosaurus, 1.40, herbivore
# Tyrannosaurus Rex, 2.5, carnivore

# $ cat dataset2.csv
# NAME, STRIDE_LENGTH, STANCE
# Euoplocephalus, 1.87, quadrupedal
# Stegosaurus, 1.90, quadrupedal
# Tyrannosaurus Rex, 5.76, bipedal
# Hadrosaurus, 1.4, bipedal
# Deinonychus, 1.21, bipedal
# Struthiomimus, 1.34, bipedal
# Velociraptor, 2.72, bipedal

*/
// Parameters that are relevant :  leg_length, stride, quadraped or biped . 
//                                 Only bipedal fastest to slowest


#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

typedef struct DINO {
    string name;
    float legLen;
    float stride;
    string diet;
    string type;
    float speed;
}DINO;

/*
Comparator compFunctor =
[](std::pair<std::string, int> elem1, std::pair<std::string, int> elem2)
{
    return elem1.second < elem2.second;
};
*/
typedef pair<string, float> dPair;

int main()
{
    // Open files first
    ifstream dino1;
    ifstream dino2;
    string line1, line2;

    map<string, DINO> dinos;

    DINO dino = { "Hadrosaurus",1.2,1.4,"herbivore","bipedal" };
    dinos["Hadrosaurus"] = dino;
    dino = { "Struthiomimus",0.92,1.34,"omnivore","bipedal" };
    dinos["Struthiomimus"] = dino;
    dino = { "Velociraptor",1.0,2.72,"carnivore","bipedal" };
    dinos["Velociraptor"] = dino;
    dino = { "Triceratops",0.87,0,"herbivore","quadrupedal" };
    dinos["Triceratops"] = dino;
    dino = { "Euoplocephalus",1.6,1.87,"herbivore","quadrupedal" };
    dinos["Euoplocephalus"] = dino;
    dino = { "Stegosaurus",1.4,1.9,"herbivore","quadrupedal" };
    dinos["Stegosaurus"] = dino;
    dino = { "Tyrannosaurus Rex",2.5,5.76,"carnivore","bipedal" };
    dinos["Tyrannosaurus Rex"] = dino;
    dino = { "Deinonychus",0, 1.21,"", "bipedal" };
    dinos["Deinonychus"] = dino;

    map<string, DINO>::iterator it = dinos.begin();
    while (it != dinos.end()) {
        
        if (it->second.type == "bipedal" && it->second.legLen != 0) {
            it->second.speed = ((it->second.stride / it->second.legLen) - 1) * sqrt(it->second.legLen * 9.8);
        }
        it++;
    }
    // Sort based on speed
    it = dinos.begin();
    // Create a vector for disnos
    vector<pair<string, float>> fastDinos;
    while (it != dinos.end()) {
        if (it->second.type == "bipedal" && it->second.legLen !=0) {
            fastDinos.push_back(make_pair(it->second.name, it->second.speed));
        }
        it++;
    }
    sort(fastDinos.begin(), fastDinos.end(), [](pair<string, float> dino1, pair<string, float> dino2)
        {
            return dino1.second > dino2.second;
        });

    // Print out sorted dinos
    for (dPair dino : fastDinos) {
        cout << dino.first << " " << dino.second << endl;
    }
   
  
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
