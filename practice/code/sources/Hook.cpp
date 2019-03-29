

#include "Hook.hpp"

namespace example
{
	Hook::Hook(Scene * scene, float x, float y)
		:Entity(scene)
	{

		float scaled_pixels = scene->scale_pixels_to_sfml();

		b2BodyDef body;
		body.type = b2_dynamicBody;
		position.x = x * scaled_pixels;
		position.y = y * scaled_pixels;
		body.position.Set(position.x, position.y);

		bodies["base"] = scene->get_world().CreateBody(&body);
		bodies["base"]->SetUserData(this);

		b2PolygonShape shape;
		b2FixtureDef fixture;

		b2Vec2 points [] = {b2Vec2(0.f,0.f), b2Vec2(3.f,0.f),b2Vec2(-3.f,-5.f),b2Vec2(3.f,-10.f),b2Vec2(0.f,-10.f),b2Vec2(-5.f,-5.f) };
		shape.Set(points, 6);
		fixture.shape = &shape;
		fixture.density = 200;
		fixture.friction = 1.f;
		fixture.restitution = 0.f;

		bodies["base"]->CreateFixture(&fixture);


		set_color(sf::Color::Yellow);
	}
	void Hook::update(float deltaTime)
	{
	}
}