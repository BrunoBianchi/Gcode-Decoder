
#include <iostream>
#include <fstream>

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include <math.h>
#include <vector>
using namespace std;
#include "Moviment.h"

string Code;

float x = 0, y = 0, z = 0, f = 0,power = 0,pot = 0;
float oldX = 0,oldY = 0,oldZ = 0,oldF = 0;


int main() {
    MotorMoviment Motor;

    string Gcode;

    ifstream myReadFile("test.txt");
while (getline(myReadFile, Gcode)) {
    int index = 0;
    for(int i = 0;i<Gcode.size();i++) {
        while(Gcode[i] != ' '&& i<3) {
            Code += Gcode[i];
            i++;
        }
        switch(Gcode[i]) {
            case 'F':
            {
                vector<int>Fvec;
                f = 0;
                power = 0;
                pot = 10;
                i++;
                while(Gcode[i] != ' '&&i <Gcode.size()) {
                    Fvec.push_back(int(Gcode[i] - 48));
                    i++;
                };
                for(int vecIndex = Fvec.size() - 1;vecIndex>=0;vecIndex--) {
                    f+= pow(pot,power) * Fvec.at(vecIndex);
                    power++;
                }   
            }
            break; 

            case 'X':
            {
                vector<float>Xvec;
                x = 0;
                power = 0;
                pot = 10;
                int decimal = 0;
                i++;
                while(Gcode[i] != ' ' && i <Gcode.size()) {
                    if(Gcode[i] == 46) {
                        int decIndex = i;
                        while(Gcode[decIndex] != ' ') {
                               decimal++;    
                               decIndex++;                          
                        }
                        decimal -=1;
                    }else {
                        Xvec.push_back(int(Gcode[i] - 48));
                    }
                    i++;
                };
                for(int vecIndex = Xvec.size() - 1;vecIndex >= 0;vecIndex--) {
                    x+= (pow(pot,power) * Xvec.at(vecIndex));
                    power++;
                }  
                x = x/pow(10,decimal);
            }
            break; 
        
            case 'Y':
            {
                vector<float>Yvec;
                y = 0;
                power = 0;
                pot = 10;
                int decimal = 0;
                i++;
                while(Gcode[i] != ' ' && i <Gcode.size()) {
                    if(Gcode[i] == 46) {
                        int decIndex = i;
                        while(decIndex<Gcode.size()) {
                               decimal++;    
                               decIndex++;                          
                        }
                        decimal -=1;
                    }else {
                        Yvec.push_back(int(Gcode[i] - 48));
                    }
                    i++;
                };
                for(int vecIndex = Yvec.size() - 1;vecIndex >= 0;vecIndex--) {
                    y+= (pow(pot,power) * Yvec.at(vecIndex));
                    power++;
                }  
                y = y/pow(10,decimal);
            }
            break; 

            case 'Z':
            {
                vector<float>Zvec;
                z = 0;
                power = 0;
                pot = 10;
                int decimal = 0;
                int  multiplier = 1;
                i++;
                while(Gcode[i] != ' ' && i <Gcode.size()) {
                    if(Gcode[i] == 46) {
                        int decIndex = i;
                        while(decIndex<Gcode.size()) {
                               decimal++;    
                               decIndex++;                          
                        }
                        decimal -=1;
                    }else {
                        if(Gcode[i] == 45) {
                            multiplier = -1;
                        }else {
                            Zvec.push_back(int(Gcode[i] - 48));
                        }
                    }
                    i++;
                };
                for(int vecIndex = Zvec.size() - 1;vecIndex >= 0;vecIndex--) {
                    z+= (pow(pot,power) * Zvec.at(vecIndex));
                    power++;
                }  
                z = (z/pow(10,decimal)) * multiplier;
            }
            break;             
        }

    }
     if(Code == "G00") {
        if(oldX != x || oldY != y || oldZ != z || oldF !=f) {
            Motor.ciruclarClock(x,y,z,f,oldX,oldY,oldZ,oldF);
           
        }else if(oldX == x && oldY == y&& oldZ == z&& oldF == f) {
             cout<<"Normal Linear"<<endl;
        }
     }else if(Code =="G01") {
        if(oldX != x || oldY != y || oldZ != z || oldF !=f) {
            Motor.ciruclarClock(x,y,z,f,oldX,oldY,oldZ,oldF);                   
        }else if(oldX == x && oldY == y&& oldZ == z&& oldF == f) {
             cout<<"Normal circular"<<endl;
        }
     }else if(Code == "M03") {
        Motor.spinClock();
     }else if(Code == "M05") {
        Motor.stopSpin();
     }else if(Code == "M30") {
        Motor.stopAll();
     }
     oldX = x;
     oldY = y;
     oldZ = z;
     oldF = f;        
    Code = "";
puts("\n");
Sleep(50);
}
// Close the file
myReadFile.close();

return 1;
}