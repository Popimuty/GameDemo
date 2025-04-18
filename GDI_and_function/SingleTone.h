#pragma once

template <typename T> 
class SingleTon
{

private:
	static T* m_Instance;

public:
	//assert(참조건) : 그냥 지나감         assert(거짓조건) : 
	// 프로그램 터짐 , 주로 프로그램이 원치않는 방향으로 흘러가지 않게 중간에 멈추는 기능
	SingleTon() {
		assert(m_Instance == nullptr && "싱글톤 인스턴스가 이미 생성됨!");
		m_Instance = static_cast<T*>(this);
	}

	virtual ~SingleTon() = default;

	//함수이름() = delete;  => 해당 함수는 절대 호출될 수 없게 만듬
	SingleTon(const SingleTon&) = delete;					// 복사 생성자 금지
	SingleTon& operator=(const SingleTon&) = delete;        // 복사 대입 금지
	SingleTon(SingleTon&&) = delete;						// 이동 생성자 금지
	SingleTon& operator=(SingleTon&&) = delete;				// 이동 대입 금지

	static T& Get()
	{
		assert(m_Instance != nullptr && "싱글톤 인스턴스가 생성 안됨!");
		return *m_Instance;
	}
};

// 초기화
template <typename T>
T* SingleTon<T>::m_Instance = nullptr;

