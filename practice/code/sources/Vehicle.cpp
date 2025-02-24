
#include "Vehicle.hpp"

namespace example
{
	Vehicle::Vehicle(Scene * scene, float x, float y)
		:Entity(scene)
	{
		right = left = false;

		const float scaled_pixels = scene->scale_pixels_to_sfml();

		//Body
		{
			b2BodyDef body;
			body.type = b2_dynamicBody;
			position.x = x * scaled_pixels;
			position.y = y * scaled_pixels;
			body.position.Set(position.x, position.y);

			bodies["vehicle"] = scene->get_world().CreateBody(&body);
			bodies["vehicle"]->SetUserData(this);

			b2PolygonShape shape;
			b2FixtureDef fixture;

			shape.SetAsBox(70.f * scaled_pixels, 12.f * scaled_pixels);
			fixture.shape = &shape;
			fixture.density = 20.f;
			fixture.friction = 1.f;
			fixture.restitution = 0.f;

			bodies["vehicle"]->CreateFixture(&fixture);

			shape.SetAsBox(38.f * scaled_pixels, 5.f * scaled_pixels, b2Vec2(-55.f * scaled_pixels, 25.f * scaled_pixels), -50 * 0.0174533f);
			bodies["vehicle"]->CreateFixture(&fixture);

			shape.SetAsBox(38.f * scaled_pixels, 5.f * scaled_pixels, b2Vec2(55.f * scaled_pixels, 25.f * scaled_pixels), 50 * 0.0174533f);
			bodies["vehicle"]->CreateFixture(&fixture);
		}

		//Wheel 1
		{
			b2BodyDef wheel1_body;
			wheel1_body.type = b2_dynamicBody;
			wheel1_pos.x = 100.f * scaled_pixels;
			wheel1_pos.y = 300.f * scaled_pixels;
			wheel1_body.position.Set(wheel1_pos.x, wheel1_pos.y);
			bodies["wheel1"] = scene->get_world().CreateBody(&wheel1_body);
			bodies["wheel1"]->SetUserData(this);

			b2CircleShape wheel1_shape;
			b2FixtureDef wheel1_fixture;

			wheel1_shape.m_radius = 20.f * scaled_pixels;
			wheel1_fixture.shape = &wheel1_shape;
			wheel1_fixture.density = 5.f;
			wheel1_fixture.friction = 0.9f;
			wheel1_fixture.restitution = 0.f;

			bodies["wheel1"]->CreateFixture(&wheel1_fixture);

			//Joint Wheel 1
			b2RevoluteJointDef wheel1_joint;
			wheel1_joint.bodyA = bodies["vehicle"];
			wheel1_joint.bodyB = bodies["wheel1"];
			wheel1_joint.collideConnected = false;
			wheel1_joint.referenceAngle = 0;
			wheel1_joint.localAnchorA.Set(-3.7f, -3.5f);
			wheel1_joint.localAnchorB.Set(0, 0);
			wheel1_joint.enableMotor = true;
			wheel1_joint.maxMotorTorque = 3000;
			joints["wheel1"] = scene->get_world().CreateJoint(&wheel1_joint);

			wheel1 = dynamic_cast<b2RevoluteJoint*>(joints["wheel1"]);
		}

		//Wheel 2
		{
			b2BodyDef wheel2_body;
			wheel2_body.type = b2_dynamicBody;
			wheel2_pos.x = 100.f * scaled_pixels;
			wheel2_pos.y = 300.f * scaled_pixels;
			wheel2_body.position.Set(wheel2_pos.x, wheel2_pos.y);
			bodies["wheel2"] = scene->get_world().CreateBody(&wheel2_body);
			bodies["wheel2"]->SetUserData(this);

			b2CircleShape wheel2_shape;
			b2FixtureDef wheel2_fixture;

			wheel2_shape.m_radius = 20.f * scaled_pixels;
			wheel2_fixture.shape = &wheel2_shape;
			wheel2_fixture.density = 5.f;
			wheel2_fixture.friction = 0.8f;
			wheel2_fixture.restitution = 0.f;

			bodies["wheel2"]->CreateFixture(&wheel2_fixture);

			//Joint Wheel 2
			b2RevoluteJointDef wheel2_joint;
			wheel2_joint.bodyA = bodies["vehicle"];
			wheel2_joint.bodyB = bodies["wheel2"];
			wheel2_joint.collideConnected = false;
			wheel2_joint.referenceAngle = 0;
			wheel2_joint.localAnchorA.Set(3.7f, -3.5f);
			wheel2_joint.localAnchorB.Set(0, 0);
			wheel2_joint.enableMotor = true;
			wheel2_joint.maxMotorTorque = 3000;
			joints["wheel2"] = scene->get_world().CreateJoint(&wheel2_joint);

			wheel2 = dynamic_cast<b2RevoluteJoint*>(joints["wheel2"]);
		}

		set_color(sf::Color::Blue);
	}

	void Vehicle::update(float deltaTime)
	{
		input();

		if (left)
		{
			wheel1->SetMotorSpeed(motor_speed);
			wheel2->SetMotorSpeed(motor_speed);
		}
		else if (right)
		{
			wheel1->SetMotorSpeed(-motor_speed);
			wheel2->SetMotorSpeed(-motor_speed);
		}
		else
		{
			wheel1->SetMotorSpeed(0);
			wheel2->SetMotorSpeed(0);
		}
	}

	void Vehicle::reset()
	{
		float scaled_pixels = scene->scale_pixels_to_sfml();

		bodies["vehicle"]->SetTransform(position, 0.f);
		bodies["vehicle"]->SetAngularVelocity(0.f);
		bodies["vehicle"]->SetLinearVelocity(b2Vec2(0.f, 0.f));
		bodies["wheel1"]->SetTransform(b2Vec2(100.f * scaled_pixels, 300.f * scaled_pixels), 0.f);
		bodies["wheel2"]->SetTransform(b2Vec2(100.f * scaled_pixels, 300.f * scaled_pixels), 0.f);
		wheel1->SetMotorSpeed(0);
		wheel2->SetMotorSpeed(0);
	}

	void Vehicle::collision_enter(Entity* e)
	{
		//nothing
	}

	void Vehicle::collision_exit(Entity* e)
	{
		//nothing
	}

	void Vehicle::input()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
		{
			right = false;
			left = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			right = true;
			left = false;
		}
		else
		{
			right = false;
			left = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			scene->set_have_to_reset(true);
		}
	}
}
