#include <iostream>
#include <vector>
#include <thread>
#include <time.h>

static const int num_threads = 20;
void sleep_and_print(int x)
{
    // sleep for time x
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
    std::cout<<x<<" ";
}

int main() {

    srand(time(NULL));
    std::vector<int> num_list;
    std::cout<<std::flush;
    std::cout<<"Unsorted list: "<<std::endl;
    
    for(size_t i = 0; i< 20; i++)
    {
        int num = int(rand()%100);
        std::cout<<num<<" ";
        num_list.push_back(num);
    }

    std::vector<std::shared_ptr<std::thread>> threads_vec(num_list.size());

    for (int i = 0; i < num_list.size(); ++i) {
        threads_vec[i] = std::make_shared<std::thread>(sleep_and_print, num_list[i]);
    }

    std::cout << "\nSorted list: \n";

    //Join the threads with the main thread. 
    for (int i = 0; i < num_threads; ++i) {
        threads_vec[i]->join();
    }

    return 0;
}