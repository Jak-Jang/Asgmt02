#include <iostream>
#include <cstdlib>	// 난수 생성
#include <ctime>	// 타임 함수로 실시간 시드 변경
using namespace std;

class Animal // 기본 클래스, 추상 클래스, 인스턴스 생성 X
{
public:
    virtual void makeSound() = 0; // 순수 가상 함수
    virtual ~Animal() {} // 가상 소멸자
};

class Zoo // 동물원 기능을 수행할 클래스
{
private:
    Animal* animals[10]; // 클래스 포인터 배열
    int count; // 동물원에 있는 동물 수
public:
    Zoo() : count(0) // 생성자, count 초기값 지정
    {
        for (int i = 0; i < 10; i++) // 배열의 초기값 지정
        {
            animals[i] = nullptr; // nullptr로 초기화
        }
        cout << "\n동물원 개장\n" << endl; // 생성자 확인용
    }

    void addAnimal(Animal* newAnimal) // 동물 추가 함수
    {
        if (count < 10)
        { 
            animals[count++] = newAnimal; // 마리 수 미달 시 count++
            cout << "동물 " << count << "/10 마리" << endl; // 현재 동물 수
        }
        else
        {
            cout << "동물이 너무 많아요" << endl;
            delete newAnimal; // 제한 수를 넘어가면 포인터 해제
        }
    }
    void performActions() // 동물 행동 함수
    {
        cout << "\n- 구경하기 -\n" << endl;
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

    ~Zoo() // 소멸자, 오류 방지용 nullptr 생성
    {
        cout << "\n동물원 마감" << endl;
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
    void makeSound() { cout << "뛰어다니는 개 : 왈왈!" << endl; }
};
class Cat : public Animal
{
    void makeSound() { cout << "식빵굽는 고양이 : 냐옹~" << endl; }
};
class Cow : public Animal
{
    void makeSound() { cout << "어슬러거리는 소 : 음머~" << endl; }
};

Animal* createRandomAnimal()
{
    int random = rand() % 3; // 3가지 경우의 수
    if (random == 0)
    {
        return new Dog();
    }
    else if (random == 1)
    {
        return new Cat();
    }
    else // 조건을 따로 주지 않고 변수 방지
    {
        return new Cow();
    }
}

int main()
{
    srand(time(NULL)); // 메인함수에 포함, 아니면 작동 안함(?)
    Zoo zoo; // Zoo 클래스 호출
    int num; // 채울 동물 수

    cout << "몇 마리의 동물을 채우시겠습니다? : ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        zoo.addAnimal(createRandomAnimal());
    }
    zoo.performActions();

    return main(); // 생성자, 소멸자 작동 확인용, 아닐 경우 return 0;
}