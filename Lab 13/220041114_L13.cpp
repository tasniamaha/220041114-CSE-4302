#include<iostream>
#include<map>
#include<set>

#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class Person{
    protected:
    string name;
    int ID;
    public:
    Person(string n,int id):name(n),ID(id){}
    string getname()const{
        return name;
    }
    int getid(){
        return ID;
    }
    virtual void display()const{
        cout<<"Name:"<<name<<", ID:"<<ID<<endl;
    }
    virtual string file_format()const{
        return name+','+to_string(ID)+"\n";
    }
    virtual ~Person(){}
};
class student:public Person{
    private:
    set<string>courseEnrolled;
    public:
    student():Person("",0){}
    student(string n,int id):Person(n,id){}
    void enrollCourse(string courseCode) {
        courseEnrolled.insert(courseCode);
    }
    void display() const override {
        cout << "Name: " << name << ", ID: " << ID << "\nCourses Enrolled: ";
        for (const auto& course : courseEnrolled)
            cout << course << " ";
        cout << endl;
    }
    string file_format() const override {
        string data = Person::file_format();
        for (const auto& course : courseEnrolled) data += course + " ";
        return data + "\n"; // Ensure a newline at the end
    }
    
    void load_courses(string course_list) {
        stringstream ss(course_list);
        string course;
        while (ss >> course) {
            courseEnrolled.insert(course);
        }
    }
};
class instructor:public Person{
    private:
    set<string>courseTeaching;
    public:
    instructor():Person("",0){}
    instructor(string n,int id):Person(n,id){}
    void assigncourse(string coursecode){
        courseTeaching.insert(coursecode);
    }
    void display() const override {
        cout << "Name: " << name << ", ID: " << ID << "\nCourses Teaching: ";
        for (const auto& course : courseTeaching)
            cout << course << " ";
        cout << endl;
    }
    string file_format() const override {
        string data = Person::file_format();
        for (const auto& course : courseTeaching) data += course + " ";
        return data + "\n"; // Ensure a newline at the end
    }
    
    void load_courses(string course_list) {
        stringstream ss(course_list);
        string course;
        while (ss >> course) {
            courseTeaching.insert(course);
        }
    }
};
map<string, string> courses;
map<int, student> students;
map<int, instructor> instructors;
void addcourse(){
    string coursecode,coursename;
    cout<<"Enter your course code:";
    cin>>coursecode;
    cout<<"Enter course name:";
    cin.ignore();
    getline(cin,coursename);
    courses[coursecode]=coursename;
    cout<<"Course added successfully!\n";
}
void enrollStudent() {
    int studentId;
    string courseCode, studentName;
    cout << "Enter student ID:";
    cin >> studentId;
    cout << "Enter course code:";
    cin >> courseCode;
    cout << "Enter student name:";
    cin.ignore();
    getline(cin, studentName);
    if (students.find(studentId) == students.end()) {
        students[studentId] = student(studentName, studentId);
    }
    students[studentId].enrollCourse(courseCode);
    cout << "Student enrolled successfully!\n" << endl;
}
void assignInstructor(){
    int instructorId;
    string coursecode,instructorName;
    cout<<"Enter instructor ID:";
    cin>>instructorId;
    cout<<"Enter course code:";
    cin>>coursecode;
    cout<<"Enter instructor name:";
    cin.ignore();
    getline(cin,instructorName);
    if (instructors.find(instructorId) == instructors.end()) {
        instructors[instructorId] = instructor(instructorName, instructorId);
    }
    instructors[instructorId]=instructor(instructorName,instructorId);
    cout<<"Instructor assigned successfully!\n"<<endl;

}
void displaydata(){
    cout<<"Course\n";
    for(const auto [code,name]:courses ){
        cout<<"Code:"<<code<<",Name:"<<name<<endl;
    }
    cout<<"Students:\n";
    for(const auto [id,stud]:students ){
        stud.display();
    }
    for(const auto [id,inst]:instructors){
        inst.display();
    }
}
void save_data(){
    ofstream coursefile("course.txt"),studentfile("student.txt"),instructorfile("instructors.txt");
    for(const auto [code,name]:courses){
        coursefile<<code<<","<<name<<"\n";
    }
    coursefile.close();
    for(const auto[code,st]:students){
        studentfile<<st.file_format();
    }
    studentfile.close();
    for(const auto[code,inst]:instructors){
        instructorfile<<inst.file_format();
    }
    instructorfile.close();
    cout<<"Data saved to files!\n";
}
void load_data(){
    ifstream coursefile("course.txt"),studentfile("student.txt"),instructorfile("instructors.txt");
    courses.clear();
    students.clear();
    instructors.clear();
    string line,coursecode,name,id,course;
    while(getline(coursefile,line)){
        stringstream ss(line);
        getline(ss,coursecode,',');
        getline(ss,name,',');
        courses[coursecode]=name;
    }
    coursefile.close();
    while (getline(studentfile, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, id, ',');
        getline(ss, course);
        student s(name, stoi(id));
        s.load_courses(course);
        students[stoi(id)] = s;
    }
    studentfile.close();
    while(getline(instructorfile,line)){
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, id, ',');
        getline(ss, course);
        instructor ins(name, stoi(id));
        ins.load_courses(course);
        instructors[stoi(id)]=ins;
    }
    instructorfile.close();
    cout<<"Data loaded successfully!\n";
}
int main(){
    while(1){
        cout<<"1. Add Course\n";
        cout<<"2. Enroll Student\n";
        cout<<"3. Assign Instructor\n";
        cout<<"4. Display Data\n";
        cout<<"5. Save Data\n";
        cout<<"6. Load Data\n";
        cout<<"7 .Exit\n";
        int choice;
        cout<<"Enter your choice:";
        cin>>choice;
        cin.ignore();
        if(choice==1){
            addcourse();
        }
        else if(choice==2){
            enrollStudent();
        }
        else if(choice==3){
            assignInstructor();
        }
        else if(choice==4){
            displaydata();
        }
        else if(choice==5){
            save_data();
        }
        else if(choice==6){
            load_data();
        }
        else {
            break;
        }
    }

}