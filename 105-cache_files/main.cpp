//  Vinzia, Daniel Alberto
//  Rojas, Elias Ezequiel

#include "cache.h"

// se opto por tomar strings estaticas.
class Student
{
    int id;
    int value;
    char data[BUFFER_SIZE];

public:
    static const string class_name;
    Student():id(0),value(0),data(""){} // const default
    Student(int _key, int _value, string _data) : id(_key), value(_value){
        _data.copy(data,BUFFER_SIZE);
    }

    friend ostream& operator<<(ostream& os, Student stud);
    string getNombre(){return string(data);}
    ~Student(){};
};

const string Student:: class_name = "StudentClass";

ostream& operator<<(ostream& os, Student stud)
{
    cout <<"Student Object: "<< stud.id <<", "<< stud.value << ", "<< stud.getNombre() <<endl; 
    return os;
}

int main()
{
    CacheManager<Student> my_cache(3);

    my_cache . insert ( " 0 " , Student (0 ,22 , " student1 " ) ) ;
    my_cache . insert ( " 1 " , Student (1 ,23 , " student2 " ) ) ;
    my_cache . insert ( " 2 " , Student (2 ,25 , " student3 " ) ) ;
    my_cache . insert ( " 3 " , Student (3 ,29 , " student4 " ) ) ;

    my_cache.showCache();
    //cout << " ----------------------UPDATE-----------------------" << endl;

    my_cache . insert ( " 2 " , Student (22 ,222 , " EZE " ) ) ;
    my_cache . showCache () ;

    cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< " << endl ;
    try{
        Student return_obj = my_cache.get(" 0 "); // not in cache but in filesystem
        cout << return_obj << endl;
    }catch(const invalid_argument& e){
        cerr << e.what();
        // printea en cerr, posee el metodo .what() ya que deriva de std::exception
    }

    cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< " << endl;

    my_cache.insert(" 2 ", Student(2, 25, " EZE "));
    my_cache.showCache();
    my_cache.insert(" 9 ", Student(1, 5, " Nine "));
    my_cache.insert(" 9 ", Student(1, 5, " Nine "));
    my_cache.insert(" 9 ", Student(1, 5, " Nine "));
    my_cache.showCache();

    return 0;
}
