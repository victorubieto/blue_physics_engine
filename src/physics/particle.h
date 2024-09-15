#pragma once

#include "core.h"

// Book's author is called Ian -> Cyan -> Blue
namespace blue
{
	// A particle is the simplest object that can be simulated in the physics system
	class Particle {
	public:

		Vector3 position;		// linear position of the particle in world space
		Vector3 velocity;		// linear velocity of the particle in world space
		Vector3 acceleration;	// this value can be used to set the acceleration of the gravity or any other constant acceleration

		real damping;			// required to remove energy added through numerical instability in the integrator
		real inverseMass;		// simpler to integrate and because in real-time simulation it is more useful to have objects with infinite mass than zero mass (unstable)

		// Integrates the particle forward in time by given amount. Uses the Newton-Euler integration method, which is a linear approximation of the correct integral (inaccurate in some cases)
		void integrate(real duration);
	};
}