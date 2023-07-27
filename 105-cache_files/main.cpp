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

    string getNombre(){return data;}
    void print(){
        cout << " Student Object: " << id << ", " << value << ", " << data << endl ;
    };
    ~Student(){};
};

const string Student:: class_name = "StudentClass";

int main()
{
    CacheManager<Student> my_cache(3);
    Student p;
    my_cache.insert(" 10 ", Student(11, 23, " ricardo "));
    my_cache.insert(" 20 ", Student(22, 25, " mateo "));
    my_cache.insert(" 30 ", Student(33, 29, " ciro "));
    my_cache.insert(" 40 ", Student(44, 29, " antonella "));
    my_cache.insert(" 20 ", Student(55, 66, " jorge "));

    //my_cache.getFromMem(" 50 ");

    //cout << " - - - - - - - - - - - - - - - - - - - - - -  UPDATE - - - - - - - - - - - - - - - - - - - - - - -" << endl ;

    //my_cache.insert(" 2 ", Student(22, 222, " EZE "));
    ////my_cache.show_cache();

    //cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< " << endl ;

    //Student return_obj = my_cache.get(" 0 "); // not in cache but in filesystem

    //cout << " <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< " << endl;

    //my_cache.insert(" 2 ", Student(2, 25, " EZE "));
    ////my_cache.show_cache();
    //my_cache.insert(" 9 ", Student(1, 5, " Nine "));
    //my_cache.insert(" 9 ", Student(1, 5, " Nine "));
    //my_cache.insert(" 9 ", Student(1, 5, " Nine "));
    //my_cache.show_cache();

    return 0;
}
