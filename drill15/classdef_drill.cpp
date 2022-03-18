#include "../std_lib_facilities.h"

struct Person
{
    public:
    Person() : first_name{"Guest"}, last_name{"Human"}, age{-1} {};

    Person(string f_name, string s_name, int age) : first_name{f_name}, last_name{s_name}, age{age} {

    if(first_name.empty() || last_name.empty()){
    error("Type in a first name and a surname!\n");
    }

    if(age == -1)
    {
        error("You have not typed in an age!\n");
    }

    const string illegal_chars = ";:\"'[]*&^%$#@!";

    string names = first_name + last_name;

    for (int i = 0; i < names.size(); ++i)
    {

        if(string(illegal_chars).find(f_name[i]) != string::npos)
        {
            error("The name may not contain these characters: " + illegal_chars + "\n");
        }
    }

    if (age <= 0 || age >= 150)
    {
        error("The age must be between 0 and 150!");
    }
};

int get_age() const
{
    return age;
}

string get_name() const
{
    return first_name + " " + last_name;
}

private:
string first_name;
string last_name;
int age;
};

ostream& operator<<( ostream& os, Person& person)
{
    return os << "Name: " << person.get_name() << '\n' << "Age: " << person.get_age() << '\n';
}

istream& operator>>(istream& in, Person& p)
{
string first_name, last_name;
int age;

in >> first_name >> last_name >> age;

if(!in)
{
    return in;
}

p = Person(first_name, last_name, age);
return in;
}

Person& operator>>(string& s, Person& p)
{
    istringstream stream_string(s);

    string input;

    string first_name, last_name;
    int age = -1;

    int arg_counter = 0;

    while(getline(stream_string, input, ' '))
    {
        switch(arg_counter)
        {
        case 0:
        first_name = input;
        break;

        case 1:
        last_name = input;
        break;

        case 2:
        age = stoi(input);
        break;

        default:
        break;
        }
    arg_counter++;
    }

return p = Person(first_name, last_name, age);
}


int main()
{
    try
    {

        cout << "2nd task:\n";

         Person person_one = Person{"Goofy", "Human", 63};

        cout << person_one;
        cout << '\n';

        cout << "3rd task:\n";

        Person person_two;

        cout << "Type in a first name and a surname, and an age, seperated by commas!\n";

        cin >> person_two;

        cout << '\n';
        cout << "You have given the following:\n";
        cout << person_two;
        cout << '\n';

        cout << "8th task:\n";

        vector<Person> persons;

        Person placeholder = Person();
        string input;

        cout << "Storing names...\n";
        cout << "Type in a first name and a surname, and an age, seperated by commas!\n";
        cout << "Type 'exit' to end the storing!\n";

        while(getline(cin, input))
        {
            if(input == "exit")
            {
                break;
            }

            if(input.empty())
            {
                continue;
            }

            try
            {
                input >> placeholder;
            }
            catch (runtime_error& e)
            {
                cerr << "Error: " << e.what() << '\n';
                continue;
            }
            catch(...)
            {
                cout << "Type in the data in the following format: first name, surname, age! (Seperated by spaces)\n";
                continue;
            }

            persons.push_back(placeholder);

            cout << '\n';
            cout << "You can type in a new name! (or quit with 'exit'!)\n";
        }

        cout << '\n';

        cout << "You have given the following:\n";

        for (int i = 0; i < persons.size(); ++i)
        {
            cout << "[" + to_string(i+1) + "] " << persons[i] << '\n';
        }

        return 0;

    }
    catch (runtime_error& e)
    {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        cerr << "Something went wrong :(.\n";
        return 2;
    }
}
