#pragma once

template <typename T> 
class SingleTon
{
public:
	// 명시적 초기화
	static void Create() {
		assert(s_instance == nullptr && "Singleton already created!");
		if (!s_instance)
			s_instance = new T();
	}

	// 명시적 해제
	static void Destroy() {
		assert(s_instance != nullptr && "Singleton not created or already destroyed!");
		delete s_instance;
		s_instance = nullptr;
	}

	// 싱글톤 인스턴스 참조 반환 (간접 호출 없이 .으로 접근)
	static T& Get() {
		if (s_instance == nullptr) {
			Create();
		}
		return *s_instance; // 생성 해제
	}

protected:
	SingleTon() = default;
	virtual ~SingleTon() = default;

	// 복사 및 이동 금지
	SingleTon(const SingleTon&) = delete;
	SingleTon& operator=(const SingleTon&) = delete;
	SingleTon(SingleTon&&) = delete;
	SingleTon& operator=(SingleTon&&) = delete;

private:
	static T* s_instance;
};

template <typename T>
T* SingleTon<T>::s_instance = nullptr;
