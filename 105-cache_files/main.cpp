#include "cache.h"

class Student
{
    int id;
    int value;
    string data;

public:
    static const string class_name; 
    Student():id(0),value(0),data(""){} // const default
    Student(int _key, int _value, string _data) : id(_key), value(_value), data(_data) {}

    friend ostream& operator<<(ostream& os, const Student& stud);
    string getNombre(){return data;}
    ~Student(){};
};

const string Student:: class_name = "StudentClass";

// se debe sobrecargar el operador de flujo!
ostream& operator<<(ostream& os, const Student& stud)
{
   cout <<"Student Object: "<< stud.id <<", "<< stud.value << ", "<< stud.data <<endl; 
   return os;
}

int main()
{
    CacheManager<Student> my_cache(3);
    Student piv;
    my_cache.insert(" 0 ", Student (0,22,"student0"));
    my_cache.insert(" 1 ", Student (1,23,"student1"));
    my_cache.insert(" 2 ", Student (2,25,"student2"));
    my_cache.insert(" 3 ", Student (3,29,"student3"));
    my_cache.insert(" 4 ", Student (123,29,"student4"));
    my_cache.insert(" 5 ", Student (123,29,"student5"));

    piv = my_cache.get(" 1 ");
    cout << piv << endl;


    //cout << "PRIMER ESTUDIANTE REMOVIDO" << endl;
    //cout << my_cache.get(" 1 ") << endl;
    //my_cache.showCache();

    //cout << " ----------------------UPDATE-----------------------" << endl;

    //my_cache.insert(" 2 ", Student(22, 222, " EZE "));
    //my_cache.showCache();

    //cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< " << endl ;

    //
    //cout << "ESTUDIANTE CON ID 0 (0,22,student1)" << endl ;
    //Student return_obj = my_cache.get(" 2 "); // not in cache but in filesystem
    //cout << return_obj << endl;

    //cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< " << endl;

    //my_cache.insert(" 2 ", Student(2, 25, " EZE "));
    //my_cache.showCache();
    //my_cache.insert(" 9 ", Student(1, 5, " Nine "));
    //my_cache.insert(" 9 ", Student(1, 5, " Nine "));
    //my_cache.insert(" 9 ", Student(1, 5, " Nine "));
    //my_cache.showCache();

    return 0;
}
