#include "pch.h"
#include "Scene.h"
#include "Draw.h"
#include "WinCreateLoop.h"
void Scene::Clear(){
	//auto -> 타입을 컴파일러가 자동으로 추론
	for (auto& object : m_Objects)
	{
		delete object;
	}
	m_Objects.clear();
	for (auto& object : m_DeletePendingObjects)
	{
		delete object;
	}
	m_DeletePendingObjects.clear(); // 루프가 끝난 다음에 m_컨테이너에 있는 물체들을 나중에 삭제
}
void Scene::Update() {
	for (auto& object : m_Objects)
	{
		//object->Update();
	}
}
void Scene::Render() {
	for (auto& object : m_Objects)
	{
		//object->Render();
	}
}

void Scene::Scene_init() {
	
}