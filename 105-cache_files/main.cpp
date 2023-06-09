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
    //Student *p;
    my_cache.insert(" 10 ", Student(1, 23, " ricardo10 "));
    my_cache.insert(" 20 ", Student(2, 25, " student20 "));
    my_cache.insert(" 30 ", Student(3, 29, " student30 "));
    my_cache.insert(" 40 ", Student(3, 29, " student40 "));
    my_cache.insert(" 50 ", Student(3, 29, " student50 "));
    my_cache.write_file(" 50 ", Student(3, 29, " student50 "));
    my_cache.write_file(" 53 ", Student(3, 29, " student53 "));
    my_cache.write_file(" 54 ", Student(3, 29, " student54 "));
    my_cache.write_file(" 55 ", Student(3, 29, " student55 "));

    ifstream arch("cache.dat",ios::in);
    pair<string,Student> *tuvi = nullptr;
    arch.read(reinterpret_cast<char *>(tuvi), sizeof(pair<string,Student>));
    tuvi->second.print();
    //buenas.print();
    my_cache.showCache();
    arch.close();

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
