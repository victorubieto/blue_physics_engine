#include <assert.h>
#include "particle.h"

using namespace blue;

void Particle::integrate(real duration)
{
	assert(duration > 0.0);

	// Update linear position
	this->position.addScaledVector(this->velocity, duration);

	// Work out the acceleration from the force
	Vector3 resultingAcc = this->acceleration;
	//resultingAcc.addScaledVector(this->forceAccum, this->inverseMass);	// TODO

	// Update linear velocity from the acceleration
	this->velocity.addScaledVector(resultingAcc, duration);

	// Impose drag.
	this->velocity *= real_pow(this->damping, duration);
}
