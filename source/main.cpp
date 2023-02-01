#include <iostream>
#include <iomanip>
#include "../library/RaceInAir.h"
#include "../library/RaceOnGround.h"
#include "../library/RaceOnGroundAndInAir.h"



enum class TRANSPORT_AIR{
    BROOMSTICK,
    MAGIC_CARPET,
    EAGLE,
    MAX_NUMB
};

enum class TRANSPORT_GROUND{
    CAMEL_IS_FAST,
    CENTAUR,
    CAMEL,
    ALL_TERRAIN_BOOTS,
    MAX_NUMB
};

enum class TRANSPORT_ALL{
    CAMEL_IS_FAST,
    CENTAUR,
    CAMEL,
    ALL_TERRAIN_BOOTS,
    BROOMSTICK,
    MAGIC_CARPET,
    EAGLE,
    MAX_NUMB
};

int greeting_out_and_choice(){
    std::cout << "Welcome to this wonderful game.\n"
        << "Choose a track where the best racers and their vehicles will fight.\n"
        << "air route [1]\nland route [2]\nland-air route [3]\n"
        << "To exit, press [0] \n";
    int choice = 0;
    while(true){
        std::cout << "Your choice => ";
        std::cin >> choice;
        if(std::cin.fail() || choice > 3 || choice < 0){
            std::cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		    std::cout << "Erroneous input, try again" << '\n';
	    }
	    else{
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;            
        }
    }
    if(choice == 0){
        std::cout << "Good bye\n";
        exit(0);
    }
    return choice;
}

int distance_sampling(){
    int distance = 0;
    std::cout << "Congratulations, you have chosen the track.\nNow select the route distance.\n";
    while(true){
        std::cout << "Your choice => ";
        std::cin >> distance;
        if(std::cin.fail() || distance <= 0){
            std::cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		    std::cout << "Erroneous input, try again" << '\n';
	    }
	    else{
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;            
        }  
    } 
    return distance;
}

template <typename PTR_RACE>
void table_name_time_output_only_race_air_and_only_race_ground(const std::shared_ptr<PTR_RACE> race){
    std::cout << std::setw(25) <<"Table of participants" << '\n';
    std::cout << std::setw(20) << "*Participants*" << std::setw(12) << "*Time*\n";
    for(int idx_i = 0; idx_i < race->get_size(); ++idx_i){
        std::cout << "|" << std::setw(20) << race->get_name(idx_i) << "|";
        std::cout << std::setw(10) << race->get_time(idx_i) << "|" << '\n';
    }
}

template <typename PTR_RACE>
void table_name_output_only_race_air_and_only_race_ground(const std::shared_ptr<PTR_RACE> race){
    std::cout << std::setw(25) <<"Table of participants" << '\n';
    std::cout << std::setw(20) << "*Participants*\n";
    for(int idx_i = 0; idx_i < race->get_size(); ++idx_i){
        std::cout << "|" <<std::setw(20) << race->get_name(idx_i) << "|" <<'\n';
    }
}

void table_name_output_all_race(const std::shared_ptr<IRaceAirGround> race){
    std::cout << std::setw(30) <<"Table of participants" << '\n';
    std::cout << std::setw(25) << "*Participants*\n";
    for(int idx_i = 0; idx_i < race->get_size_air_vec(); ++idx_i){
        std::cout << "|" << std::setw(20) << race->get_name_air_vec(idx_i);
        std::cout << std::setw(10) << race->get_specilization_air_vec(idx_i) << "|" <<'\n';
    }
    for(int idx_i = 0; idx_i < race->get_size_ground_vec(); ++idx_i){
        std::cout << "|" << std::setw(20) << race->get_name_ground_vec(idx_i);
        std::cout << std::setw(10) << race->get_specilization_ground_vec(idx_i) << "|" <<'\n';
    }    
}

void table_name_time_output_all_race(const std::shared_ptr<IRaceAirGround> race){
    std::cout << std::setw(30) <<"Table of participants" << '\n';
    std::cout << std::setw(20) << "*Participants*" << std::setw(20) << "*Time*\n";
    for(int idx_i = 0; idx_i < race->get_size_air_ground_vec(); ++idx_i){
        std::cout << "|" << std::setw(20) << race->get_name_air_ground_vec(idx_i) << "|";
        std::cout << std::setw(20) << race->get_time(idx_i) << "|" << '\n';
    }
}

bool exit_register(const int &minimum_number_vehicles){
    if(minimum_number_vehicles < 2){
        std::cout << "The minimum number of vehicles must be more than two.\n";
        return true;
    }
    int choice_again = 1;
    std::cout << "Don't you want to choose again? Yes [1] or No [0]\n";
    while(true){
        std::cout << "Your choice => ";
        std::cin >> choice_again;
        if(std::cin.fail() || choice_again > 1 || choice_again < 0){
            std::cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		    std::cout << "Erroneous input, try again" << '\n';
	    }
	    else{
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;  
        }       
    }
    if(choice_again == 1)
        return true;
    return false;
}

void cheking_vehicle_selection(int& choice, const int & max_numb_vehicle){
    while(true){
            std::cout << "Your choice of vehicle => ";
            std::cin >> choice;
            if(std::cin.fail() || choice > max_numb_vehicle || choice < 0){
                std::cin.clear();
		        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		        std::cout << "Erroneous input, try again" << '\n';
	        }
	        else{
		        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;  
            }         
        }
}

bool checking_vectors_emptiness(const std::shared_ptr<IRaceAirGround> &race){
    if(race->get_size_air_vec() == 0){
            std::cout << "You need to enter at least one air transport\n";
            return true;
    }
    if(race->get_size_ground_vec() == 0){
            std::cout << "You need to enter at least one ground transport\n";
            return true;
        }
    return false;
}

void game_race_air(const int &distance){
    int choice = 0;
    int minimum_number_vehicles = 0;
    int counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::MAX_NUMB)]{0,0,0};
    std::shared_ptr<IRaceAir> race = IRaceAir::creat_race_in_air(distance);
    std::cout << "Register transports to participate in the race.\n"
        << "Broomstick [1]\nMagic Carpet [2]\nEagle [3]\n" 
        << "To exit, press [0]\n";
    while(true){
        cheking_vehicle_selection(choice, static_cast<int>(TRANSPORT_AIR::MAX_NUMB));
        switch(choice){
            case 1: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::BROOMSTICK)] == 0){
                        race->set_broomstick();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::BROOMSTICK)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                    break;
                    }
            case 2: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::MAGIC_CARPET)] == 0){
                        race->set_magic_carpet();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::MAGIC_CARPET)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                    break;
                    }
            case 3: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::EAGLE)] == 0){
                        race->set_eagle();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_AIR::EAGLE)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                        break;
                    }
        }
        if(minimum_number_vehicles == static_cast<int>(TRANSPORT_AIR::MAX_NUMB))
            break;      
        if(choice == 0){
            if(exit_register(minimum_number_vehicles))
                continue;
            else
                break;
        }
    }
    table_name_output_only_race_air_and_only_race_ground(race);
    std::cout << "The race has begun\nNow we will find out the winners\n";
    race->bubble_sort_transport();
    table_name_time_output_only_race_air_and_only_race_ground(race);
}

void game_race_ground(const int &distance){
    int choice = 0;
    int minimum_number_vehicles = 0;
    int counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::MAX_NUMB)]{0,0,0};
    std::shared_ptr<IRaceGround> race = IRaceGround::creat_race_on_ground(distance);
    std::cout << "Register transports to participate in the race.\n"
        << "Camel is fast [1]\nCentraur [2]\nCamel [3]\nAll Terrain Boots [4]\n"
        << "To exit, press [0]\n";
    while(true){
        cheking_vehicle_selection(choice, static_cast<int>(TRANSPORT_GROUND::MAX_NUMB));
        switch(choice){
            case 1: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CAMEL_IS_FAST)] == 0){
                        race->set_camel_is_fast();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CAMEL_IS_FAST)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                        break;
                    }
            case 2: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CENTAUR)] == 0){
                        race->set_centaur();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CENTAUR)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                        break;
                    }
            case 3: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CAMEL)] == 0){
                        race->set_camel();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::CAMEL)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                        break;
                    }
            case 4: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::ALL_TERRAIN_BOOTS)] == 0){
                        race->set_all_terrain_boots();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_GROUND::ALL_TERRAIN_BOOTS)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                        break;
                    }
                
        }
        if(minimum_number_vehicles == static_cast<int>(TRANSPORT_GROUND::MAX_NUMB))
            break;      
        if(choice == 0){
            if(exit_register(minimum_number_vehicles))
                continue;
            else
                break;
        }
    }
    table_name_output_only_race_air_and_only_race_ground(race);
    std::cout << "The race has begun\nNow we will find out the winners\n";
    race->bubble_sort_transport();
    table_name_time_output_only_race_air_and_only_race_ground(race);
}

void game_race_air_and_ground(const int &distance){
    int choice = 0;
    int minimum_number_vehicles = 0;
    int counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::MAX_NUMB)]{0,0,0};
    std::shared_ptr<IRaceAirGround> race = IRaceAirGround::creat_race_on_ground_in_air(distance);
    std::cout << "Register transports to participate in the race.\n"
        << "Camel is fast [1]\nCentraur [2]\nCamel [3]\nAll Terrain Boots [4]\n" 
        << "Broomstick [5]\nMagic Carpet [6]\nEagle [7]\n"
        << "To exit, press [0]\n";
    while(true){
        cheking_vehicle_selection(choice, static_cast<int>(TRANSPORT_ALL::MAX_NUMB));
        switch(choice){
            case 1: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CAMEL_IS_FAST)] == 0){
                        race->set_camel_is_fast();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CAMEL_IS_FAST)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                        break;
                    }
            case 2: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CENTAUR)] == 0){
                        race->set_centaur();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CENTAUR)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                        break;
                    }
            case 3: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CAMEL)] == 0){
                        race->set_camel();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::CAMEL)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                        break;
                    }
            case 4: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::ALL_TERRAIN_BOOTS)] == 0){
                        race->set_all_terrain_boots();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::ALL_TERRAIN_BOOTS)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                        break;
                    }
            case 5: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::BROOMSTICK)] == 0){
                        race->set_broomstick();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::BROOMSTICK)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                    break;
                    }
            case 6: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::MAGIC_CARPET)] == 0){
                        race->set_magic_carpet();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::MAGIC_CARPET)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                    break;
                    }
            case 7: if(counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::EAGLE)] == 0){
                        race->set_eagle();
                        ++minimum_number_vehicles;
                        ++counter_selected_vehicle[static_cast<int>(TRANSPORT_ALL::EAGLE)];
                        break;
                    }else{
                        std::cout << "You have already registered this vehicle\n";
                        break;
                    }
        }
        if(minimum_number_vehicles == static_cast<int>(TRANSPORT_ALL::MAX_NUMB))
            break;
        if(choice == 0){
            if(exit_register(minimum_number_vehicles)){
                continue;
            }
            else{
                if(!checking_vectors_emptiness(race)){
                    break;
                }else
                    continue;
            }
        }
    }
    table_name_output_all_race(race);
    std::cout << "The race has begun\nNow we will find out the winners\n";
    race->bubble_sort_transport();
    table_name_time_output_all_race(race);
}
// win ground = CamelIsFast, Centaur, Camel, AllTerrainBoots
// win air = Broomstick, MagicCarpet, Eagle
// win air and ground = CamelIsFast, Broomstick, Centaur, MagicCarpet/Camel, Eagle, AllTerrainBoots

int main() {
    int choice_race = greeting_out_and_choice();
    int distance = distance_sampling();
    switch (choice_race){
        case 1: game_race_air(distance); break;
        case 2: game_race_ground(distance); break;
        case 3: game_race_air_and_ground(distance); break;
    }
    std::cout <<std::setw(25) << "!Game over!";
    return 0;
}