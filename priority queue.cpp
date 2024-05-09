#include <iostream> 
#include <queue> 
#include <string> 
struct Patient { 
    std::string name; 
    int priority; 
    bool operator<(const Patient& other) const { 
        return priority > other.priority; // Higher priority patients are served first 
    } 
}; 
int main() { 
    // Priority queue to store patients 
    std::priority_queue<Patient> hospitalQueue; 
    Patient patient1 = { "John", 2 };  // Non-serious 
    Patient patient2 = { "Mary", 1 };  // Serious 
    Patient patient3 = { "Alice", 3 }; // General Checkup 
    hospitalQueue.push(patient1); 
    hospitalQueue.push(patient2); 
    hospitalQueue.push(patient3); 
    while (!hospitalQueue.empty()) { 
        Patient servedPatient = hospitalQueue.top(); 
        hospitalQueue.pop(); 
        std::cout << "Serving patient: " << servedPatient.name << std::endl; 
    } 
 return 0; 
} 