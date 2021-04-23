#include <iostream>
#include <memory>

class Student{
    public:
        std:: string name;
        int age;
        std:: string favorite_subject;
        int mark;
};

class School_class{
    private:
        int number_of_students;
        std:: string Teacher;
        std::unique_ptr<Student[]> massive_students {new Student[15]};
    public:
        School_class(int number_of_students);
        void change_teacher(std::string new_teacher){
            this->Teacher = new_teacher;
        }
        void show_class();
        void add_student(const Student& student);
        void delete_student(int number_of_expelled);
};

School_class::School_class(int number_of_students){
    if(number_of_students > 15){
        this->number_of_students = 15;
        std:: cout << "Sorry, covid. We'll take only 15 students." << std::endl;
        for(int i=0; i < 15; i++){
            std::cin >> this->massive_students[i].name;
            std::cin >> this->massive_students[i].age;
            std::cin >> this->massive_students[i].favorite_subject;
            std::cin >> this->massive_students[i].mark;
        }
    }
    else{
        this->number_of_students = number_of_students;
        for(int i=0; i < number_of_students; i++){
            std::cin >> this->massive_students[i].name;
            std::cin >> this->massive_students[i].age;
            std::cin >> this->massive_students[i].favorite_subject;
            std::cin >> this->massive_students[i].mark;
        }
    }
}

void School_class::show_class(){
    for(int i=0; i < this->number_of_students; i++){
        std::cout << this->massive_students[i].name << " ";
        std::cout << this->massive_students[i].age << " ";
        std::cout << this->massive_students[i].favorite_subject << " ";
        std::cout << this->massive_students[i].mark << std::endl;
    }
}

void School_class::add_student(const Student& student){
    if(this->number_of_students > 15){
        std:: cout << "Sorry, We already have 15 students." << std::endl;
    }
    else{
        this->number_of_students +=1;
        this->massive_students[this->number_of_students - 1] = student;
    }   
}

void School_class::delete_student(int number_of_expelled){
    if(number_of_expelled > 15){
        std:: cout << "Sorry, We  have only 15 students." << std::endl;
    }
    else{
        massive_students[number_of_expelled-1] = massive_students[this->number_of_students-1];
        this->number_of_students -=1;
    }
}

int main(){
    School_class A(3);
    std::cout << std::endl;
    A.show_class();
    std::cout << std::endl;   
    Student Stepa;
    Stepa.name = "Stepa";
    Stepa.age = 15;
    Stepa.favorite_subject = "Math";
    Stepa.mark = 4;
    A.add_student(Stepa);
    A.show_class();
    std::cout << std::endl;
    A.delete_student(2);
    A.show_class();
    return 0;
}