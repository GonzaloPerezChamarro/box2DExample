

#include "Entity.hpp"
#include "Scene.hpp"



namespace example
{
	Entity::Entity(Scene* scene) : scene(scene)
	{
		enabled = true;
	}

	Entity::~Entity()
	{
		for (auto & bodie : bodies) 
		{
			scene->get_world().DestroyBody(bodie.second);
		}
		for (auto & joint : joints) 
		{
			scene->get_world().DestroyJoint(joint.second);
		}
		delete scene;
	}
	void Entity::render(sf::RenderWindow & renderer)
	{
		if (!enabled) return;

		float scale = scene->get_scale();

		for (auto body_begin = bodies.begin(), body_end = bodies.end(); body_begin != body_end; ++body_begin){
			b2Transform transform = body_begin->second->GetTransform();

			for (auto fixture = body_begin->second->GetFixtureList(); fixture != nullptr; fixture = fixture->GetNext()) {
				b2Shape::Type type = fixture->GetShape()->GetType();


				if (type == b2Shape::e_edge)
				{
					b2EdgeShape * edge = static_cast<b2EdgeShape *>(fixture->GetShape());

					b2Vec2 point_a = b2Mul(transform, edge->m_vertex1);
					b2Vec2 point_b = b2Mul(transform, edge->m_vertex2);

					sf::Vertex line[] = {
						sf::Vertex(convert_to_sfml_pos(point_a, (float)scene->get_height()), color),
						sf::Vertex(convert_to_sfml_pos(point_b, (float)scene->get_height()), color)
					};
					renderer.draw(line, 2, sf::Lines);
				}
				else if (type == b2Shape::e_polygon && !fixture->IsSensor())
				{
					//&& !fixture->IsSensor()
					b2PolygonShape * polygon = static_cast<b2PolygonShape *>(fixture->GetShape());
					sf::ConvexShape shape;

					int vertex_count = polygon->GetVertexCount();
					shape.setPointCount(vertex_count);
					shape.setFillColor(color);
					
					for (int i = 0; i < vertex_count; ++i)
					{
						b2Vec2 mul = b2Mul(transform, polygon->GetVertex(i));
						shape.setPoint(i, convert_to_sfml_pos(mul, (float)scene->get_height()));
					}
					renderer.draw(shape);
				}
				else if (type == b2Shape::e_circle) 
				{
					b2CircleShape * circle = static_cast<b2CircleShape *>(fixture->GetShape());
					b2Vec2 center = circle->m_p;
					float radius = circle->m_radius * scale;
					sf::CircleShape circle_Shape;
					b2Vec2 mul = b2Mul(transform, center);
					circle_Shape.setPosition(convert_to_sfml_pos(mul, (float)scene->get_height()) - sf::Vector2f(radius, radius));
					circle_Shape.setFillColor(color);
					circle_Shape.setRadius(radius);
					renderer.draw(circle_Shape);
				}
			}
		}

		for (auto joint_begin = joints.begin(), joint_end = joints.end(); joint_begin != joint_end; ++joint_begin)
		{
			b2Vec2 anchor_A = joint_begin->second->GetBodyA()->GetPosition();
			b2Vec2 anchor_B = joint_begin->second->GetBodyB()->GetPosition();

			sf::Vertex line[] = {
				sf::Vertex(convert_to_sfml_pos(anchor_A, (float)scene->get_height()), sf::Color::Blue),
				sf::Vertex(convert_to_sfml_pos(anchor_B, (float)scene->get_height()), sf::Color::Blue)
			};
			renderer.draw(line, 2, sf::Lines);

		}
	}
}