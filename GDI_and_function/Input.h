#pragma once
#include "SingleTone.h"

enum class KeyState {
    KEY_DOWN = 0,
    KEY_HOLD = 1,
    KEY_UP = 2,
    KEY_NONE = 3
};


class Input : public SingleTon<Input>
{
    friend class SingleTon<Input>;
private:
    Input() = default;			// 다른 생성을 통한 생성자 호출은 금지
    ~Input() = default;

    KeyState keyStates[256] ;  // 현재 키의 상태를 저장하는 배열
    bool prevKeyState[256]  ;      // 이전상태의 키 상태를 저장하는 배열

public:
    void Update();
    void Start();
};

