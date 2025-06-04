#include <iostream>
using namespace std;


class Animal // �⺻ Ŭ����, �߻� Ŭ����, �ν��Ͻ� ���� X
{
public:
	virtual void makeSound() = 0; // ���� ���� �Լ�
	virtual ~Animal() {} // ���� �Ҹ���
};

class Dog : public Animal // Animal�� �Ļ� Ŭ����
{
public:
	Dog(string sound) : Sounds(sound) {} // ������
	void makeSound() { cout << "Dog : " << Sounds << endl; }
	// ���� ���� �Լ� 
private: // ��� ���� ����
	string Sounds;
};

class Cat : public Animal // Animal�� �Ļ� Ŭ����
{
public:
	Cat(string sound) : Sounds(sound) {} // ������
	void makeSound() { cout << "Cat : " << Sounds << endl; }

private: // ��� ���� ����
	string Sounds;
};

class Cow : public Animal // Animal�� �Ļ� Ŭ����
{
public:
	Cow(string sound) : Sounds(sound) {} // ������
	void makeSound() { cout << "Cow : " << Sounds << endl; }

private: // ��� ���� ����
	string Sounds;
};

void print(Animal* animal)
{
	animal->makeSound(); // Animal Ŭ������ makeSound ȣ��
}

int main()
{
	Animal* animal[3];	// ������ �迭
	animal[0] = new Dog("krrr"); // ������ �迭 �� �Է�
	animal[1] = new Cat("hiss"); // ������ �迭 �� �Է�
	animal[2] = new Cow("mooo"); // ������ �迭 �� �Է�


	for (int i = 0; i < 3; i++) // �ε��� ������ sizeof ��� �� ���, ���� o
	{
		print(animal[i]);
	}

	// �ݺ��� Ż�� ������ sizeof�� ����� ��� ���� ó��
	for (int i = 0; i < 3; i++)
	{
		delete animal[i];	// ��ü �޸� ����
	}

	return 0;
}