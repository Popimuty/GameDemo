#include "pch.h"
#include "EndScene.h"
#include "SceneMove.h"
#include "Input.h"
#include "Draw.h"
#include "player.h"
#include "string.h"
void EndScene::Scene_init() {
	storage_back = new Gdiplus::Bitmap(L"../image/end.png");
	width_back = storage_back->GetWidth();
	height_back = storage_back->GetHeight();
	tmp.append("Killed Enemy " + std::to_string(player::count));
}

void EndScene::Update() {
	if (KeyState::KEY_UP == Input::Get().check(32)) {
		SceneMove::Get().ChangeScene(0);

	}
}
//void Draw::Write_text(std::wstring tmp, int len_size, int loc_x, int loc_y)

void EndScene::Render() {
	Draw::Get().Draw_Image(storage_back, width_back, height_back, 0, 0, 0, 0);
	Draw::Get().Write_text(tmp,15,400,600);
}

