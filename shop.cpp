#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class People {
    public:
        unsigned long people_count;
        unsigned short products_count;
        unsigned short time_at_checkout;
        People(unsigned long people_count): people_count(people_count){}
        
        void calculate_products()
        {
            products_count = 1 + rand() % 10;
        }
        
        void random_time_checkout()
        {
            time_at_checkout = 1 + rand() % 10;
        }
    
};
 
class Checkout {
    public:
        unsigned short max_open_checkouts;
        unsigned short time;
        unsigned short average_time_maintenance;
        unsigned short max_people_in_queue;
        Checkout(unsigned int moc): max_open_checkouts(moc){}

};

class Enqueue {
    private:
        unsigned short max_queue = 6;
};

int main() {
    unsigned long people;
    cout << "Enter how many people have come in: ";
    cin >> people;
    People People(people);

    unsigned short checkout_count;
    cout << "Enter max checkout count: ";
    cin >> checkout_count;
    Checkout Checkout(checkout_count);

    return 0;
}