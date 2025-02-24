
#include "Sensor.hpp"
#include <iostream>

namespace example
{
	Sensor::Sensor(Scene * scene, float x, float y, float hx, float hy, std::string platform_name, float angle)
		:Rectangle(scene, x, y, hx, hy, angle, b2_staticBody)
	{
		platform = static_cast<Platform*>(scene->get_entity_by_name(platform_name));
		bodies["rectangle"]->GetFixtureList()[0].SetSensor(true);
		bodies["rectangle"]->SetUserData(this);

		offset = platform->get_position() - bodies["rectangle"]->GetPosition();

		delay = 2.f;
		current_time = 0;
		collision_detected = false;

		set_color(sf::Color::White);
	}

	void Sensor::update(float deltaTime)
	{
		if (collision_detected && !platform->get_move_to_target())
		{
			current_time += deltaTime;
			if (current_time >= delay)
			{
				platform->set_move_to_target(true);
			}
		}
		else if (!collision_detected && platform->get_move_to_target())
		{
			current_time += deltaTime;
			if (current_time >= delay)
			{
				platform->set_move_to_target(false);
			}
		}

		if (!platform->is_stopped())
		{
			bodies["rectangle"]->SetTransform(platform->get_position() - offset, angle_in_rad);
		}
	}

	void Sensor::collision_enter(Entity* e)
	{
		if (!collision_detected)
		{
			current_time = 0;
			collision_detected = true;
		}

		entities_detected.insert(e->get_tag());
	}

	void Sensor::collision_exit(Entity* e)
	{
		entities_detected.erase(e->get_tag());

		if (entities_detected.size() == 0)
		{
			current_time = 0;
			collision_detected = false;
		}
	}
}
