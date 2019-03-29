
#include "Listener.hpp"

#include "Entity.hpp"

namespace example
{
	void Listener::BeginContact(b2Contact* contact) 
	{
		void * fixture_A = contact->GetFixtureA()->GetBody()->GetUserData();
		void * fixture_B = contact->GetFixtureB()->GetBody()->GetUserData();

		if ((fixture_A && fixture_B) && (fixture_A != fixture_B)) {
			Entity * entity_A = static_cast<Entity*>(fixture_A);
			Entity * entity_B = static_cast<Entity*>(fixture_B);

			if (entity_A) {
				entity_A->collision_enter();

			}

			if (entity_B) {
				entity_B->collision_enter();
			}
		}
	}

	void Listener::EndContact(b2Contact* contact) 
	{
		void * fixture_A = contact->GetFixtureA()->GetBody()->GetUserData();
		void * fixture_B = contact->GetFixtureB()->GetBody()->GetUserData();
		if ((fixture_A && fixture_B) && (fixture_A != fixture_B)) {
			Entity * entity_A = static_cast<Entity*>(fixture_A);
			Entity * entity_B = static_cast<Entity*>(fixture_B);

			if (entity_A) {
				entity_A->collision_exit();

			}

			if (entity_B) {
				entity_B->collision_exit();

			}
		}
	}
}