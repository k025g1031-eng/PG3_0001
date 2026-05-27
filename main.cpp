#include <stdio.h>

class Enemy {
public:

    // メンバ関数ポインタ
    typedef void (Enemy::* State)();

    Enemy() {

        state_ = &Enemy::Approach;
    }

    void Initialize() {

        state_ = &Enemy::Approach;
    }

    void Update() {

        (this->*state_)();
    }

    void Draw() {

    }

private:

    // 現在の状態
    State state_;

    // 接近
    void Approach() {

        printf("敵が接近しています\n");

        state_ = &Enemy::Shot;
    }

    // 射撃
    void Shot() {

        printf("敵が射撃しました\n");

        state_ = &Enemy::Leave;
    }

    // 離脱
    void Leave() {

        printf("敵が離脱しています\n");

        state_ = &Enemy::Approach;
    }
};

int main() {

    Enemy enemy;

    enemy.Initialize();

    for (int i = 0; i < 6; i++) {

        enemy.Update();

        enemy.Draw();
    }

    return 0;
}