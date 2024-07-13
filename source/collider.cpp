#include "Collider.h"

Collider::Collider()
{}

Collider::~Collider()
{}

void Collider::move(Player &player)
{
	_xPos = player.getXpos();
}