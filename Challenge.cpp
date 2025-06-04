#include <iostream>
#include <cstdlib>	// ���� ����
#include <ctime>	// Ÿ�� �Լ��� �ǽð� �õ� ����
using namespace std;

class Animal // �⺻ Ŭ����, �߻� Ŭ����, �ν��Ͻ� ���� X
{
public:
    virtual void makeSound() = 0; // ���� ���� �Լ�
    virtual ~Animal() {} // ���� �Ҹ���
};

class Zoo // ������ ����� ������ Ŭ����
{
private:
    Animal* animals[10]; // Ŭ���� ������ �迭
    int count; // �������� �ִ� ���� ��
public:
    Zoo() : count(0) // ������, count �ʱⰪ ����
    {
        for (int i = 0; i < 10; i++) // �迭�� �ʱⰪ ����
        {
            animals[i] = nullptr; // nullptr�� �ʱ�ȭ
        }
        cout << "\n������ ����\n" << endl; // ������ Ȯ�ο�
    }

    void addAnimal(Animal* newAnimal) // ���� �߰� �Լ�
    {
        if (count < 10)
        { 
            animals[count++] = newAnimal; // ���� �� �̴� �� count++
            cout << "���� " << count << "/10 ����" << endl; // ���� ���� ��
        }
        else
        {
            cout << "������ �ʹ� ���ƿ�" << endl;
            delete newAnimal; // ���� ���� �Ѿ�� ������ ����
        }
    }
    void performActions() // ���� �ൿ �Լ�
    {
        cout << "\n- �����ϱ� -\n" << endl;
        {
            for (int i = 0; i < count; i++)
            {
                if (animals[i] != nullptr)
                {
                    animals[i]->makeSound();
                }
            }
        }
    }

    ~Zoo() // �Ҹ���, ���� ������ nullptr ����
    {
        cout << "\n������ ����" << endl;
        for (int i = 0; i < count; i++)
        {
            if (animals[i] != nullptr)
            {
                delete animals[i];
                animals[i] = nullptr;
            }
        }
    }
};

class Dog : public Animal
{
    void makeSound() { cout << "�پ�ٴϴ� �� : �п�!" << endl; }
};
class Cat : public Animal
{
    void makeSound() { cout << "�Ļ����� ����� : �Ŀ�~" << endl; }
};
class Cow : public Animal
{
    void makeSound() { cout << "����Ÿ��� �� : ����~" << endl; }
};

Animal* createRandomAnimal()
{
    int random = rand() % 3; // 3���� ����� ��
    if (random == 0)
    {
        return new Dog();
    }
    else if (random == 1)
    {
        return new Cat();
    }
    else // ������ ���� ���� �ʰ� ���� ����
    {
        return new Cow();
    }
}

int main()
{
    srand(time(NULL)); // �����Լ��� ����, �ƴϸ� �۵� ����(?)
    Zoo zoo; // Zoo Ŭ���� ȣ��
    int num; // ä�� ���� ��

    cout << "�� ������ ������ ä��ðڽ��ϴ�? : ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        zoo.addAnimal(createRandomAnimal());
    }
    zoo.performActions();

    return main(); // ������, �Ҹ��� �۵� Ȯ�ο�, �ƴ� ��� return 0;
}