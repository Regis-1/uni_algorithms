#include "../include/Manager.hh"
#include <fstream>

int main(int argc, char* argv[]){
	if(argc == 5 || argc == 6){
		srand( time(NULL) );

		Manager<int>* manager = new Manager<int>;
		int my_size = atoi(argv[1]);
		int my_ntests = atoi(argv[2]);
		float my_sort_percent = std::stof(argv[3]);
		std::string my_algorithm = std::string(argv[4]);
		bool will_print = false;

		bool will_save = false;
		std::string path = "./results.txt";
		std::ofstream file;

		//ARGUMENTS CHECK
		if(my_size == 0){
			std::cout<<"Wrong size value!"<<std::endl;
			return -1;
		}
		if(my_ntests <= 0){
			std::cout<<"Wrong test count value!"<<std::endl;
			return -1;
		}
		if((my_sort_percent != -1 && my_sort_percent < 0) || my_sort_percent > 100){
			std::cout<<"Wrong starting sorted percentage value!"<<std::endl;
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
		if(argc == 6){
			std::string output_opt = std::string(argv[5]);
			if(output_opt == "-p")
				will_print = true;
			else if(output_opt == "-s")
				will_save = true;
			else
				std::cout<<"Wrong usage of 5th argument!"<<std::endl;
		}

		//CREATING AN ARRAY
		int* my_array = manager->create_array(my_size); 

		//CREATING HEADER IN OUTPUT FILE
		if(will_save){
			file.open(path);
			file << my_size << "," << my_ntests << "," << my_sort_percent << "," << my_algorithm << "\n";
		}

		//MAIN LOOP OF PROGRAM
		for(int i = 0; i < my_ntests; i++){
			//RANDOMIZING
			manager->random_array(my_array, my_size);

			//SORTING BEGINNING PART FOR GIVEN PERCENTAGE
			if(my_sort_percent != 0){
				if(my_sort_percent != -1){
					int eobs = manager->get_eobs(my_size, my_sort_percent);
					manager->sort_array(my_array, 0, eobs-1, my_size);
				}
				else{
					manager->sort_array(my_array, 0, my_size-1, my_size);
					manager->reverse_array(my_array, my_size);
				}
			}

			//SORTING
			long int duration = manager->sort_array(my_array, 0, my_size-1, my_size);
			if(will_print)
				manager->print_array(my_array, my_size);
			auto duration_ms = duration/1000.0;
			if(will_save)
				file << i+1 << "," << duration_ms << "\n";
			else
				std::cout<< std::endl << "Duration [ms] >> " << duration_ms << std::endl;
		}

		if(will_save)
			file.close();
	}
	else{
		std::cout<< std::endl <<
			"Usage: ./s0rt_my_life [size of array] [number of tests] [percentage of sorted elements] [sort algorithm] ([-p or -s])\n"<<
			"---------------------------------------------------------------------------------------------------------------------\n"<<
			"Available sorting algorithms: merge, quick, intro\n"<<std::endl;
	}

	return 0;
}
