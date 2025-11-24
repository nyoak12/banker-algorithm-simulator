#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

std::vector<int> available = {0, 0, 0};

//class for creating process objects to hold resource data
class Process{
    public:
        Process(std::vector<int> allocation, std::vector<int> max) 
                 : allocation_(allocation), max_(max){processID = nextID++;}
        int getID(){return processID;}
        std::vector<int> getAllocation(){return allocation_;}
        std::vector<int> getMax(){return max_;}
        std::vector<int> getNeeds(){
            std::vector<int> needs={0, 0, 0};
            for(int i = 0; i < needs.size(); ++i)
                needs[i] = max_[i] - allocation_[i];
            return needs;
        }

        std::vector<int> updateResources(){
            std::vector<int> nAvailable = available;
            for(int i = 0; i < nAvailable.size(); ++i) nAvailable[i] = available[i] + allocation_[i];
            return nAvailable;
        }

        bool canRun(){
            std::vector<int> needs = getNeeds();
            for(int i = 0; i < needs.size(); ++i){
                if((available[i] - needs[i]) < 0) return false;
            }return true;
        }
    private:
        std::vector<int> allocation_;
        std::vector<int> max_;
        int processID;
        static int nextID;

};

int Process::nextID = 0;

int main(){

std::ifstream file("data.txt");
std::string line;
std::vector<Process> p;

while (std::getline(file, line)) {
    if (line.empty() || line[0] == '#') continue;

    std::stringstream ss(line);

    //parameters for process objects
    std::vector<int> alloc(3), maxN(3);
    char bar;

    //create process objects from data.txt
    if (ss >> alloc[0] >> alloc[1] >> alloc[2] >> bar >> maxN[0] >> maxN[1] >> maxN[2]) {
        p.emplace_back(alloc, maxN);
    } else {
        // available resources
        ss.clear();
        ss.str(line);
        int a,b,c;
        ss >> a >> b >> c;
        available = {a,b,c};
    }
}

    //checks for safe state , then prints out sequence if safe state is true
    std::vector<int> sequence;

    int count = p.size();
    int progress = p.size();
    bool safeState = true;
    while(!p.empty()){

        for(auto it = p.begin(); it != p.end(); ){
            if(it->canRun()){
                sequence.push_back(it->getID());
                available = it->updateResources();
                it = p.erase(it);
                --progress;
                                
            }else ++it;
        
        }
        if(progress == count){
            std::cout << "System state = not safe";
            safeState = false;
            break;

        }else count = progress;
    }

    if(safeState){
        std::cout <<"System state = safe\nSequence: ";
        for(auto s: sequence){
            std::cout << "P" << s << "->";
        }
    }std::cout << std::endl;
      
}