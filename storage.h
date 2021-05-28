#include <string>
using namespace std;
class storage{
   private:
    float barCode;
    string name;
    float weight;
    float price;
    float number;
    
    public:
    storage();
    storage(bool value);
    void add(storage *arr,int notes);
    void del(storage *arr);
    void print(storage *arr,int notes);
    void search(storage *arr,int notes);
    void edit(storage *arr);
    void triage(storage *arr,int notes);
};
