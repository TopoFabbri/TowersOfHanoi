#include "Disc.h"

Disc::Disc(int newNumber, float height)
{
	dropWav = LoadSound("aud/DropDisc.wav");
	grabWav = LoadSound("aud/GrabDisc.wav");
	selected = RED;
	base = WHITE;
	number = newNumber;
	grabbed = false;
	selectedRot = 3.f;

	std::string path = "res/Disc" + std::to_string(newNumber + 1) + ".png";

	sprite = LoadTexture(path.c_str());

	rec = { 0, 0, 6.f + static_cast<float>(number) * 2.5f, height };
}

void Disc::placeDisc(Vector2 pos)
{
	PlaySound(dropWav);
	setPos(pos);
}

void Disc::setPos(Vector2 pos)
{
	rec.x = pos.x - rec.width / 2.f;
	rec.y = pos.y - rec.height / 2.f;
}

void Disc::grab()
{
	grabbed = true;
	PlaySound(grabWav);
}

int Disc::getNumber()
{
	return number;
}

void Disc::setSelected()
{
	tint = selected;
	rot = selectedRot;
}

void Disc::quitSelected()
{
	tint = base;
	rot = 0;
}