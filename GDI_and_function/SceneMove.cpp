#include "pch.h"
#include "SceneMove.h"



void SceneMove::Init() {
}
void SceneMove::Render() {

}

//포인터 상태표  upate 중           update 끝
//m_p_NowScene     있음         끝난 포인터 있음
//m_p_NextScene    null              있음
void SceneMove::Update() {
	//if(포인터) : 포인터가 있으면 참 -> 내부 구문 실행, nullptr이면 거짓 -> 다음구문으로
	if (m_p_NextScene) {
		if (m_p_NowScene)
			m_p_NowScene->Exit();

		m_p_NowScene = m_p_NextScene;
		m_p_NowScene = nullptr;

		m_p_NowScene->Scene_init();
	}

	if (m_p_NowScene)
		m_p_NowScene->Update();
}


void SceneMove::ChangeScene(size_t index) {
	m_p_NextScene = m_Scenes_list[index];
}



