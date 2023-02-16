#include <iostream>
#include <algorithm>
using namespace std;

struct singly_ll_node
{
	int _data;
	singly_ll_node* _next;
};

class singly_ll // 연결리스트 
{
public:
	using node = singly_ll_node;
	using node_ptr = node*;
	
private:
	node_ptr _head;

public:
	void push_front(int value)
	{
		auto new_node = new node{ value, NULL };
		// singly_ll_node new_node 동적 할당
		// 이때 _data = value, _next = nullptr

		if (_head != NULL)
			new_node->_next = _head; 
		// _head가 존재하지 않는다면, 새로운 노드의 다음 주솟값을 _head로 지정
		// 즉, 최초의 경우 예외처리

		_head = new_node; // _head에 new_node 삽입
	}

	void pop_front()
	{
		auto first = _head;

		if (_head) // _head가 존재하는 경우
		{
			_head = _head->_next; // _head의 다음 주솟값을 땡겨온 후
			delete first; // first 할당 해제
		}
	}

	struct singly_ll_iterator // 반복자 설정
	{
	private:
		node_ptr ptr;

	public:
		singly_ll_iterator(node_ptr p) : ptr(p)
		{

		}

		int& operator * ()
		{
			return ptr->_data;
		}

		node_ptr get()
		{
			return ptr;
		}

		singly_ll_iterator& operator ++ () // 선행 증가
		{
			ptr = ptr->_next;

			return *this;
		}

		singly_ll_iterator operator ++ (int) // 후행 증가
		{
			singly_ll_iterator result = *this;
			++(*this);

			return result;
		}

		friend bool operator == (const singly_ll_iterator& left,
			const singly_ll_iterator& right) // == 연산자 재정의
		{
			return left.ptr == right.ptr;
		}

		friend bool operator != (const singly_ll_iterator& left,
			const singly_ll_iterator& right) // != 연산자 재정의
		{
			return left.ptr != right.ptr;
		}
	};

	singly_ll_iterator begin()
	{
		return singly_ll_iterator(_head);
	}

	singly_ll_iterator begin() const
	{
		return singly_ll_iterator(_head);
	}

	singly_ll_iterator end()
	{
		return singly_ll_iterator(NULL);
	}

	singly_ll_iterator end() const
	{
		return singly_ll_iterator(NULL);
	}

	singly_ll() = default; // 기본 생성자

	singly_ll(const singly_ll& other) : _head(NULL) // 복사 생성자
	{
		_head = new node{ 0, NULL };
		auto cur = _head; // 임시 주솟값
		auto it = other.begin(); // 시작 주솟값

		while (true)
		{
			cur->_data = *it; // 임시 주솟값의 값을 시작 주솟값의 값으로 받음
			
			auto tmp = it; // tmp = it
			++tmp; // tmp의 다음 주소

			if (tmp == other.end()) // 끝에 도달했을 때
				break;

			cur->_next = new node{ 0,NULL };
			cur = cur->_next;
			it = tmp;
		}
	}

	singly_ll(const std::initializer_list<int>& ilist) : _head(NULL) // 초기화 리스트
	{
		for (auto it = std::rbegin(ilist); it != std::rend(ilist); ++it)
			push_front(*it);
	}
};

int main()
{
	singly_ll sll = { 1,2,3 };
	sll.push_front(0);

	cout << "첫 번째 리스트: ";
	for (auto& i : sll)
		cout << i << ' ';
	cout << '\n';

	auto sll2 = sll;
	sll2.push_front(-1);

	cout << "첫 번째 리스트를 복사 후 맨 앞에 -1 추가: ";
	for (auto& i : sll2)
		cout << i << ' ';
	cout << '\n';

	cout << "깊은 복사 후 첫 번째 리스트: ";
	for (auto& i : sll)
		cout << i << ' ';
	cout << '\n';
}