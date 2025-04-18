#pragma once

enum class KeyState {
    KEY_DOWN = 0,
    KEY_HOLD = 1,
    KEY_UP = 2,
    KEY_NONE = 3
};


class Input
{
    KeyState keyStates[256] ;  // 현재 키의 상태를 저장하는 배열
    bool prevKeyState[256]  ;      // 이전상태의 키 상태를 저장하는 배열

    void Update();
    void Start();
};

