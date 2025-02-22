#include <iostream> 
#include <string> 

using namespace std;

class Person
{
public:
    string name;
    int age;
    double weight;
    string occupation;

public:
    Person()
    {
        name = "NONE";
        age = 0;
        weight = 0.0;
        occupation = "NONE";
    }

    Person(string name, int age, double weight, string occupation)
    {
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->weight = weight;
    }

    string getName() const { return name; }
    int getAge() const { return age; }
    double getWeight() const { return weight; }
    string getOccupation() const { return occupation; }

    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setWeight(double weight) { this->weight = weight; }
    void setOccupation(string occupation) { this->occupation = occupation; }

    void printInfo() const
    {
        cout << "���: " << name << endl;
        cout << "�������: " << age << endl;
        cout << "���: " << weight << endl;
        cout << "��� �������: " << occupation << endl;
    }
};

void sortByAge(Person people[], int& count)
{
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (people[j].age > people[j + 1].age) {
                swap(people[j], people[j + 1]);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");

    const int MAX_PEOPLE = 100;
    Person people[MAX_PEOPLE];
    int count = 0;
    int choice;

    while (true)
    {
        cout << "1. �������� ��������\n"
            << "2. ������������� ��������\n"
            << "3. �������� ���� �����\n"
            << "4. ����������� �� ��������\n"
            << "5. �����\n��� �����: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�������� ����. ����������, ������� ����� �� 1 �� 5." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            if (count >= MAX_PEOPLE) {
                cout << "���������� ������������ ���������� �����." << endl;
                break;
            }
            string name, occupation;
            int age;
            double weight;

            cout << "������� ���: ";
            cin >> name;
            cout << "������� �������: ";
            cin >> age;
            cout << "������� ���: ";
            cin >> weight;
            cout << "������� ��� �������: ";
            cin >> occupation;


            people[count++] = Person(name, age, weight, occupation);
            break;
        }
        case 2:
        {
            if (count == 0) {
                cout << "��� ����� ��� ��������������." << endl;
                break;
            }
            int index;
            cout << "������� ������ �������� ��� �������������� (0-" << count - 1 << "): ";
            cin >> index;

            if (index < 0 || index >= count) {
                cout << "�������� ������." << endl;
                break;
            }

            int fieldChoice;
            cout << "��� ������ ��������?\n"
                << "1. �������\n"
                << "2. ���\n"
                << "3. ��� �������\n"
                << "��� �����: ";
            cin >> fieldChoice;

            switch (fieldChoice)
            {
            case 1: {
                int newAge;
                cout << "������� ����� �������: ";
                cin >> newAge;
                people[index].setAge(newAge);
                break;
            }
            case 2: {
                double newWeight;
                cout << "������� ����� ���: ";
                cin >> newWeight;
                people[index].setWeight(newWeight);
                break;
            }
            case 3: {
                string newOccupation;
                cout << "������� ����� ��� �������: ";
                people[index].setOccupation(newOccupation);
                break;
            }
            default:
                cout << "�������� �����." << endl;
                break;
            }
            break;
        }
        case 3: {
            if (count == 0) {
                cout << "��� ����� ��� �����������." << endl;
                break;
            }
            for (int i = 0; i < count; ++i) {
                cout << "������� #" << i + 1 << ":" << endl;
                people[i].printInfo();
                cout << endl;
            }
            break;
        }
        case 4: {
            sortByAge(people, count);
            cout << "���� ������������� �� ��������." << endl;
            break;
        }
        case 5:
            cout << "����� �� ���������." << endl;

        default:
            cout << "�������� �����. ����������, ���������� �����." << endl;
        }
    }

}