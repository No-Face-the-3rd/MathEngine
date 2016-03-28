#include "Rigidbody.h"


Rigidbody::Rigidbody() : m(1.0f), d(0.0f), t(0.0f), aVel(0.0f), aAcc(0.0f), vel({ 0.0f,0.0f }), acc({ 0.0f,0.0f }), f({ 0.0f,0.0f }), j({ 0.0f,0.0f })
{

}

void Rigidbody::addForce(const meow::vec2 &a)
{
	f += a;
}
void Rigidbody::addTorque(const float &a)
{
	t += a;
}
void Rigidbody::integrate(Transform *a, const float &dt)
{
	j = f / m - acc;
	acc = acc + j * dt;
	vel = vel + acc * dt;
	a->setPosition(a->getPosition() + vel * dt);

	vel = vel - vel * drag * dt;
	f = { 0.0f, 0.0f };

	aAcc = t / m;
	aVel += aAcc * dt;
	a->setAngle(a->getAngle() + aVel * dt);
	t = 0.0f;
}