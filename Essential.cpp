#include <iostream>
using namespace std;


class Animal // 기본 클래스, 추상 클래스, 인스턴스 생성 X
{
public:
	virtual void makeSound() = 0; // 순수 가상 함수
	virtual ~Animal() {} // 가상 소멸자
};

class Dog : public Animal // Animal의 파생 클래스
{
public:
	Dog(string sound) : Sounds(sound) {} // 생성자
	void makeSound() { cout << "Dog : " << Sounds << endl; }
	// 순수 가상 함수 
private: // 멤버 변수 선언
	string Sounds;
};

class Cat : public Animal // Animal의 파생 클래스
{
public:
	Cat(string sound) : Sounds(sound) {} // 생성자
	void makeSound() { cout << "Cat : " << Sounds << endl; }

private: // 멤버 변수 선언
	string Sounds;
};

class Cow : public Animal // Animal의 파생 클래스
{
public:
	Cow(string sound) : Sounds(sound) {} // 생성자
	void makeSound() { cout << "Cow : " << Sounds << endl; }

private: // 멤버 변수 선언
	string Sounds;
};

void print(Animal* animal)
{
	animal->makeSound(); // Animal 클래스의 makeSound 호출
}

int main()
{
	Animal* animal[3];	// 포인터 배열
	animal[0] = new Dog("krrr"); // 포인터 배열 값 입력
	animal[1] = new Cat("hiss"); // 포인터 배열 값 입력
	animal[2] = new Cow("mooo"); // 포인터 배열 값 입력


	for (int i = 0; i < 3; i++) // 인덱스 범위를 sizeof 사용 시 경고, 실행 o
	{
		print(animal[i]);
	}

	// 반복문 탈출 범위를 sizeof로 사용할 경우 예외 처리
	for (int i = 0; i < 3; i++)
	{
		delete animal[i];	// 객체 메모리 해제
	}

	return 0;
}