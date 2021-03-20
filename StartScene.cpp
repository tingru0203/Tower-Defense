#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>

#include "AudioHelper.hpp"
#include "GameEngine.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
#include "StageSelectScene.hpp"
#include "Point.hpp"
#include "Resources.hpp"
#include "Slider.hpp"
#include "StartScene.hpp"

void StartScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("start/dirt.png", "start/floor.png", halfW - 200, halfH - 50, 400, 100, 0, 0);
    btn->SetOnClickCallback(std::bind(&StartScene::StageSelectOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Start", "pirulen.ttf", 48, halfW, halfH, 0, 0, 0, 255, 0.5, 0.5));
}
void StartScene::Terminate() {
	IScene::Terminate();
}
void StartScene::StageSelectOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}
