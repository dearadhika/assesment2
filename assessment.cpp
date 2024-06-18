#include <iostream>
#include <cmath>  
#include <string>

using namespace std;

const double COST_PER_HOUR = 18.50;
const double COST_PER_MINUTE = 0.40;
const double COST_OF_DINNER = 20.70;

class Event {
private:
    string event_name;
    string first_name;
    string last_name;
    int num_guests;
    int num_minutes;
    int num_servers;
    double cost_for_one_server;
    double total_food_cost;
    double total_cost;
    double deposit_amount;
    double average_cost_per_person;

public:
    
    Event(string e_name, string f_name, string l_name, int guests, int minutes)
        : event_name(e_name), first_name(f_name), last_name(l_name), num_guests(guests), num_minutes(minutes) {
        num_servers = calculate_servers();
        cost_for_one_server = calculate_cost_for_one_server();
        total_food_cost = calculate_total_food_cost();
        total_cost = calculate_total_cost();
        deposit_amount = calculate_deposit_amount();
        average_cost_per_person = calculate_average_cost_per_person();
    }

    int calculate_servers() {
        return ceil(num_guests / 20.0);
    }

    double calculate_cost_for_one_server() {
        double cost1 = (num_minutes / 60) * COST_PER_HOUR;
        double cost2 = (num_minutes % 60) * COST_PER_MINUTE;
        return cost1 + cost2;
    }

    double calculate_total_food_cost() {
        return num_guests * COST_OF_DINNER;
    }

    double calculate_total_cost() {
        return total_food_cost + (cost_for_one_server * num_servers);
    }

    double calculate_deposit_amount() {
        return total_cost * 0.25;
    }

    double calculate_average_cost_per_person() {
        return total_food_cost / num_guests;
    }

    void display_event_details() {

        cout << "Number of Servers: " << num_servers << endl;
        cout << "Cost for Server: " << cost_for_one_server << endl;
        cout << "Total Food Cost: " << total_food_cost << endl;
        cout << "Average Cost Per Person: " << average_cost_per_person << endl;
        cout << "\n";
        cout << "Total Cost: " << total_cost << endl;
        cout << "please deposite a 25% deposite to reserve the event" << endl;
        cout << "The deposite need is :" << deposit_amount << endl;
    }
};

int main() {
    
    string event_name, first_name, last_name;
    int num_guests, num_minutes;
	cout << "***********************EVENT MANAGEMENT SYSTEM*********************** \n";
    cout << "Enter the name of the event: ";
    getline(cin, event_name);
    cout << "Enter your first name: ";
    getline(cin, first_name);
    cout << "Enter your last name: ";
    getline(cin, last_name);
    cout << "Enter the number of guests: ";
    cin >> num_guests;
    cout << "Enter the duration of the event in minutes: ";
    cin >> num_minutes;
     
     cout << "========================================event estimate for :"<< first_name <<" "<< last_name <<"========================================"<<"\n" ;
 
    Event event(event_name, first_name, last_name, num_guests, num_minutes);

    
    event.display_event_details();

    return 0;
}

