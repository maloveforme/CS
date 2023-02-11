#include <iostream>
using namespace std;

template<class T>
class vector
{
	T* _data = nullptr; // 데이터의 주소값
	int _size = 0; // 크기
	int _capacity = 0; // 용량

public:
	vector() { } // 기본 생성자

	~vector() // 소멸자
	{
		if (_data) // 소멸자가 실행될 때 벡터 내에 데이터가 존재하면
			delete[] _data; // 할당 해제
	}

	void reserve(const int& capacity) // capacity만큼 용량을 늘려주는 것
	{
		if (_capacity > capacity) // 기존의 용량이 입력받은 용량보다 크다면
			return; // 따로 처리해줄 게 없음
		_capacity = move(capacity);

		T* newData = new T[_capacity]; // 넓힌 크기의 배열 초기화

		for (int i = 0; i < _size; ++i)
			newData[i] = move(_data[i]); // 새로운 공간에 데이터를 밀어 넣음

		if (_data) // 데이터가 남아 있다면
			delete[] _data; // 할당 해제

		_data = newData; // 주솟값만 가리키게 
	}

	void push_back(const T& value) // 맨 뒤의 위치에 값 대입
	{
		if (_size == _capacity) // 용량과 크기가 같을 때
		{
			int newCapacity = static_cast<int>(_capacity * 1.5); // 1.5배 늘린 용량

			if (newCapacity == _capacity) // 예외: 용량이 0과 1일 때
				newCapacity++;

			reserve(newCapacity); // 공간 넓히기
		}

		_data[_size++] = value; // 맨 뒷자리에 데이터를 넣고, 크기 증가
	}

	void pop_back()
	{
		_size > 0 ? _data[_size--] = NULL : 0;
	}

	int size() // 크기 반환
	{
		return _size;
	}

	int capacity() // 용량 반환
	{
		return _capacity;
	}

	T& operator [] (const int& pos) // 임의 접근 v[i]
	{
		return _data[pos];
	}

	void clear() // 모두 지우기
	{
		if (_data) // 데이터가 존재한다면
		{
			delete[]_data; // 할당을 해제하고
			_data = new T[_capacity]; // 다시 새로 할당
		}

		_size = 0; // 크기 초기화
	}

};

int main()
{
	vector<int> v;

	v.reserve(150);
	cout << v.size() << ' ' << v.capacity() << endl;

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v[i] << ' ' << v.size() << ' ' << v.capacity() << endl;
	}

	for (int i = 100; i > 0; --i)
	{
		v.pop_back();
		cout << v[i] << ' ' << v.size() << ' ' << v.capacity() << endl;
	}
}