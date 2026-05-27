#include"enemy.h"
#include <stdio.h>

Enemy::Enemy() {

}

void Enemy::Initialize() {

    state_ = &Enemy::Approach;
}

void Enemy::Update() {

    (this->*state_)();
}

void Enemy::Draw() {

}

void Enemy::Approach() {

    printf("敵が接近しています\n");

    state_ = &Enemy::Shot;
}

void Enemy::Shot() {

    printf("敵が射撃しました\n");

    state_ = &Enemy::Leave;
}

void Enemy::Leave() {

    printf("敵が離脱しています\n");

    state_ = &Enemy::Approach;
}