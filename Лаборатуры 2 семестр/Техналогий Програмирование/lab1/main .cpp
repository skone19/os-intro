/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Student{
    string name;
    int Id;
    string surname;
    Student* next;
    Student* prev;
public:
    Student(string surname_ = "", string name_ = "", int Id_ = 0)
    {
        name = name_;
        surname = surname_;
        Id = Id_;
        next = nullptr;
        prev = nullptr;
        cout<<" Student:  "<< surname << " " << name << " " << Id << " created\n";
    }
    void set_next(Student* next_) { next = next_; }
    void set_prev(Student* prev_) { prev = prev_; }
    
    Student* get_next() { return next; }
    Student* get_prev() { return prev; }
    
    Student(Student &other) { 
        this->name = other.name;
        this->surname = other.surname;
        this->Id = other.Id;
    }
    
    
    void set_name(string name_) {name = name_;}
    void set_surname(string surname_) {surname = surname_;}
    void set_Id(int Id_) {Id = Id_;}
    
    string get_name() { return name;}
    string get_surname() { return surname;}
    int get_Id() { return Id;}
    
    ~Student() {cout<<"Student: "<<surname<< " " <<  name << " " << Id << " deleted\n";}
    //elem operator= (elem &other) { cout<<"= called\n"; this->name = other.name; return other;}
};

class list
{
public:
    Student* head;
    Student* tail;
    int count; //количество элементов
    list() { head = nullptr; tail = nullptr; count = 0;}
    ~list()
    {
        Student* cur_Student = head;
        while(cur_Student != nullptr)
        {
            Student* del_Student = cur_Student;
            cur_Student = cur_Student->get_next();
            delete del_Student;
        }
    }

    void print() // вывод всех элементов списка прямом парядке 
    {
        Student* cur_Student = head;
        while(cur_Student != nullptr)
        {
            cout<<cur_Student->get_surname()<<" " <<cur_Student->get_name()<<" " <<cur_Student->get_Id()<<"\n";
            cur_Student = cur_Student->get_next();
            
        }
    }
    void inverted_print()
    {
        Student* cur_Student = tail;
        while(cur_Student != nullptr)
        {
            cout<<cur_Student->get_surname()<<" " <<cur_Student->get_name()<<" " <<cur_Student->get_Id()<<"\n";
            cur_Student = cur_Student->get_prev();
        }
    }

    void push_back(Student* last) //вставка в конец списка
    {
        cout<<"push_back is called\n";
        Student *add = new Student(last->get_surname(), last->get_name(), last->get_Id());
        if(head == nullptr)//в списке нет студентов
        {
            head = add;
            tail = add;
            count++;
            return;
        }
        Student* cur_Student = tail;
        cur_Student->set_next(add);//устанавливаем прямой указатель
        add->set_prev(tail);//установаливаем обратный указатель
        tail = add;//меняем значение указателя на последний элемент
        count++;
    }

    void push_front(Student* front) //вставка в начало списка
    {
        Student *add = new Student();
        add->set_surname(front->get_surname());
        add->set_name(front->get_name());
        add->set_Id(front->get_Id());
        
        if(head == nullptr)
        {
            head = add;
            tail = add;
            count++;
            return;
        }
        add->set_next(head);
        head->set_prev(add);
        head = add;
        count++;
    }
    
    void insert(int place, Student* new_Student)
    {
        if(head == nullptr)
            return;
        if(place >= count)
        {
            cout<<"Error! Not enough student in list!\n";
            return;
        }
        else if(place + 1 == count)
            push_back(new_Student);
        else
        {
            Student *add = new Student(new_Student->get_surname(), new_Student->get_name(), new_Student->get_Id());
            int k = 0;
            Student* cur_Student = head;
            while(k < place)
            {
                cur_Student = cur_Student->get_next();
                if(cur_Student == nullptr)
                    break;
                k++;
            }
            add->set_next(cur_Student->get_next());
            add->set_prev(cur_Student);
            cur_Student->get_next()->set_prev(add);
            cur_Student->set_next(add);
            count++;
        } //вставка в определенное место списка (после элемента с индексом n)
    }
    void insert(Student after, Student* new_Student)
    {
        if(head == nullptr)
            return;
        if(after.get_surname() == tail->get_surname() &&
            after.get_name() == tail->get_name() &&
            after.get_Id() == tail->get_Id()){
                push_back(new_Student);
            }
        else
        {
            Student* add = new Student(new_Student->get_surname(), new_Student->get_name(), new_Student->get_Id());
            Student* cur_Student = head;
            while(cur_Student != nullptr && 
                cur_Student->get_surname() != after.get_surname() && 
                cur_Student->get_name() != after.get_name() && 
                cur_Student->get_Id() != after.get_Id()){
                cur_Student = cur_Student->get_next();
            }
            if(cur_Student == nullptr)
            {
                cout<<"Student with required surname, name, Id  is not found\n";
                return;
            }
            add->set_next(cur_Student->get_next());
            add->set_prev(cur_Student);
            cur_Student->get_next()->set_prev(add);
            cur_Student->set_next(add);
            count++;
        }
    } //вставка после конкретного элемента
    void pop_front(){
        Student *cur_Student = head;
        head = head->get_next(); 
        cur_Student->get_next();
        delete cur_Student;
        cur_Student = nullptr;
        count--;
        if (!head)
        cout << "head is null" << endl;

    return;
    }   //удаление первого элемента
    void pop_back(){
        Student *cur_Student = tail; 
    if(!tail->get_prev())
            {
            head=NULL;
            tail=NULL;
            delete cur_Student;
            cur_Student=nullptr;
             count--;
            }
            
    else{
       tail=tail->get_prev();
       delete cur_Student;
       count--;
              
            }
            
         }
        // else{
            //tail->set_next(NULL);
            // free (cur_Student);
            // cur_Student=nullptr;
            // count--;
        // }
    // удаление последнего элемента
    void Delete(int place){
        if(head == nullptr)
            return;
        if(place >= count)
        {
            cout<<"Error! Not enough Student in list!\n";
            return;
        }
        
        else if(place == 0 && head->get_next() ){ 
            Student*Student1=head;
 head = head->get_next();
 head->set_prev(nullptr);
 delete Student1;
count--;
            
    }
    else if(place==0 && head == tail){
            head->set_next(nullptr);
            head = nullptr;
            delete head;
            count = 0;
        }
        else if(place == count-1)
            pop_back();
         else{
            Student *Student1 = head;
            int k=0;
            for(k=0;k<place;k++){
                Student1 = Student1->get_next();
            }
             Student *Student2 = Student1;
            Student2->get_prev()->set_next(Student1->get_next());
            Student2->get_next()->set_prev(Student1->get_prev());
            delete Student1;
            count--;
        }
            
           
            
        } // удаление элемента по индексу
        
         void Delete(Student *student){
        if(head == nullptr){
            return;
        }
        else if(student->get_surname() == head->get_surname() &&
                student->get_name() == head->get_name() &&
                student->get_Id() == head->get_Id() && head->get_next()){
            Student *Student1 = head;
            head = head->get_next();
            head->set_prev(NULL);
            delete Student1;
            count--;
        }
        else if(student->get_surname() == head->get_surname() &&
                student->get_name() == head->get_name() &&
                student->get_Id() == head->get_Id() && head == tail){
            cout << "Check";
            head->set_next(NULL);
            head = NULL;
            delete head;
            count = 0;
        }
        else if(student->get_surname() == tail->get_surname() &&
                student->get_name() == tail->get_name() &&
                student->get_Id() == tail->get_Id()){
            pop_front();
                }
        else{
            Student *Student1 = head;
            while(Student1 != nullptr && Student1->get_surname() != student->get_surname() &&
                Student1->get_name() != student->get_name() &&
                Student1->get_Id() != student->get_Id()){
                    Student1 = Student1->get_next();
                }
            if(Student1 == nullptr)
            {
                cout<<"Element with required surname, name and Id is not found\n";
                return;
            }
            Student *Student2 = Student1;
            Student2->get_prev()->set_next(Student1->get_next());
            Student2->get_next()->set_prev(Student1->get_prev());
            delete Student1;
            count--;
        }
    } // удаление конкретного элемента
    void move(int place1, int place2){
        if(head == nullptr || head==tail)
            return;
        if(place1 >= count || place2 >= count)
        {
            cout<<"Error! Not enough users in list!\n";
            return;
        }
        else if(place1<place2){
            Student *Student1 = head;
            int k=0;
            for(k=0;k<place1;k++){
                Student1 = Student1->get_next();
            }
            insert(place2, Student1);
            Delete(place1);
        }
        else{
            Student *Student1 = head;
            int k=0;
            for(k=0;k<place1;k++){
                Student1 = Student1->get_next();
            }
            insert(place2, Student1);
            Delete(place1+1);
        }//перемещение элемента (элемент с индексом n переставляется на место после элемента с индексом k)
    }
    void swap(int place1, int place2){
        if(head == nullptr || head==tail)
            return;
        if(place1 >= count || place2 >= count)
        {
            cout<<"Error! Not enough student in list!\n";
            return;
        }
        else if(place1<place2){
            Student *Student1 = head;
            Student *Student2 = head;
            int k=0;
            for(k=0;k<place1;k++){
                Student1 = Student1->get_next();
            }
            for(k=0;k<place2;k++){
                Student2 = Student2->get_next();
            }                     
            insert(place2, Student1); 
            insert(place1, Student2); 
            Delete(place1); 
            Delete(place2); 
        }
        else{
            cout << "Error! Enter the indices in ascending order!\n";
            return;
        }
    } //перестановка элементов (элементы с индексами n и k меняются местами)
    
    void find(int place){
        int k=0;
        Student *find_Student= head;
        if(head == nullptr)
            return;
        if(place >= count)
        {
            cout<<"Error! Not enough Student in list!\n";
            return;
        }
        else{
            for(k;k<place;k++){
                find_Student = find_Student->get_next();
            }
            cout << "Student with index " << place << " : \n";
            cout << find_Student->get_surname() << " " << find_Student->get_name() << " " << find_Student->get_Id() << endl;
        }
        
    } // поиск конкретного элемента списка
};
        

int main()
{
    list my_list;
    int Student_num;
    //cin>>Student_num;
    Student new_Student;
    bool Exit = true;
    while(Exit){
        string surname, after_surname, name, after_name;
        int Id, after_Id;
        int index;
        int operation=0;
        
        cout<<"Insert surname of student: "<<endl;
        cin>>surname;
        cout<<"Insert name of Student: "<<endl;
        cin>>name;
        cout<<"Insert Id of student: "<<endl;
        cin>>Id;
        
        new_Student.set_surname(surname); 
        new_Student.set_name(name);
        new_Student.set_Id(Id);
        
        cout<<"Choose operation: \n \ 
                1 - Вставить студент в начало списка\n \
                2 - Вставить студент в конец списка\n \
                3 - Вставить студент в определенном место списка \n \
                4 - Вставить студент  после другой студент\n \
                5 - Удалить  первый студент в списке\n \
                6 - Удалить последние студент в списке\n \
                7 - Удалить студент с индексом в списке\n \
                8 - Удалить студент с название :surname, name and Id\n \ 
                9 - Перемещать студенты с индексом \n \
                10 -Поменять местами студенты с индексами\n \
                11 -Поискать студент в списке\n \
                12 -Найти количества студенты в списке\n \
                13 -вывод всех элементо списка\n \
                14 -вывод всех элементо списка обратном\n \
                15 -Добавить следующие Студент\n \
                16 -Выход из программы\n" ;
        bool go = true;
        while(go){
        cin>>operation;
        
        switch(operation){
            case 1:{
                my_list.push_front(&new_Student);
                break;
            }
            case 2:{
                my_list.push_back(&new_Student);
                break;
            }
            case 3:{
                cout<<"Insert index:\n";
                cin>>index;
                my_list.insert(index, &new_Student);
                break;
            }
            case 4:{
                cout<<"Insert surname, name, Id:\n";
                cin>>after_surname >> after_name >> after_Id;
                Student after_Student(after_surname, after_name, after_Id);
                my_list.insert(after_Student, &new_Student);
                break;
            }
            case 5:{
                my_list.pop_front();
                break;
            }
            case 6:{
                my_list.pop_back();
                break;
            }
            case 7:{
                cout<<"Insert index:\n";
                cin>>index;
                my_list.Delete( index);
                break;
            }
            case 8:{
                cout << " Insert surname, name and Id ";
                cin>>after_surname >> after_name >> after_Id;
                 Student after_Student (after_surname, after_name, after_Id);
                my_list.Delete(&after_Student);
                break;
            }
            case 9:{
                int index1, index2;
                cout << "Insert index of student to move:\n";
                cin >> index1;
                cout << "Insert index of place to move:\n";
                cin >> index2;
                my_list.move(index1, index2);
                break;
            }
            case 10:{
                int index1, index2;
                cout << "Enter the indices in ascending order!\n\n";
                cout << "Insert index of student to move:\n";
                cin >> index1;
                cout << "Insert index of place to move:\n";
                cin >> index2;
                my_list.swap(index1, index2);
                break;
            }
            
            
            case 11:{
                int ind;
                cout << "Enter the index of the user you want to find\n";
                cin >> ind;
                my_list.find(ind);
                break;
            }
            
            
             case 12:{
                cout<<"Now we have "<<my_list.count<<" student\n";
                break;
            }
            case 13:{
                my_list.print();
                break;
            }
            case 14:{
                my_list.inverted_print();
                break;
            }
            case 15:{
                go=false;
                break;
            }
            case 16:{
                go= false;
                Exit = false;
                cout << "Program completed successfully\n";
                break;
            }
            default:{
                cout<<"Error! wrong operation! Insert from 1 to 14\n";
                break;
            }
        }
    
      
    
    
    }
  }
  return 0;
}












