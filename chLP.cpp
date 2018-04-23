#include "csv.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
//#include <experimental/filesystem>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

int main(int argc,char* argv[]){
    int loadPos1;
    int loadPos2;
    if(argc==1){
        printf("\nEnter the two positions");
        return 0;
    }
    if(argc>=2){
        std::stringstream (argv[1]) >> loadPos1;
        std::stringstream (argv[2]) >> loadPos2;
        
    }
                       
    

	std::ofstream outfile;
	outfile.open("out.csv");
	io::CSVReader<4> in("loadPosition.csv");
	std::string name; int posX; int posY; int posZ;
    
    fs::detail::create_directory(fs::path("original_inps"));
	
    while(in.read_row(name, posX, posY, posZ)){
		for(int i = 0; i<9;i++){
			if(i==0)
				outfile << name<<"_position_"<<i<<", "<<posX<<", "<<posY<<", "<<posZ<<std::endl;
			if(i==1)
				outfile << name<<"_position_"<<i<<", "<<posX<<", "<<posY-loadPos1<<", "<<posZ<<std::endl;
			if(i==2)
				outfile << name<<"_position_"<<i<<", "<<posX+loadPos1<<", "<<posY<<", "<<posZ<<std::endl;
			if(i==3)
				outfile << name<<"_position_"<<i<<", "<<posX<<", "<<posY+loadPos1<<", "<<posZ<<std::endl;
			if(i==4)
				outfile << name<<"_position_"<<i<<", "<<posX-loadPos1<<", "<<posY<<", "<<posZ<<std::endl;
			if(i==5)
				outfile << name<<"_position_"<<i<<", "<<posX<<", "<<posY-loadPos2<<", "<<posZ<<std::endl;
			if(i==6)
				outfile << name<<"_position_"<<i<<", "<<posX+loadPos2<<", "<<posY<<", "<<posZ<<std::endl;
			if(i==7)
				outfile << name<<"_position_"<<i<<", "<<posX<<", "<<posY+loadPos2<<", "<<posZ<<std::endl;
			if(i==8)
				outfile << name<<"_position_"<<i<<", "<<posX-loadPos2<<", "<<posY<<", "<<posZ<<std::endl;
            
            std::string oldFname = name + ".inp";
            std::string newFname = name +"_lp_"+std::to_string(loadPos1)+"_"+std::to_string(loadPos2)+"_"+ "_position_" + std::to_string(i) + ".inp";
            fs::detail::copy_file(fs::path(oldFname), fs::path(newFname),fs::detail::copy_option::overwrite_if_exists);
			
            
		}
        std::string oldPos = name + ".inp";
        std::string newPos = "original_inps/" + name + ".inp";
        std::cout<<"oldpos = "<<oldPos<<std::endl;
        std::cout<<"newpos = "<<newPos<<std::endl;
        fs::rename(fs::path(oldPos), fs::path(newPos));
	}
    
	
    outfile.close();
	return 0;
}
