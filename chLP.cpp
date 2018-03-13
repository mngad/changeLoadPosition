#include "csv.h"
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main(){

	std::ofstream outfile;
	outfile.open("out.csv");
	io::CSVReader<4> in("loadPosition.csv");
	std::string name; int posX; int posY; int posZ;
	while(in.read_row(name, posX, posY, posZ)){
		//std::cout <<name<<" "<<posX<<" "<<posY<<" "<<posZ<< std::endl;
		for(int i = 0; i<9;i++){
			

			//std::cout<<i<<std::endl;
			if(i==0)
				outfile << name<<", "<<posX<<", "<<posY<<", "<<posZ<<std::endl;	
			if(i==1)
				outfile << name<<i<<", "<<posX<<", "<<posY-1<<", "<<posZ<<std::endl;	
			if(i==2)
				outfile << name<<i<<", "<<posX+1<<", "<<posY<<", "<<posZ<<std::endl;	
			if(i==3)
				outfile << name<<i<<", "<<posX<<", "<<posY+1<<", "<<posZ<<std::endl;	
			if(i==4)
				outfile << name<<i<<", "<<posX-1<<", "<<posY<<", "<<posZ<<std::endl;	
			if(i==5)
				outfile << name<<i<<", "<<posX<<", "<<posY-2<<", "<<posZ<<std::endl;	
			if(i==6)
				outfile << name<<i<<", "<<posX+2<<", "<<posY<<", "<<posZ<<std::endl;	
			if(i==7)
				outfile << name<<i<<", "<<posX<<", "<<posY+2<<", "<<posZ<<std::endl;	
			if(i==8)
				outfile << name<<i<<", "<<posX-2<<", "<<posY<<", "<<posZ<<std::endl;	
			if(i>=1){
				std::string oldFname = name + ".inp";
				std::string newFname = name + std::to_string(i) + ".inp";
				//std::cout<<oldFname<<std::endl;
				//std::cout<<newFname<<std::endl;
				fs::copy(oldFname,newFname,fs::copy_options::overwrite_existing );
			}
		}
	}
	outfile.close();
	return 0;
}
