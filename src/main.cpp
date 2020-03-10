#include "../include/Manager.hh"

int main(int argc, char* argv[]){
	if(argc == 4 || argc == 5){
		srand( time(NULL) );

		Manager<int>* manager = new Manager<int>;
		int my_size = atoi(argv[1]);
		int my_ntests = atoi(argv[2]);
		std::string my_algorithm = std::string(argv[3]);
		bool will_print = false;

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
		if(argc == 5){
			std::string print_opt = std::string(argv[4]);
			if(print_opt == "-p")
				will_print = true;
			else
				std::cout<<"Wrong usage of 4th argument!"<<std::endl;
		}

		int* my_array = manager->create_array(my_size); 
		manager->random_array(my_array, my_size);

		//SORTING
		long int duration = manager->sort_array(my_array, 0, my_size-1);

		if(will_print)
			manager->print_array(my_array, my_size);
		auto duration_ms = duration/1000.0;

		std::cout<< std::endl << "Duration [ms] >> " << duration_ms << std::endl;
	}
	else{
		std::cout<< std::endl <<
			"Usage: ./s0rt_my_life [size of array] [number of tests] [sort algorithm] ([-p for print the array])\n"<<
			"---------------------------------------------------------------------------------------------------\n"<<
			"Available sorting algorithms: merge, quick, intro\n"<<std::endl;
	}

	return 0;
}
