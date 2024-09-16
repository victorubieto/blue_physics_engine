#pragma once

#include "particle.h"

// Book's author is called Ian -> Cyan -> Blue
namespace blue
{

	enum shotType {
		UNUSED,
		PISTOL,
		ARTILLERY,
		FIREBALL,
		LASER
	};

	// Ballistic represents any weapon that can shoot particles
	// For simplification, a bal listic will only be able to shoot one particle at a time
	class Ballistic {
	public:

		Particle* bullet = NULL;
		shotType etype;

		Ballistic();
	};

}