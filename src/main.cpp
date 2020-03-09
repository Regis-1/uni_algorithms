#include <iostream>
#include <cstdlib>
#include <string>

#include "../include/Manager.hh"

int main(int argc, char* argv[]){
	if(argc == 4){
		Manager<int>* manager = new Manager<int>;
		int my_size = atoi(argv[1]);
		int my_ntests = atoi(argv[2]);
		std::string my_algorithm = std::string(argv[3]);

		//ARGUMENTS CHECK
		if(my_size == 0){
			std::cout<<"Wrong size value!"<<std::endl;
			return -1;
		}
		if(my_ntests <= 0){
			std::cout<<"Wrong test count value!"<<std::endl;
			return -1;
		}
		if(my_algorithm == "merge")
			manager->set_algorithm(merge);
		else if(my_algorithm == "quick")
			manager->set_algorithm(quick);
		else if(my_algorithm == "intro")
			manager->set_algorithm(intro);
		else{
			std::cout<<"Wrong sorting method!"<<std::endl;
			return -1;
		}

		int* my_array = manager->create_array(my_size); 
	}
	else{
		std::cout<< std::endl <<
			"Usage: ./s0rt_my_life [size of array] [number of tests] [sort algorithm]\n"<<
			"------------------------------------------------------------------------\n"<<
			"Available sorting algorithms: merge, quick, intro\n"<<std::endl;
	}

	return 0;
}
