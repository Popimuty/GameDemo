#include "pch.h"
#include "Input.h"



void Input::Update() {
    for (int vk = 0; vk < 256; ++vk)
    {
        bool nowPressed = (GetAsyncKeyState(vk) & 0x8000) != 0;

        if (nowPressed)
        {
            if (!prevKeyState[vk])
                keyStates[vk] = KeyState::KEY_DOWN;
            else
                keyStates[vk] = KeyState::KEY_HOLD;
        }
        else
        {
            if (prevKeyState[vk])
                keyStates[vk] = KeyState::KEY_UP;
            else
                keyStates[vk] = KeyState::KEY_NONE;
        }

        prevKeyState[vk] = nowPressed;
    }
}


void Input::Start() {
    KeyState keyStates[256] = { KeyState::KEY_NONE };  // 현재 키의 상태를 저장하는 배열
    bool prevKeyState[256] = { false };                // 이전상태의 키 상태를 저장하는 배열
}
