#pragma once

#include <vector>
#include <glm/vec3.hpp>

namespace Physics 
{
	class PhysicsObjects;

	class PhysicsScene
	{
	public:
		struct CollisionInfo
		{
			PhysicsObjects* objA;
			PhysicsObjects* objB;

			// More data will be added in here for the collision resolution
		};

		PhysicsScene();
		virtual ~PhysicsScene();

		void Update(float deltaTime);

		void ApplyGlobalForce(const glm::vec3 & force);

		// Attach a Physics Object to the scene
		void AttachObjects(PhysicsObjects *obj);
		// Remove a Physics Object to the scene
		void RemoveObjects(PhysicsObjects *obj);

		const std::vector<PhysicsObjects*> & GetObjects() const { return m_objects; }

		bool isObjectColliding(PhysicsObjects* obj);

	protected:
		std::vector<PhysicsObjects *> m_objects;
		glm::vec3 m_globalForce;

		void DetectCollisions();
		std::vector<CollisionInfo> m_collisions;

	private:

	};

}