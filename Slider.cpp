#include <algorithm>
#include <string>
#include <stdio.h>

#include "Point.hpp"
#include "Slider.hpp"
#include "GameEngine.hpp"

Slider::Slider(float x, float y, float w, float h) :
	ImageButton("stage-select/slider.png", "stage-select/slider-blue.png", x, y),
	Bar("stage-select/bar.png", x, y, w, h),
	End1("stage-select/end.png", x, y + h / 2, 0, 0, 0.5, 0.5),
	End2("stage-select/end.png", x + w, y + h / 2, 0, 0, 0.5, 0.5) {
	Position.x += w;
	Position.y += h / 2;
	Anchor = Engine::Point(0.5, 0.5);
}
// TODO 4 (0/6): Finish the 6 functions below and ensure it can control both BGM and SFX volume.
//               The slider shouldn't be dragged outside the bar, and you should also keep the mouse-in / mouse-out effect.
void Slider::Draw() const {
	// TODO 4 (1/6): Draw all components.
    Bar.Draw();
    End1.Draw();
    End2.Draw();
    ImageButton::Draw();
}
void Slider::SetOnValueChangedCallback(std::function<void(float value)> onValueChangedCallback) {
	// TODO 4 (2/6): Set the function pointer. Can imitate ImageButton's 'SetOnClickCallback'.
	OnValueChangedCallback = onValueChangedCallback;
}
void Slider::SetValue(float value) {
	// TODO 4 (3/6): Call 'OnValueChangedCallback' when value changed. Can imitate ImageButton's 'OnClickCallback'.
	//               Also move the slider along the bar, to the corresponding position.
	this->value = value;
}
void Slider::OnMouseDown(int button, int mx, int my) {
	// TODO 4 (4/6): Set 'Down' to true if mouse is in the slider.
	if (mouseIn)
        Down = true;
}
void Slider::OnMouseUp(int button, int mx, int my) {
	// TODO 4 (5/6): Set 'Down' to false.
    Down = false;
}
void Slider::OnMouseMove(int mx, int my) {
	// TODO 4 (6/6): Clamp the coordinates and calculate the value. Call 'SetValue' when you're done.
	ImageButton::OnMouseMove(mx, my);
	if(Down) {
        if(mx < Bar.Position.x || mx > Bar.Position.x + Bar.Size.x)
            return;
        Position.x = mx;
        SetValue((mx-Bar.Position.x)/Bar.Size.x);
        if (OnValueChangedCallback)
            OnValueChangedCallback(value);
	}
}
