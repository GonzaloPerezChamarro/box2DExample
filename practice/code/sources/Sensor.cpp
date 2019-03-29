
#include "Sensor.hpp"
#include <iostream>

namespace example
{
	Sensor::Sensor(Scene * scene, float x, float y, float hx, float hy, std::string platform_name, float angle)
		:Rectangle(scene, x, y,hx,hy,angle,b2_staticBody)
	{
		platform = static_cast<Platform*>(scene->get_entity_by_name(platform_name));
		bodies["rectangle"]->GetFixtureList()[0].SetSensor(true);
		bodies["rectangle"]->SetUserData(this);

		offset = platform->get_position() - bodies["rectangle"]->GetPosition();

		delay = 2.f;

		set_color(sf::Color::White);
	}

	void Sensor::update(float deltaTime)
	{
		current_time += deltaTime;
		if (current_time >= delay)
			platform->set_have_to_move(next_mov);

		if (!platform->is_stopped())
			bodies["rectangle"]->SetTransform(platform->get_position() - offset, angle_in_rad);
	}

	void Sensor::collision_enter()
	{
		current_time = 0;
		next_mov = true;
	}

	void Sensor::collision_exit()
	{
		current_time = 0;
		next_mov = false;

	}
}