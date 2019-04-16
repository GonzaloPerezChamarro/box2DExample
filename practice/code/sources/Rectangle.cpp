#include "Rectangle.hpp"

namespace example
{
	Rectangle::Rectangle(Scene * scene,float x, float y, float hx, float hy, float angle, b2BodyType type)
		:Entity(scene)
	{
		float pixels_scaled = scene->scale_pixels_to_sfml();

		b2BodyDef body;
		body.type = type;

		body.fixedRotation = false;
		body.angle = angle_in_rad = angle * 3.14159 / 180 * 1;
		
		position.x = x * pixels_scaled;
		position.y = y * pixels_scaled;
		body.position.Set(position.x, position.y);
		
		

		bodies["rectangle"] = scene->get_world().CreateBody(&body);

		b2PolygonShape shape;
		b2FixtureDef fixture;
		shape.SetAsBox(hx * pixels_scaled, hy * pixels_scaled);
		fixture.shape = &shape;
		fixture.friction = 0.2f;
		fixture.restitution = 0.f;


		bodies["rectangle"]->CreateFixture(&fixture);

		set_color(sf::Color::Cyan);

	}

	void Rectangle::update(float deltaTime)
	{
		//nothing
	}
	void Rectangle::collision_enter(Entity* e)
	{
		//nothing
	}
	void Rectangle::collision_exit(Entity*e)
	{
		//nothing
	}
}