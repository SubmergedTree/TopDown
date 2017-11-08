#include "AdditionalMath.h"

namespace vec
{
	sf::Vector2f normalize2f(sf::Vector2f const& vec)
	{
		float length = sqrtf(vec.x * vec.x + vec.y * vec.y);

		if (length == 0)
			return vec;
		else
		{
			return sf::Vector2f(vec.x / length, vec.y / length);
		}
	}
}