#pragma once

#include "Collider.h"

#include <glm/vec3.hpp>

namespace Physics {

	class PhysicsObjects;

	class SphereCollider : public Collider
	{
	public:
		SphereCollider();
		SphereCollider(float radius);
		virtual ~SphereCollider();

		// Getters
		const glm::vec3 &GetPosition() const { return m_position; }
		float GetRadius() const { return m_radius; }
		// Setters
		void SetPosition(const glm::vec3 & position) { m_position = position; }
		void SetRadius(float radius) { m_radius = radius; }

		bool Intersects(Collider* other) const;

		virtual void Transform(PhysicsObjects *obj);

	protected:
		glm::vec3 m_position;
		float m_radius;
	private:

	};


}