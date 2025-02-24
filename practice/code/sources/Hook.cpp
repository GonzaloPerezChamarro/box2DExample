

#include "Hook.hpp"

namespace example
{
	Hook::Hook(Scene * scene, float x, float y)
		:Entity(scene)
	{
		float scaled_pixels = scene->scale_pixels_to_sfml();
		b2BodyDef body;
		b2PolygonShape shape;
		b2FixtureDef fixture;

		//BODY
		{
			body.type = b2_dynamicBody;
			position.x = x * scaled_pixels;
			position.y = y * scaled_pixels;
			body.position.Set(position.x, position.y);

			bodies["base"] = scene->get_world().CreateBody(&body);

			shape.SetAsBox(80.f *scaled_pixels, 3.f *scaled_pixels);
			fixture.shape = &shape;
			fixture.density = 20;
			fixture.friction = 0.8f;
			fixture.restitution = 0.f;
			bodies["base"]->CreateFixture(&fixture);
			main_body = bodies["base"];
		}

		//BASES
		{
			body.type = b2_staticBody;
			body.position.Set(position.x, position.y - 1.f);
			bodies["base_bottom"] = scene->get_world().CreateBody(&body);
			shape.SetAsBox(230 * scaled_pixels, 2.f * scaled_pixels);

			fixture.shape = &shape;
			fixture.density = 100;
			fixture.friction = 1.f;
			fixture.restitution = 0.f;
			bodies["base_bottom"]->CreateFixture(&fixture);
		}

		{
			body.type = b2_staticBody;
			body.position.Set(position.x, position.y + .1f);
			bodies["base_top"] = scene->get_world().CreateBody(&body);
			shape.SetAsBox(230 * scaled_pixels, 2.f * scaled_pixels);

			fixture.shape = &shape;
			fixture.density = 100;
			fixture.friction = 1.f;
			fixture.restitution = 0.f;
			bodies["base_top"]->CreateFixture(&fixture);
		}

		//TOPS
		{
			body.type = b2_staticBody;
			body.position.Set(position.x - 20, position.y);
			bodies["top_left"] = scene->get_world().CreateBody(&body);
			shape.SetAsBox(2 * scaled_pixels, 7.f * scaled_pixels);

			fixture.shape = &shape;
			fixture.density = 100;
			fixture.friction = 1.f;
			fixture.restitution = 0.f;
			bodies["top_left"]->CreateFixture(&fixture);
		}

		{
			body.type = b2_staticBody;
			body.position.Set(position.x + 20, position.y);
			bodies["top_right"] = scene->get_world().CreateBody(&body);
			shape.SetAsBox(2 * scaled_pixels, 7.f * scaled_pixels);

			fixture.shape = &shape;
			fixture.density = 100;
			fixture.friction = 1.f;
			fixture.restitution = 0.f;
			bodies["top_right"]->CreateFixture(&fixture);
		}

		//HOOK
		{
			body.type = b2_dynamicBody;
			body.position.Set(position.x, position.y - 10);

			bodies["hook"] = scene->get_world().CreateBody(&body);
			bodies["hook"]->SetUserData(this);

			shape.SetAsBox(15.f *scaled_pixels, 5.f *scaled_pixels);
			fixture.shape = &shape;
			fixture.density = 200.f;
			fixture.friction = 1.f;
			fixture.restitution = 0.f;

			bodies["hook"]->CreateFixture(&fixture);
		}

		// PRISM JOINT
		{
			b2PrismaticJointDef joint;
			joint.Initialize(bodies["base"], bodies["hook"], position, b2Vec2(0, -1));
			joint.lowerTranslation = -5.f;
			joint.upperTranslation = 8.5f;
			joint.enableLimit = true;
			joint.maxMotorForce = 20000;
			joint.enableMotor = true;


			joints["joint"] = scene->get_world().CreateJoint(&joint);
			prim_joint = dynamic_cast<b2PrismaticJoint*>(joints["joint"]);
		}
		
		//HOOK LEFT
		{
			body.type = b2_dynamicBody;
			body.position.Set(position.x, position.y - 12);

			bodies["hook_left"] = scene->get_world().CreateBody(&body);
			bodies["hook_left"]->SetUserData(this);

			shape.SetAsBox(14.f *scaled_pixels, 2.f *scaled_pixels, b2Vec2(-2.f, 0.f), 45 * 3.1416 / 180);
			fixture.shape = &shape;
			fixture.density = 20.f;
			fixture.friction = 1.f;
			fixture.restitution = 0.f;

			bodies["hook_left"]->CreateFixture(&fixture);


			shape.SetAsBox(14.f *scaled_pixels, 2.f *scaled_pixels, b2Vec2(-2.f, -3.f), -45 * 3.1416 / 180);
			fixture.shape = &shape;
			fixture.density = 3.f;
			fixture.friction = 1.f;
			fixture.restitution = 0.f;

			bodies["hook_left"]->CreateFixture(&fixture);
		}

		//HOOK right
		{
			body.type = b2_dynamicBody;
			body.position.Set(position.x, position.y - 12);
			body.angle = 0.f;

			bodies["hook_right"] = scene->get_world().CreateBody(&body);
			bodies["hook_right"]->SetUserData(this);

			shape.SetAsBox(14.f *scaled_pixels, 2.f *scaled_pixels, b2Vec2(2.f, 0.f), -45 * 3.1416 / 180);
			fixture.shape = &shape;
			fixture.density = 20.f;
			fixture.friction = 1.f;
			fixture.restitution = 0.f;

			bodies["hook_right"]->CreateFixture(&fixture);


			shape.SetAsBox(14.f *scaled_pixels, 2.f *scaled_pixels, b2Vec2(2.f, -3.f), 45 * 3.1416 / 180);
			fixture.shape = &shape;
			fixture.density = 3.f;
			fixture.friction = 1.f;
			fixture.restitution = 0.f;

			bodies["hook_right"]->CreateFixture(&fixture);
		}

		//REV JOINTS
		{
			b2RevoluteJointDef joint;
			joint.Initialize(bodies["hook"], bodies["hook_left"],b2Vec2(bodies["hook"]->GetPosition().x, bodies["hook"]->GetPosition().y));
			joint.collideConnected = false;
			joint.referenceAngle = 0.f;
			joint.lowerAngle = -40.f * 3.1416f / 180;
			joint.upperAngle = 0.f;
			joint.enableMotor = true;
			joint.enableLimit = true;
			joint.maxMotorTorque = 7000.f;
			joints["joint_left"] = scene->get_world().CreateJoint(&joint);

			joint_left = dynamic_cast<b2RevoluteJoint*>( joints["joint_left"]);
			
			joint.Initialize(bodies["hook"], bodies["hook_right"], b2Vec2(bodies["hook"]->GetPosition().x, bodies["hook"]->GetPosition().y));
			joint.collideConnected = false;
			joint.referenceAngle = 0.f;
			joint.upperAngle = 40.f * 3.1416f / 180;
			joint.lowerAngle = 0.f;
			joint.enableMotor = true;
			joint.maxMotorTorque = 10000.f;
			joints["joint_right"] = scene->get_world().CreateJoint(&joint);

			joint_right = dynamic_cast<b2RevoluteJoint*>(joints["joint_right"]);
		}
		
		up = true;
		set_color(sf::Color(210, 88, 10));
	}

	void Hook::update(float deltaTime)
	{
		// Vertical movement 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			prim_joint->SetMotorSpeed(-300);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			prim_joint->SetMotorSpeed(50);
		}

		// Horizontal movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			main_body->ApplyLinearImpulse(b2Vec2(-400, 0), b2Vec2(0, position.y), true);
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			main_body->ApplyLinearImpulse(b2Vec2(400, 0), b2Vec2(0, position.y), true);
		}

		// Hook
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			joint_left->SetMotorSpeed(10000);
			joint_right->SetMotorSpeed(-10000);
		}
		else
		{
			joint_left->SetMotorSpeed(-7000);
			joint_right->SetMotorSpeed(7000);
		}
	}
}
