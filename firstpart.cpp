#include <iostream>
#include <string>
#include <map>


using namespace std;


class Secretary;                  //Forward declaration of Secretary class to make it a friend

class Person{
    private:
        static int count;       // Counter for the number of Person objects
        int keynumber;         //Keynumber can be whatever eg Arithmos Tautothtas or sdi etc
        int age;
        string name;
        string lastname;
        friend class Secretary;    //that can only go in the private part of th eclass
    public:
        Person(){
            count++;
            cout<<"constructed"<<endl;
        }
        Person(string n,string l, int k, int a){
            name=n; 
            lastname=l; 
            keynumber=k;
            age=a;
            count++;
            cout<<"constructed"<<endl;
        }
        ~Person() {
            count--;
            cout<<"deconstructed"<<endl;
        }
        static int getcount(){                //static is sos if you wanna be able to call it not on an instance
            return count;
        }
        // Overloading the output operator
        friend ostream& operator<<(ostream& os, const Person& pers) {
            os<<pers.name<<endl;
            os<<pers.lastname<<endl;
            os<<pers.keynumber<<endl;
            os<<pers.age<<endl;
            return os;
        }
        // Overloading the input operator
        friend istream& operator>>(istream& is, Person& pers) {
            cout<<"give name:";
            is>>pers.name;
            cout<<"give lastname:";
            is>>pers.lastname;
            cout<<"give keynumber:";
            is>>pers.keynumber;
            cout<<"give age:";
            is>>pers.age;
            count++;
            return is;
        }
        // Overloading the equality operator for Person
        bool operator==(const Person& other)const{
            return (name==other.name &&
                    lastname==other.lastname &&
                    keynumber==other.keynumber &&
                    age==other.age);
        }
};

int Person::count=0;                                              // Initializing the static member count




class Secretary{
    private:
        map<int, Person*>department;                          // Map to store Person objects
    public:
        Secretary(){                                        //i dont need anything more, map and etc vars are created when an instance is
            cout<<"secretary constructed"<<endl;
        }
        ~Secretary(){                                     // Deleting the dynamically allocated Persons
            map<int, Person*>::iterator it; 
            for(it = department.begin();it!=department.end();it++){
                delete it->second;
            }
            cout<<"secretary destructed"<<endl;
        }
        // Check if a specific Person exists in the department
        bool containsperson(const Person& persontofind)const{
            map<int, Person*>::const_iterator it;
            for(it=department.begin();it!=department.end();it++){
                if(*(it->second)==persontofind){
                    return true;
                }
            }
            return false;
        }
        // Copy Constructor
        Secretary(const Secretary& other){
            map<int, Person*>::const_iterator it;
            for(it = other.department.begin();it!=other.department.end();it++){
                department[it->first]=new Person(*(it->second));
            }
            cout<<"secretary copy constructed"<<endl;
        }
        // Overloading the addition operator
        void operator+=(Person* person){	
            map<int, Person*>::iterator it;
            it=department.find(person->keynumber);   // Delete the existing Person object if it exists to not have memory leaks
            if(it!=department.end()) {
                delete it->second;
            }
            department[person->keynumber]=person;
        }
        // Overloading the output operator
        friend ostream& operator<<(ostream& os,const Secretary& secretary){
            map<int, Person*>::const_iterator it;
            for(it=secretary.department.begin();it!=secretary.department.end();it++){
                os<<*(it->second)<<endl;
            }
            return os;
        }
        // Overloading the input operator
        friend istream& operator>>(istream& is,Secretary& secretary){
            Person* person=new Person();
            is>>*person;
            secretary+=person;
            return is;
        }
        // Overloading the assignment operator
        Secretary& operator=(const Secretary& other){
            if (this!=&other){
                // Deleting the existing Persons
                map<int, Person*>::const_iterator it;
                for(it=department.begin();it!=department.end();it++) {
                    delete it->second;
                }
                for(it=other.department.begin();it!=other.department.end();it++){      // Cloning the Persons from the other Secretary
                    department[it->first]=new Person(*(it->second));
                }
                cout<<"secretary assigned"<<endl;
            }
            return *this;
        }
};




int main() {
    Person person1("John","Karas",2200178,25);
    Person person2("Alice","Asimath",2200225,30);
    cout<<"total persons:"<<Person::getcount()<<endl;

    // Creating instance of Secretary
    Secretary departmentsecretary;

    // Adding Persons to the department
    departmentsecretary+=new Person(person1);
    departmentsecretary+=new Person(person2);

    // Displaying the department
    cout<<"department secretary:"<<endl;
    cout<<departmentsecretary<<endl;

    // Adding a new Person from the user
    cin>>departmentsecretary;

    // Displaying the updated department
    cout<<"updated department secretary:"<<endl;
    cout<<departmentsecretary<<endl;

    // Checking if a specific Person exists in the department
    if(departmentsecretary.containsperson(person1)){
        cout<<"person is in the department"<<endl;
    }
    else{
        cout<<"person is not in the department"<<endl;
    }

    // Copy Constructor
    Secretary copysecretary(departmentsecretary);
    cout<<"copy department secretary:"<<endl;
    cout<<copysecretary<<endl;

    // Overloading the assignment operator
    Secretary assignedsecretary;
    assignedsecretary=departmentsecretary;
    cout<<"assigned department secretary:"<<endl;
    cout<<assignedsecretary<<endl;
    
    return 0;
}






 
//katalabe yperfortwseis,copy constructor,map
//kanto oso pio aplo ginetai 
//ftiakse sxolia,all


//sos otan h eksetash be ready for the other version!!!!!!!!!!!!!
//ok to exw katalabei kai teleiopoihsei se ena poly megalo bathmo
//epishs exw parei oti gnwsh mporei na moy dwsei gia to 2o part 
//otan einai eksetash tha to kseskonisw allh mia fora,opws kai to 2o


//pame twra na kanoyme kai to 2o teleio kai meta oso xrono exoyme ta katalabainoyme,teleiopoyme
