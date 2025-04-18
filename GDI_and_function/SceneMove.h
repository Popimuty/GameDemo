#pragma once
#include"Scene.h"
#include "SingleTone.h"

class Scene;
class SceneMove : public SingleTon<SceneMove>
{
	//friend class Singleton<SceneManager>; // 이 클래스만 생성자 접근 허용
private:
	SceneMove() = default;			// 다른 생성을 통한 생성자 호출은 금지
	~SceneMove() = default;

	//std::vector : C++ 표준 템플릿 라이브러리(STL)의 동적 배열(가변 크기 배열)
	std::vector<Scene*> m_vScenes; // 씬 리스트

	Scene* m_pCurrentScene = nullptr; // 현재 씬
	Scene* m_pNextScene = nullptr; // 다음 씬
public:
	void Init();
	void Update();
	void Render();
	void ChangeScene(size_t index);
	Scene* GetCurrentScene() { return m_pCurrentScene; }

	//push_back  : push_back의 경우 Vector의 마지막에 새로운 원소를 추가하기 위해 
	//			   임시 객체를 하나 만들어서 거기에 값을 복사 후, Vector에 삽입하는 과정을 거친다. 
	//             삽입이 끝나면 당연히 임시 객체 또한 파괴된다.
	//emplace_back  : emplace_back은 가변인자 템플릿을 사용해서 삽입하려는 자료형에 따라, 
	//				  함수 내에서 삽입을 위한 객체를 자체적으로 생성할 수 있다. 
	//                즉, 불필요한 임시 객체를 만들 필요가 없다.
	template<typename T>
	void CreateScene()
	{
		Scene* pScene = new T();
		m_vScenes.push_back(pScene);
	}
};

